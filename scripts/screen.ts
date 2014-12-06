class StartScreen {
    static show() { startarea.style.display = ""; }
    static hide() { startarea.style.cssText += "display: none !important"; }

    static startGame() {
        StartScreen.hide();
        CharacterSelectionScreen.show();
    }
    static resumeGame() { }
    static introduce() {
        StartScreen.hide();
        IntroScreen.show();
    }
}

class CharacterSelectionScreen {
    static show() { 
        selectorPanel.style.display = "";
        document.documentElement.style.backgroundImage = 'url("UI/게임 설명화면/선택화면배경.jpg")';
    }
    static hide() { selectorPanel.style.cssText += "display: none !important"; }

    static select(sexuality: Module.Sexuality) {
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

class ComicScreen {
    static show() {
        comicPanel.style.display = "";
        document.documentElement.style.backgroundImage = 'url("UI/로딩화면/배경.png")';
    }
    static hide() { comicPanel.style.cssText += "display: none !important"; }
    static play() { 
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
        return sequence.then(() => timeoutPromise(2000));
    }
    private static clear() {
        while (comicPanel.firstChild)
            comicPanel.removeChild(comicPanel.firstChild);
    }
}

class IntroScreen {
    static show() { introPanel.style.display = "" }
    static hide() { introPanel.style.cssText += "display: none !important"; }
    static returnToStartScreen() {
        IntroScreen.hide();
        StartScreen.show();
    }
}

class GameScreen {
    static show() { gamearea.style.display = "" }
    static hide() { gamearea.style.cssText += "display: none !important"; }
}