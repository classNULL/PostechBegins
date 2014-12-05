///<reference path="colorizer.ts" />

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
    return position;
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
    coverScreen();

    var optionBook: Module.CellOptionBook;
    return timeoutPromise(500)
        .then(() => {
            dice.classList.remove("rotate");

            var step = gameCenter.dice();
            var position = move(step);

            optionBook = gameCenter.map.at(position).callOption(gameCenter.character, 1);
            setOptions(optionBook);
            showOptions();
            return waitOptionSelection();
        })
        .then((index) => {
            var result = optionBook.at(index).apply();
            optionResultDisplay.textContent = result;
            optionBook.delete();

            hideOptions();
            clearOptions();
            uncoverScreen();
        });
}

function changeMonth(month: Module.Month) {
    var monthProgressDiv = <HTMLDivElement>gameProgressArea.children[month.value - 3];
    monthProgressDiv.classList.add("progressin");
    titleArea.textContent = month.value + "월";
    document.documentElement.style.backgroundImage = 'url("UI/wallpaper/' + month.value + '.jpg")';
}

/* cover */

function coverScreen() {
    cover.style.display = "";
}
function uncoverScreen() {
    cover.style.display = "none";
}

/* options */

function setOptions(options: Module.CellOptionBook) {
    for (var i = 0; i < options.size; i++) {
        optionDisplay.appendChild(createOptionItemBlock(options.at(i), i));
    }
}
function createOptionItemBlock(option: Module.CellOption, index: number) {
    return DOMLiner.element("div", { class: "option-item", "data-option-index": index.toString() }, option.title);
}
function waitOptionSelection() {
    var optionItemBlocks = optionDisplay.children;
    return new Promise<number>((resolve, reject) => {
        var waiter = (ev: PointerEvent) => {
            for (var i = 0; i < optionItemBlocks.length; i++)
                optionItemBlocks[i].removeEventListener("click", waiter);
            resolve(parseInt((<HTMLElement>ev.target).dataset["dataOptionIndex"]));
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
    optionDisplay.style.display = "";
}
function hideOptions() {
    optionDisplay.style.display = "none";
}