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
var charInCell: HTMLDivElement;
window.addEventListener("DOMContentLoaded", () => {
    createGameCenter(Module.Sexuality.Man);
    charInCell = <HTMLDivElement>document.querySelector(".charInCell");
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
    
    if (gender == Module.Sexuality.Man)
        face.style.backgroundImage = "url(UI/캐릭터/남자/남자1.png)";
    else if (gender == Module.Sexuality.Woman)
        face.style.backgroundImage = "url(UI/캐릭터/여자/여자1.png)";

    colorize(gameCenter.map, Module.Month.March);
}

function move() {
    var step = gameCenter.dice();
    alert("주사위 수 " + step + "이(가) 나왔습니다.");
    var position = gameCenter.move(step);
    var posstr = dateIndexToString(position);
    alert(position + "번 칸에 멈추었습니다. " + posstr + "입니다.");
}

function dateIndexToString(index: number) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}

function rollDice() {
    dice.classList.add("rotate");
    return timeoutPromise(500).then(() => {
        dice.classList.remove("rotate");
        
        
        return gameCenter.dice();
    });
}

function timeoutPromise(time: number) {
    return new Promise<void>((resolve, reject) => {
        setTimeout(() => resolve(), time);
    });
}