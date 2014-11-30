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
        if (cell instanceof Module.NormalCell)
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
///<reference path="screenapi.ts" />
///<reference path="colorizer.ts" />
window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter;
window.addEventListener("DOMContentLoaded", function () {
    createGameCenter(Module.Sexuality.Man);
});
function createGameCenter(gender) {
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
function dateIndexToString(index) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}
function rollDice() {
    dice.classList.add("rotate");
    return timeoutPromise(1000).then(function () {
        dice.classList.remove("rotate");
        return gameCenter.dice();
    });
}
function timeoutPromise(time) {
    return new Promise(function (resolve, reject) {
        setTimeout(function () { return resolve(); }, time);
    });
}
//# sourceMappingURL=app.js.map