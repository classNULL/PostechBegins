///<reference path="screenapi.ts" />
///<reference path="colorizer.ts" />

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
window.addEventListener("DOMContentLoaded", () => {
    charInCell = <HTMLDivElement>document.querySelector(".charInCell");
    gameProgressArea = <HTMLDivElement>document.querySelector(".gameprogressarea");
    titleArea = <HTMLDivElement>document.querySelector(".titlearea");
    cover = <HTMLDivElement>document.querySelector(".cover");

    createGameCenter(Module.Sexuality.Man);
});

function createGameCenter(gender: Module.Sexuality) {
    gameCenter = new Module.GameCenter(gender);
    var gamechar = gameCenter.character;
    //alert(
    //    "love: " + gamechar.love
    //    + "\r\nenergy: " + gamechar.energy
    //    + "\r\nrelationship: " + gamechar.relationship
    //    + "\r\nselfImprovement: " + gamechar.selfImprovement
    //    + "\r\nstudy: " + gamechar.study
    //    + "\r\nMAX_ENERGY: " + gamechar.MAX_ENERGY
    //    + "\r\nMAX_LOVE: " + gamechar.MAX_LOVE
    //    + "\r\nMAX_RELATIONSHIP: " + gamechar.MAX_RELATIONSHIP
    //    + "\r\nMAX_SELFIMPROVEMENT: " + gamechar.MAX_SELFIMPROVEMENT);

    if (gender == Module.Sexuality.Man) {
        face.style.backgroundImage 
        = charInCell.style.backgroundImage 
        = "url(UI/캐릭터/남자/남자1.png)";
    }
    else if (gender == Module.Sexuality.Woman) {
        face.style.backgroundImage 
        = charInCell.style.backgroundImage 
        = "url(UI/캐릭터/여자/여자1.png)";
    }
    moveCharacter(1);
    colorize(gameCenter.map, Module.Month.March);
}

function moveCharacter(day: number) {
    charInCell.classList.remove("cell" + charInCell.dataset["day"]);
    charInCell.classList.add("cell" + day);
    charInCell.dataset["day"] = day.toString();
}

function move(step: number) {
    var position = gameCenter.move(step);

    var monthday = Module.MonthDay.fromIndex(position);
    moveCharacter(monthday.day);
    if (month !== monthday.month) {
        month = monthday.month;
        changeMonth(month);
        colorize(gameCenter.map, month);
    }
    monthday.delete();
    //alert(position + "번 칸에 멈추었습니다. " + posstr + "입니다.");
}

function dateIndexToString(index: number) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}

function rollDice() {
    dice.classList.add("rotate");
    cover.style.display = "";
    return timeoutPromise(500).then(() => {
        dice.classList.remove("rotate");
        cover.style.display = "none";
        
        var step = gameCenter.dice();
        move(step);
    });
}

function changeMonth(month: Module.Month) {
    var monthProgressDiv = <HTMLDivElement>gameProgressArea.children[month.value - 3];
    monthProgressDiv.classList.add("progressin");
    titleArea.textContent = month.value + "월";
}

function timeoutPromise(time: number) {
    return new Promise<void>((resolve, reject) => {
        setTimeout(() => resolve(), time);
    });
}