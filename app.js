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
    colorize(gameCenter.map, Module.Month.March);
    reflectMaxStatus(gameCenter.mutableCharacter());
    reflectStatus(gameCenter.mutableCharacter());
}
function moveCharacter(day) {
    charInCell.classList.remove("cell" + charInCell.dataset["day"]);
    charInCell.classList.add("cell" + day);
    charInCell.dataset["day"] = day.toString();
}
function reflectDate(dateIndex) {
    var monthday = Module.MonthDay.fromIndex(dateIndex);
    if (currentMonth !== monthday.month)
        changeMonth(monthday.month);
    moveCharacter(monthday.day);
    monthday.delete();
}
function dateIndexToString(index) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}
function rollDice() {
    dice.classList.add("rotate");
    coverScreen();
    var optionBook;
    return timeoutPromise(500).then(function () {
        dice.classList.remove("rotate");
        var step = gameCenter.dice();
        optionResultDisplay.textContent = "주사위를 던져서 " + step + "이 나왔다.";
        var currentPosition = gameCenter.currentPosition;
        var newPosition = gameCenter.move(step);
        reflectDate(newPosition);
        optionBook = gameCenter.map.at(newPosition).callOption(gameCenter.mutableCharacter(), newPosition - currentPosition);
        setCellMessage(gameCenter.map.at(gameCenter.currentPosition).cellMessage);
    }).then(function () { return timeoutPromise(500); }).then(function () {
        setOptions(optionBook);
        showOptions();
        return waitOptionSelection();
    }).then(function (index) {
        var result = optionBook.at(index).apply();
        optionResultDisplay.textContent = result;
        optionBook.delete();
        reflectStatus(gameCenter.mutableCharacter());
        reflectDate(gameCenter.passSkips());
        hideOptions();
        clearOptions();
        uncoverScreen();
    });
}
function changeMonth(month) {
    currentMonth = month;
    var monthProgressDiv = gameProgressArea.children[month.value - 3];
    monthProgressDiv.classList.add("progressin");
    titleArea.textContent = month.value + "월";
    document.documentElement.style.backgroundImage = 'url("UI/wallpaper/' + month.value + '.jpg")';
    colorize(gameCenter.map, month);
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
///<reference path="screenapi.ts" />
///<reference path="gamefunctions.ts" />
window.screen.lock("landscape-primary");
Module.srand(Date.now() & 65535);
var gameCenter;
var currentMonth = Module.Month.March;
var charInCell;
var gameProgressArea;
var cover;
var titleArea;
var faceArea;
var optionResultDisplay;
window.addEventListener("DOMContentLoaded", function () {
    charInCell = document.querySelector(".charInCell");
    gameProgressArea = document.querySelector(".gameprogressarea");
    titleArea = document.querySelector(".titlearea");
    faceArea = document.querySelector(".facearea");
    cover = document.querySelector(".cover");
    optionResultDisplay = document.querySelector(".option-result-display");
    createGameCenter(Module.Sexuality.Man);
});
function timeoutPromise(time) {
    return new Promise(function (resolve, reject) {
        setTimeout(function () { return resolve(); }, time);
    });
}
//# sourceMappingURL=app.js.map