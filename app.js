if (!Screen.prototype.lock)
    Screen.prototype.lock = function (orientation) {
        return new Promise(function (resolve, reject) {
            var lockOrientation = screen.lockOrientation || screen.mozLockOrientation || screen.msLockOrientation;
            if (lockOrientation && lockOrientation.call(screen, orientation))
                resolve();
            else
                reject(new Error("Screen couldn't be locked."));
        });
    };
function colorize(maptable, month) {
    var map = document.querySelector(".map");
    var firstday = Module.MonthDay.fromCalendar(month, 1);
    var firstdayIndex = firstday.index;
    firstday.delete();
    var days = Module.MonthDay.containingDays(month);
    for (var i = 0; i < days; i++) {
        var cell = maptable.at(firstdayIndex + i);
        var type = "";
        if (cell instanceof Module.NormalCell || cell instanceof Module.NormalCell || cell instanceof Module.NormalCell || cell instanceof Module.NormalCell)
            type = "normal";
        else if (cell instanceof Module.MarchCell)
            type = "march";
        else if (cell instanceof Module.WeekendCell)
            type = "weekend";
        else if (cell instanceof Module.BeforeExamCell)
            type = "before_exam";
        else if (cell instanceof Module.ExamCell)
            type = "exam";
        else if (cell instanceof Module.AfterExamCell)
            type = "after_exam";
        else if (cell instanceof Module.FestivalCell)
            type = "festival";
        else if (cell instanceof Module.DanceCell)
            type = "dance";
        else if (cell instanceof Module.SpecialCell)
            type = "special";
        var cellElement = map.querySelector(".cell" + (i + 1));
        if (type)
            cellElement.dataset["cellType"] = type;
        else
            cellElement.dataset["cellType"] = "";
        cellElement.style.display = "";
    }
    for (var i = days; i < 31; i++) {
        var cellElement = map.querySelector(".cell" + (i + 1));
        cellElement.style.display = "none";
    }
}
///<reference path="colorizer.ts" />
function createGameCenter(gender) {
    gameCenter = new Module.GameCenter(gender);
    if (gender == Module.Sexuality.Man) {
        faceArea.style.backgroundImage = charInCell.style.backgroundImage = "url(UI/캐릭터/남자/남자1.png)";
    }
    else if (gender == Module.Sexuality.Woman) {
        faceArea.style.backgroundImage = charInCell.style.backgroundImage = "url(UI/캐릭터/여자/여자1.png)";
    }
    moveCharacter(1);
    reflectMonth(Module.Month.March);
    reflectMonthEvent(Module.Month.March);
    reflectMaxStatus(gameCenter.mutableCharacter());
    reflectStatus(gameCenter.mutableCharacter());
    gameCenter.recordCurrentStatus();
}
function moveCharacter(day) {
    charInCell.classList.remove("cell" + charInCell.dataset["day"]);
    charInCell.classList.add("cell" + day);
    charInCell.dataset["day"] = day.toString();
}
function reflectDate(dateIndex) {
    var monthday = Module.MonthDay.fromIndex(dateIndex);
    if (currentMonth !== monthday.month) {
        reflectMonth(monthday.month);
        currentTitles = assignTitles();
        reflectTitles(currentTitles);
        passMonthEvent();
        reflectMonthEvent(monthday.month);
        gameCenter.recordCurrentStatus();
    }
    else if (monthday.day > 15) {
        gameMonthEventResultDisplay.textContent = "";
    }
    moveCharacter(monthday.day);
    monthday.delete();
}
function reflectLove() {
    var love = gameCenter.character.status.love;
    var mutableCharacter = gameCenter.mutableCharacter();
    if (love == 100) {
        mutableCharacter.mutableTitleBook().addTitle("couple");
        mutableCharacter.couple();
        currentTitles.push("연애중");
    }
    else if (love < 50) {
        mutableCharacter.mutableTitleBook().removeTitle("couple");
        currentTitles = currentTitles.filter(function (title) { return title !== "couple"; });
    }
    reflectTitles(currentTitles);
}
function reflectTitles(titles) {
    while (gameCharacterTitlesArea.firstChild)
        gameCharacterTitlesArea.removeChild(gameCharacterTitlesArea.firstChild);
    titles.forEach(function (title) {
        var displayName;
        switch (title) {
            case "outsider":
                displayName = "아싸";
                break;
            case "alcoholic":
                displayName = "술쟁이";
                break;
            case "circle_resident":
                displayName = "동방충";
                break;
            case "nerd":
                displayName = "공부벌레";
                break;
            case "couple":
                displayName = "연애중";
                break;
            case "circle_independent":
                displayName = "무동아리";
                break;
            case "weak":
                displayName = "체력낮음";
                break;
            default:
                throw new Error("알 수 없는 칭호");
        }
        gameCharacterTitlesArea.appendChild(DOMLiner.element("div", null, displayName));
    });
}
function reflectMonthEvent(month) {
    currentMonthEvent = getMonthEvent(month);
    gameMonthEventDisplay.textContent = currentMonthEvent.introduction;
}
function passMonthEvent() {
    var eventResultMessage = currentMonthEvent.checkSuccess(gameCenter.character, gameCenter.getStatusIncrease());
    gameMonthEventResultDisplay.textContent = eventResultMessage;
}
function dateIndexToString(index) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}
function rollDice() {
    dice.classList.add("rotate");
    dicebutton.classList.add("pushed");
    coverScreen();
    var optionBook;
    var cell;
    return timeoutPromise(500).then(function () {
        dice.classList.remove("rotate");
        var step = gameCenter.dice();
        optionResultDisplay.textContent = "주사위를 던져서 " + step + "이 나왔다.";
        dice.src = "UI/UI/기타/dice" + step + ".png";
        var currentPosition = gameCenter.currentPosition;
        var newPosition = gameCenter.move(step);
        reflectDate(newPosition);
        cell = gameCenter.map.at(newPosition);
        optionBook = cell.callOption(gameCenter.mutableCharacter(), newPosition - currentPosition);
        setCellMessage(cell.cellMessage);
    }).then(function () { return timeoutPromise(500); }).then(function () {
        setOptions(optionBook);
        showOptions();
        return waitOptionSelection();
    }).then(function (index) {
        if (cell instanceof Module.WinterVacationCell) {
            GameScreen.hide();
            ResultScreen.reflectResult(gameCenter.character);
            ResultScreen.show();
            gameCenter.delete();
            return;
        }
        var result = optionBook.at(index).apply();
        optionResultDisplay.textContent = result;
        optionBook.delete();
        if (cell instanceof Module.ExamCell) {
            gameGradeSpan.textContent = gameCenter.character.getSemesterGrade(gameCenter.character.spring).toFixed(2);
        }
        reflectStatus(gameCenter.mutableCharacter());
        reflectDate(gameCenter.passSkips());
        reflectFace(gameCenter.character);
        dicebutton.classList.remove("pushed");
        dice.src = "UI/UI/기타/dice.png";
        hideOptions();
        clearOptions();
        uncoverScreen();
    });
}
function reflectMonth(month) {
    for (var i = currentMonth.value + 1; i <= month.value; i++) {
        var monthProgressDiv = gameProgressArea.children[i - 3];
        monthProgressDiv.classList.add("progressin");
    }
    currentMonth = month;
    gameTitleArea.textContent = month.value + "월";
    document.documentElement.style.backgroundImage = 'url("UI/wallpaper/' + month.value + '.jpg")';
    colorize(gameCenter.map, month);
}
function getMonthEvent(month) {
    switch (month) {
        case Module.Month.March:
            return new Module.MarchEvent();
        case Module.Month.April:
            return new Module.AprilEvent();
        case Module.Month.May:
            return new Module.MayEvent();
        case Module.Month.June:
            return new Module.JuneEvent();
        case Module.Month.September:
            return new Module.SeptemberEvent();
        case Module.Month.October:
            return new Module.OctoberEvent();
        case Module.Month.November:
            return new Module.NovemberEvent();
        case Module.Month.December:
            return new Module.DecemberEvent();
        default:
            throw new Error("이 달에는 이벤트가 발생할 수 없습니다");
    }
}
/* cover */
function coverScreen() {
    cover.style.display = "";
}
function uncoverScreen() {
    cover.style.display = "none";
}
/* status */
function reflectStatus(character) {
    stressDisplayBar.value = character.status.stress;
    energyDisplayBar.value = character.status.energy;
}
function reflectMaxStatus(character) {
    stressDisplayBar.max = character.maxStatus.stress;
    energyDisplayBar.max = character.maxStatus.energy;
}
function reflectFace(character) {
    var sex = character.sexuality == Module.Sexuality.Woman ? "여자" : "남자";
    var stress = character.status.stress;
    if (stress < 25) {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "1.png)";
    }
    else if (stress < 50) {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "2.png)";
    }
    else if (stress < 75) {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "3.png)";
    }
    else {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "4.png)";
    }
}
/* options */
function setOptions(options) {
    for (var i = 0; i < options.size; i++) {
        optionDisplay.appendChild(createOptionItemBlock(options.at(i), i));
    }
}
function createOptionItemBlock(option, index) {
    return DOMLiner.element("div", { class: "option-item", "data-option-index": index.toString() }, option.title);
}
function waitOptionSelection() {
    var optionItemBlocks = optionDisplay.children;
    return new Promise(function (resolve, reject) {
        var waiter = function (ev) {
            for (var i = 0; i < optionItemBlocks.length; i++)
                optionItemBlocks[i].removeEventListener("click", waiter);
            resolve(parseInt(ev.target.dataset["optionIndex"]));
        };
        for (var i = 0; i < optionItemBlocks.length; i++)
            optionItemBlocks[i].addEventListener("click", waiter);
    });
}
function clearOptions() {
    while (optionDisplay.firstChild)
        optionDisplay.removeChild(optionDisplay.firstChild);
}
function showOptions() {
    cellPanel.style.display = "";
}
function hideOptions() {
    cellPanel.style.display = "none";
}
function setCellMessage(message) {
    cellMessage.textContent = message;
}
function assignTitles() {
    var increase = gameCenter.getStatusIncrease();
    var titleBook = gameCenter.mutableCharacter().mutableTitleBook();
    var titles = [];
    var assign = function (title, enable) {
        if (enable) {
            titleBook.addTitle(title);
            titles.push(title);
        }
        else
            titleBook.removeTitle(title);
    };
    assign("outsider", increase.relationship < 10);
    assign("alcoholic", increase.relationship > 50 && increase.selfImprovement <= 8);
    assign("circle_resident", increase.selfImprovement > 16);
    assign("nerd", increase.study > -10);
    assign("circle_independent", increase.selfImprovement == 0);
    return titles;
}
///<reference path="screenapi.ts" />
///<reference path="gamefunctions.ts" />
window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter;
var currentMonth = Module.Month.March;
var currentMonthEvent;
var currentTitles = [];
var charInCell;
var gameProgressArea;
var cover;
var optionResultDisplay;
window.addEventListener("DOMContentLoaded", function () {
    charInCell = document.querySelector(".charInCell");
    gameProgressArea = document.querySelector(".gameprogressarea");
    cover = document.querySelector(".cover");
    optionResultDisplay = document.querySelector(".option-result-display");
    /*
    StartScreen.hide();
    ResultScreen.show();
    */
    /*
    createGameCenter(Module.Sexuality.Man);
    reflectDate(gameCenter.currentPosition);
    */
});
function timeoutPromise(time) {
    return new Promise(function (resolve, reject) {
        setTimeout(function () { return resolve(); }, time);
    });
}
var StartScreen;
(function (StartScreen) {
    function show() {
        startarea.style.display = "";
    }
    StartScreen.show = show;
    function hide() {
        startarea.style.cssText += "display: none !important";
    }
    StartScreen.hide = hide;
    function startGame() {
        StartScreen.hide();
        CharacterSelectionScreen.show();
    }
    StartScreen.startGame = startGame;
    function resumeGame() {
    }
    StartScreen.resumeGame = resumeGame;
    function introduce() {
        StartScreen.hide();
        IntroScreen.show();
    }
    StartScreen.introduce = introduce;
})(StartScreen || (StartScreen = {}));
var CharacterSelectionScreen;
(function (CharacterSelectionScreen) {
    function show() {
        selectorPanel.style.display = "";
        document.documentElement.style.backgroundImage = 'url("UI/게임 설명화면/선택화면배경.jpg")';
    }
    CharacterSelectionScreen.show = show;
    function hide() {
        selectorPanel.style.cssText += "display: none !important";
    }
    CharacterSelectionScreen.hide = hide;
    function select(sexuality) {
        CharacterSelectionScreen.hide();
        ComicScreen.show();
        ComicScreen.play().then(function () {
            ComicScreen.hide();
            GameScreen.show();
            createGameCenter(sexuality);
            reflectDate(gameCenter.currentPosition);
        });
    }
    CharacterSelectionScreen.select = select;
})(CharacterSelectionScreen || (CharacterSelectionScreen = {}));
var ComicScreen;
(function (ComicScreen) {
    function show() {
        comicPanel.style.display = "";
        document.documentElement.style.backgroundImage = 'url("UI/로딩화면/배경.png")';
    }
    ComicScreen.show = show;
    function hide() {
        comicPanel.style.cssText += "display: none !important";
    }
    ComicScreen.hide = hide;
    function play() {
        var parent = comicPanel;
        var sequence = Promise.resolve();
        for (var i = 2; i <= 6; i++) {
            (function (index) {
                sequence = sequence.then(function () { return timeoutPromise(2000); }).then(function () {
                    var child = DOMLiner.element("div", { style: 'background-image: url("UI/로딩화면/' + index + '.png")' });
                    parent.appendChild(child);
                    parent = child;
                });
            })(i);
        }
        return sequence.then(function () { return timeoutPromise(2000); }).then(function () {
            parent.appendChild(DOMLiner.element("div", { class: "fade-in", style: 'background-image: url("UI/로딩화면/logo.jpg")' }));
        }).then(function () { return timeoutPromise(4000); });
    }
    ComicScreen.play = play;
    function clear() {
        while (comicPanel.firstChild)
            comicPanel.removeChild(comicPanel.firstChild);
    }
})(ComicScreen || (ComicScreen = {}));
var IntroScreen;
(function (IntroScreen) {
    function show() {
        introPanel.style.display = "";
    }
    IntroScreen.show = show;
    function hide() {
        introPanel.style.cssText += "display: none !important";
    }
    IntroScreen.hide = hide;
    function returnToStartScreen() {
        IntroScreen.hide();
        StartScreen.show();
    }
    IntroScreen.returnToStartScreen = returnToStartScreen;
})(IntroScreen || (IntroScreen = {}));
var GameScreen;
(function (GameScreen) {
    function show() {
        gamearea.style.display = "";
    }
    GameScreen.show = show;
    function hide() {
        gamearea.style.cssText += "display: none !important";
    }
    GameScreen.hide = hide;
})(GameScreen || (GameScreen = {}));
var ResultScreen;
(function (ResultScreen) {
    function show() {
        resultPanel.style.display = "";
    }
    ResultScreen.show = show;
    function hide() {
        resultPanel.style.cssText += "display: none !important";
    }
    ResultScreen.hide = hide;
    function reflectResult(character) {
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
    ResultScreen.reflectResult = reflectResult;
})(ResultScreen || (ResultScreen = {}));
//# sourceMappingURL=app.js.map