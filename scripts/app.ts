///<reference path="screenapi.ts" />
///<reference path="gamefunctions.ts" />

interface DOMStringMap {
    [key: string]: string;
}

declare var face: HTMLImageElement;
declare var dice: HTMLImageElement;

window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter: Module.GameCenter;
var month = Module.Month.March;
var charInCell: HTMLDivElement;
var gameProgressArea: HTMLDivElement;
var cover: HTMLDivElement;
var titleArea: HTMLDivElement;
var optionDisplay: HTMLDivElement;
var optionResultDisplay: HTMLDivElement;
window.addEventListener("DOMContentLoaded", () => {
    charInCell = <HTMLDivElement>document.querySelector(".charInCell");
    gameProgressArea = <HTMLDivElement>document.querySelector(".gameprogressarea");
    titleArea = <HTMLDivElement>document.querySelector(".titlearea");
    cover = <HTMLDivElement>document.querySelector(".cover");
    optionDisplay = <HTMLDivElement>document.querySelector(".option-display");
    optionResultDisplay = <HTMLDivElement>document.querySelector(".option-result-display");

    createGameCenter(Module.Sexuality.Man);
});

function timeoutPromise(time: number) {
    return new Promise<void>((resolve, reject) => {
        setTimeout(() => resolve(), time);
    });
}