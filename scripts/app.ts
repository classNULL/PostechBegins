///<reference path="screenapi.ts" />
///<reference path="gamefunctions.ts" />

interface DOMStringMap {
    [key: string]: string;
}

declare var startarea: HTMLDivElement;
declare var selectorPanel: HTMLDivElement;
declare var introPanel: HTMLDivElement;
declare var gamearea: HTMLDivElement;

declare var gameTitleArea: HTMLDivElement;
declare var faceArea: HTMLDivElement;
declare var dice: HTMLImageElement;
declare var dicebutton: HTMLDivElement;
declare var stressDisplayBar: HTMLProgressElement;
declare var energyDisplayBar: HTMLProgressElement;

declare var cellPanel: HTMLDivElement;
declare var cellMessage: HTMLDivElement;
declare var optionDisplay: HTMLDivElement;

declare var gameStartButton: HTMLDivElement;
declare var gameResumeButton: HTMLDivElement;
declare var gameIntroButton: HTMLDivElement;

window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter: Module.GameCenter;
var currentMonth = Module.Month.March;

var charInCell: HTMLDivElement;
var gameProgressArea: HTMLDivElement;
var cover: HTMLDivElement;
var optionResultDisplay: HTMLDivElement;
window.addEventListener("DOMContentLoaded", () => {
    charInCell = <HTMLDivElement>document.querySelector(".charInCell");
    gameProgressArea = <HTMLDivElement>document.querySelector(".gameprogressarea");
    cover = <HTMLDivElement>document.querySelector(".cover");
    optionResultDisplay = <HTMLDivElement>document.querySelector(".option-result-display");

    
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