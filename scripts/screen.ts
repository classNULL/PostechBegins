module StartScreen {
    export function show() { startarea.style.display = ""; }
    export function hide() { startarea.style.cssText += "display: none !important"; }

    export function reflectResumability() {
        localforage.getItem(gameSaveVersion)
            .then((value: GameStatus) => {
                if (!value) {
                    gameResumeButton.classList.add("disabled");
                    gameResumeButton.onclick = null;
                    return;
                }

                gameResumeButton.classList.remove("disabled");
                gameCenter = new Module.GameCenter(value.characterProperty, value.position);
                gameResumeButton.onclick = () => { 
                    StartScreen.hide();
                    ComicScreen.show();
                    ComicScreen.play()
                        .then(() => {
                            ComicScreen.hide();
                            GameScreen.show();
                            var monthday = Module.MonthDay.fromIndex(gameCenter.currentPosition);
                            reflectGender(gameCenter.character.sexuality);
                            reflectMonth(monthday.month);
                            reflectMonthEvent(monthday.month);
                            reflectMaxStatus(gameCenter.character);
                            reflectStatus(gameCenter.character);
                            reflectDate(gameCenter.currentPosition);
                            monthday.delete();
                        });
                };
            });
    }
    export function startGame() {
        StartScreen.hide();
        CharacterSelectionScreen.show();
    }
    export function resumeGame() { }
    export function introduce() {
        StartScreen.hide();
        IntroScreen.show();
    }
}

module CharacterSelectionScreen {
    export function show() { 
        selectorPanel.style.display = "";
        document.documentElement.style.backgroundImage = 'url("UI/게임 설명화면/선택화면배경.jpg")';
    }
    export function hide() { selectorPanel.style.cssText += "display: none !important"; }

    export function select(sexuality: Module.Sexuality) {
        CharacterSelectionScreen.hide();
        ComicScreen.show();
        ComicScreen.play()
            .then(() => {
                ComicScreen.hide();
                GameScreen.show();
                createGameCenter(sexuality);
                reflectDate(gameCenter.currentPosition);
            });
    }
}

module ComicScreen {
    export function show() {
        comicPanel.style.display = "";
        document.documentElement.style.backgroundImage = 'url("UI/로딩화면/배경.png")';
    }
    export function hide() { comicPanel.style.cssText += "display: none !important"; }
    export function play() { 
        var parent = comicPanel;
        var sequence = Promise.resolve<void>();
        for (var i = 2; i <= 6; i++) {
            ((index: number) => {
                sequence = sequence.then(() => timeoutPromise(2000)).then(() => {
                    var child = <HTMLDivElement>DOMLiner.element("div", { style: 'background-image: url("UI/로딩화면/' + index + '.png")' });
                    parent.appendChild(child);
                    parent = child;
                });
            })(i);
        }
        return sequence
            .then(() => timeoutPromise(2000))
            .then(() => {
                parent.appendChild(DOMLiner.element("div", { class: "fade-in", style: 'background-image: url("UI/로딩화면/logo.jpg")' }));
            })
            .then(() => timeoutPromise(4000));
    }
    function clear() {
        while (comicPanel.firstChild)
            comicPanel.removeChild(comicPanel.firstChild);
    }
}

module IntroScreen {
    export function show() { introPanel.style.display = "" }
    export function hide() { introPanel.style.cssText += "display: none !important"; }
    export function returnToStartScreen() {
        IntroScreen.hide();
        StartScreen.show();
    }
}

module GameScreen {
    export function show() { gamearea.style.display = "" }
    export function hide() { gamearea.style.cssText += "display: none !important"; }
}

module ResultScreen {
    export function show() { resultPanel.style.display = "" }
    export function hide() { resultPanel.style.cssText += "display: none !important"; }
    export function returnToStartScreen() {
        ResultScreen.hide();
        StartScreen.show();
    }

    export function reflectResult(character: Module.Hero) {
        var score = Module.Score.score(character);
        var sex = character.sexuality == Module.Sexuality.Woman ? "여자" : "남자";
        resultPanelCharacter.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "1.png)";

        resultGradeSpan.textContent = character.getAverageGrade().toFixed(2);
        resultGradeScoreProgress.value = score.gradeScore;
        resultRelationshipProgress.value = score.relationship;
        resultSelfImprovementProgress.value = score.selfImprovement;

        resultTotalGrade.textContent = score.total.toFixed(2);
        resultTotalEvaluation.textContent = score.evaluateTotal();
        resultGradeEvaluation.textContent = score.evaluateGradeScore();
        resultRelationshipEvaluation.textContent = score.evaluateRelationship();
        resultSelfImprovementEvaluation.textContent = score.evaluateSelfImprovement();
    }
}