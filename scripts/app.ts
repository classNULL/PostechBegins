///<reference path="screenapi.ts" />
///<reference path="gamefunctions.ts" />

interface DOMStringMap {
    [key: string]: string;
}

declare var startarea: HTMLDivElement;
declare var selectorPanel: HTMLDivElement;
declare var introPanel: HTMLDivElement;
declare var comicPanel: HTMLDivElement;
declare var gamearea: HTMLDivElement;
declare var resultPanel: HTMLDivElement;

declare var gameTitleArea: HTMLDivElement;
declare var gameCharacterTitlesArea: HTMLDivElement;
declare var faceArea: HTMLDivElement;
declare var dice: HTMLImageElement;
declare var dicebutton: HTMLDivElement;
declare var stressDisplayBar: HTMLProgressElement;
declare var energyDisplayBar: HTMLProgressElement;
declare var gameGradeSpan: HTMLSpanElement;
declare var gameMonthEventDisplay: HTMLDivElement;
declare var gameMonthEventResultDisplay: HTMLDivElement;

declare var cellPanel: HTMLDivElement;
declare var cellMessage: HTMLDivElement;
declare var optionDisplay: HTMLDivElement;

declare var gameStartButton: HTMLDivElement;
declare var gameResumeButton: HTMLDivElement;
declare var gameIntroButton: HTMLDivElement;

declare var resultTotalGrade: HTMLSpanElement;
declare var resultNotMosol: HTMLSpanElement;
declare var resultGradeSpan: HTMLSpanElement;
declare var resultPanelCharacter: HTMLDivElement;
declare var resultGradeScoreProgress: HTMLProgressElement;
declare var resultRelationshipProgress: HTMLProgressElement;
declare var resultSelfImprovementProgress: HTMLProgressElement;
declare var resultTotalEvaluation: HTMLSpanElement;
declare var resultGradeEvaluation: HTMLSpanElement;
declare var resultRelationshipEvaluation: HTMLSpanElement;
declare var resultSelfImprovementEvaluation: HTMLSpanElement;

window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter: Module.GameCenter;
var currentMonth = Module.Month.March;
var currentMonthEvent: Module.MonthEvent;

var charInCell: HTMLDivElement;
var gameProgressArea: HTMLDivElement;
var cover: HTMLDivElement;
var optionResultDisplay: HTMLDivElement;

var beforeunloadSubscription: EventPromise.EventSubscription;

var gameSaveVersion = "gameSave14121600";

FixedViewport.polyfill(1920, 1080).onDOMContentLoaded();

window.addEventListener("DOMContentLoaded", () => {
    charInCell = <HTMLDivElement>document.querySelector(".charInCell");
    gameProgressArea = <HTMLDivElement>document.querySelector(".gameprogressarea");
    cover = <HTMLDivElement>document.querySelector(".cover");
    optionResultDisplay = <HTMLDivElement>document.querySelector(".option-result-display");

    StartScreen.reflectResumability();
    /*
    StartScreen.hide();
    ResultScreen.show();
    */
    /*
    createGameCenter(Module.Sexuality.Man);
    reflectDate(gameCenter.currentPosition);
    */
});

function timeoutPromise(time: number) {
    return new Promise<void>((resolve, reject) => {
        setTimeout(() => resolve(), time);
    });
}

interface GameStatus {
    characterProperty: Module.CharacterProperty;
    position: number;
    titles: string[];
}