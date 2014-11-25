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
///<reference path="screenapi.ts" />
window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter;
function createGameCenter(gender) {
    gameCenter = new Module.GameCenter(gender);
    var gamechar = gameCenter.character;
    alert("love: " + gamechar.love + "\r\nenergy: " + gamechar.energy + "\r\nrelationship: " + gamechar.relationship + "\r\nselfImprovement: " + gamechar.selfImprovement + "\r\nstudy: " + gamechar.study + "\r\nMAX_ENERGY: " + gamechar.MAX_ENERGY + "\r\nMAX_LOVE: " + gamechar.MAX_LOVE + "\r\nMAX_RELATIONSHIP: " + gamechar.MAX_RELATIONSHIP + "\r\nMAX_SELFIMPROVEMENT: " + gamechar.MAX_SELFIMPROVEMENT);
    selectGender.style.display = "none";
    mover.style.display = "";
    characterImage.style.display = "";
    if (gender == Module.Sexuality.Man)
        characterImage.src = "UI/캐릭터/남자/남자1.png";
    else if (gender == Module.Sexuality.Woman)
        characterImage.src = "UI/캐릭터/여자/여자1.png";
}
function move() {
    var step = gameCenter.dice();
    alert("주사위 수 " + step + "이(가) 나왔습니다.");
    var position = gameCenter.move(step);
    var posstr = dateIndexToString(position);
    alert(position + "번 칸에 멈추었습니다. " + posstr + "입니다.");
    currentPositionRepresenter.textContent = position + ". " + posstr;
}
function dateIndexToString(index) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}
//# sourceMappingURL=app.js.map