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
    static show() { selectorPanel.style.display = "" }
    static hide() { selectorPanel.style.cssText += "display: none !important"; }

    static select(sexuality: Module.Sexuality) {
        CharacterSelectionScreen.hide();
        GameScreen.show();
        createGameCenter(sexuality);
        reflectDate(gameCenter.currentPosition);
    }
}

class IntroScreen {
    static show() { introPanel.style.display = "" }
    static hide() { introPanel.style.cssText += "display: none !important"; }
    static returnToStartScreen() {
        StartScreen.show();
    }
}

class GameScreen {
    static show() { gamearea.style.display = "" }
    static hide() { gamearea.style.cssText += "display: none !important"; }
}