///<reference path="colorizer.ts" />

function createGameCenter(gender: Module.Sexuality) {
    gameCenter = new Module.GameCenter(gender);

    if (gender == Module.Sexuality.Man) {
        faceArea.style.backgroundImage
        = charInCell.style.backgroundImage
        = "url(UI/캐릭터/남자/남자1.png)";
    }
    else if (gender == Module.Sexuality.Woman) {
        faceArea.style.backgroundImage
        = charInCell.style.backgroundImage
        = "url(UI/캐릭터/여자/여자1.png)";
    }
    moveCharacter(1);
    colorize(gameCenter.map, Module.Month.March);
    reflectMaxStatus(gameCenter.mutableCharacter());
    reflectStatus(gameCenter.mutableCharacter());
}

function moveCharacter(day: number) {
    charInCell.classList.remove("cell" + charInCell.dataset["day"]);
    charInCell.classList.add("cell" + day);
    charInCell.dataset["day"] = day.toString();
}

function reflectDate(dateIndex: number) {
    var monthday = Module.MonthDay.fromIndex(dateIndex);
    if (currentMonth !== monthday.month)
        changeMonth(monthday.month);
    moveCharacter(monthday.day)
    monthday.delete();
}

function dateIndexToString(index: number) {
    var monthday = Module.MonthDay.fromIndex(index);
    var result = monthday.month.value + "월 " + monthday.day + "일";
    monthday.delete();
    return result;
}

function rollDice() {
    dice.classList.add("rotate");
    dicebutton.classList.add("pushed");
    coverScreen();

    var optionBook: Module.CellOptionBook;
    return timeoutPromise(500)
        .then(() => {
            dice.classList.remove("rotate");

            var step = gameCenter.dice();
            optionResultDisplay.textContent = "주사위를 던져서 " + step + "이 나왔다.";
            dice.src = "UI/UI/기타/dice" + step + ".png";

            var currentPosition = gameCenter.currentPosition;
            var newPosition = gameCenter.move(step);
            reflectDate(newPosition);

            optionBook = gameCenter.map.at(newPosition).callOption(gameCenter.mutableCharacter(), newPosition - currentPosition);
            setCellMessage(gameCenter.map.at(gameCenter.currentPosition).cellMessage);
        })
        .then(() => timeoutPromise(500))
        .then(() => {
            setOptions(optionBook);
            showOptions();
            return waitOptionSelection();
        })
        .then((index) => {
            var result = optionBook.at(index).apply();
            optionResultDisplay.textContent = result;
            optionBook.delete();
            reflectStatus(gameCenter.mutableCharacter());

            reflectDate(gameCenter.passSkips());

            dicebutton.classList.remove("pushed");
            dice.src = "UI/UI/기타/dice.png";
            hideOptions();
            clearOptions();
            uncoverScreen();
        });
}

function changeMonth(month: Module.Month) {
    for (var i = currentMonth.value + 1; i <= month.value; i++) {
        var monthProgressDiv = <HTMLDivElement>gameProgressArea.children[i - 3];
        monthProgressDiv.classList.add("progressin");
    }
    currentMonth = month;

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

function reflectStatus(character: Module.Hero) {
    stressDisplayBar.value = character.status.stress;
    energyDisplayBar.value = character.status.energy;
}

function reflectMaxStatus(character: Module.Hero) {
    stressDisplayBar.max = character.maxStatus.stress;
    energyDisplayBar.max = character.maxStatus.energy;
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
            resolve(parseInt((<HTMLElement>ev.target).dataset["optionIndex"]));
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
function setCellMessage(message: string) {
    cellMessage.textContent = message;
}