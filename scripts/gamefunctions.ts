///<reference path="colorizer.ts" />

function initializeGame() {
    reflectGameStatus();
    gameCenter.recordCurrentStatus();
    runWorkers();
}
function reflectGameStatus() {
    var monthday = Module.MonthDay.fromIndex(gameCenter.currentPosition);
    reflectMonth(monthday.month);
    reflectMonthEvent(monthday.month);
    reflectDate(gameCenter.currentPosition);
    monthday.delete();

    reflectGender(gameCenter.character.sexuality);
    reflectMaxStatus(gameCenter.character);
    reflectStatus(gameCenter.character);
    reflectFace(gameCenter.character);
}
function runWorkers() {
    beforeunloadSubscription = EventPromise.subscribeEvent(window, "beforeunload", (ev: BeforeUnloadEvent) => {
        return ev.returnValue = "게임을 종료하시겠습니까? 현재 상태는 매 20초 및 매달마다 자동으로 저장됩니다.";
    });
    var saver = () => {
        if (!gameCenter)
            return;

        saveGame()
            .then(() => timeoutPromise(20000))
            .then(() => saver());
        console.log("Saved");
    };
    timeoutPromise(20000).then(() => saver());
}
function saveGame() {
    return localforage.setItem(gameSaveVersion,
        <GameStatus>{
            characterProperty: gameCenter.character.getCurrentProperty(),
            position: gameCenter.currentPosition
        });
}
function removeSave() {
    return localforage.removeItem(gameSaveVersion);
}

function reflectGender(gender: Module.Sexuality) {
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
}

function moveCharacter(day: number) {
    charInCell.classList.remove("cell" + charInCell.dataset["day"]);
    charInCell.classList.add("cell" + day);
    charInCell.dataset["day"] = day.toString();
}

function reflectDate(dateIndex: number) {
    var monthday = Module.MonthDay.fromIndex(dateIndex);
    if (currentMonth !== monthday.month) {
        reflectMonth(monthday.month);
        assignTitles();
        reflectTitles();
        passMonthEvent();
        reflectMonthEvent(monthday.month);
        gameCenter.recordCurrentStatus();
        saveGame();
    }
    else if (monthday.day > 6) {
        gameMonthEventResultDisplay.textContent = "";
    }
    reflectLove();

    moveCharacter(monthday.day);
    monthday.delete();
}

function reflectLove() {
    var love = gameCenter.character.status.love;
    var mutableCharacter = gameCenter.mutableCharacter();
    if (love == 100) {
        mutableCharacter.mutableTitleBook().addTitle("couple");
        mutableCharacter.couple();
    }
    else if (love < 50) {
        mutableCharacter.mutableTitleBook().removeTitle("couple");
    }
    reflectTitles();
}

function reflectTitles() {
    while (gameCharacterTitlesArea.firstChild)
        gameCharacterTitlesArea.removeChild(gameCharacterTitlesArea.firstChild);

    var titleVector = gameCenter.character.titleBook.containingTitles();
    for (var i = 0; i < titleVector.size; i++) {
        var displayName: string;
        switch (titleVector.at(i)) {
            case "outsider": displayName = "아싸"; break;
            case "alcoholic": displayName = "술쟁이"; break;
            case "circle_resident": displayName = "동방충"; break;
            case "nerd": displayName = "공부벌레"; break;
            case "couple": displayName = "연애중"; break;
            case "circle_independent": displayName = "무동아리"; break;
            case "weak": displayName = "체력낮음"; break;
            default: throw new Error("알 수 없는 칭호");
        }
        gameCharacterTitlesArea.appendChild(DOMLiner.element("div", null, displayName));
    }
}

function reflectMonthEvent(month: Module.Month) {
    currentMonthEvent = getMonthEvent(month);
    gameMonthEventDisplay.textContent = currentMonthEvent.introduction;
}
function passMonthEvent() {
    var eventResultMessage = currentMonthEvent.checkSuccess(gameCenter.character, gameCenter.getStatusIncrease());
    gameMonthEventResultDisplay.textContent = eventResultMessage;
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
    var cell: Module.Cell;
    return timeoutPromise(500)
        .then(() => {
            dice.classList.remove("rotate");

            var step = gameCenter.dice();
            optionResultDisplay.textContent = "주사위를 던져서 " + step + "이 나왔다.";
            dice.src = "UI/UI/기타/dice" + step + ".png";

            var currentPosition = gameCenter.currentPosition;
            var newPosition = gameCenter.move(step);
            reflectDate(newPosition);

            cell = gameCenter.map.at(newPosition);
            optionBook = cell.callOption(gameCenter.mutableCharacter(), newPosition - currentPosition);
            setCellMessage(cell.cellMessage);
        })
        .then(() => timeoutPromise(500))
        .then(() => {
            setOptions(optionBook);
            showOptions();
            return waitOptionSelection();
        })
        .then((index) => {
            if (cell instanceof Module.WinterVacationCell) {
                GameScreen.hide();
                ResultScreen.reflectResult(gameCenter.character);
                ResultScreen.show();

                beforeunloadSubscription.cease();
                removeSave();

                gameCenter.delete();
                return;
            }

            var result = optionBook.at(index).apply();
            optionResultDisplay.textContent = result;
            optionBook.delete();

            if (cell instanceof Module.ExamCell) {
                gameGradeSpan.textContent = gameCenter.character.getSemesterGrade(gameCenter.character.spring).toFixed(2);
            }

            reflectStatus(gameCenter.mutableCharacter());
            reflectDate(gameCenter.passSkips());
            reflectFace(gameCenter.character);

            dicebutton.classList.remove("pushed");
            dice.src = "UI/UI/기타/dice.png";
            hideOptions();
            clearOptions();
            uncoverScreen();
        });
}

function reflectMonth(month: Module.Month) {
    for (var i = currentMonth.value + 1; i <= month.value; i++) {
        var monthProgressDiv = <HTMLDivElement>gameProgressArea.children[i - 3];
        monthProgressDiv.classList.add("progressin");
    }
    currentMonth = month;

    gameTitleArea.textContent = month.value + "월";
    document.documentElement.style.backgroundImage = 'url("UI/wallpaper/' + month.value + '.jpg")';
    colorize(gameCenter.map, month);
}

function getMonthEvent(month: Module.Month) {
    switch (month) {
        case Module.Month.March: return new Module.MarchEvent();
        case Module.Month.April: return new Module.AprilEvent();
        case Module.Month.May: return new Module.MayEvent();
        case Module.Month.June: return new Module.JuneEvent();
        case Module.Month.September: return new Module.SeptemberEvent();
        case Module.Month.October: return new Module.OctoberEvent();
        case Module.Month.November: return new Module.NovemberEvent();
        case Module.Month.December: return new Module.DecemberEvent();
        
        default: throw new Error("이 달에는 이벤트가 발생할 수 없습니다");
    }
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

function reflectFace(character: Module.Hero) {
    var sex = character.sexuality == Module.Sexuality.Woman ? "여자" : "남자";
    var stress = character.status.stress;
    if (stress < 25) {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "1.png)";
    }
    else if (stress < 50) {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "2.png)";
    }
    else if (stress < 75) {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "3.png)";
    }
    else {
        faceArea.style.backgroundImage = "url(UI/캐릭터/" + sex + "/" + sex + "4.png)";
    }
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

function assignTitles() {
    var increase = gameCenter.getStatusIncrease();
    var titleBook = gameCenter.mutableCharacter().mutableTitleBook();

    var assign = (title: string, enable: boolean) => {
        if (enable)
            titleBook.addTitle(title);
        else 
            titleBook.removeTitle(title);
    };

    assign("outsider", increase.relationship < 10);
    assign("alcoholic", increase.relationship > 50 && increase.selfImprovement <= 8);
    assign("circle_resident", increase.selfImprovement > 16);
    assign("nerd", increase.study > -10);
    assign("circle_independent", increase.selfImprovement == 0);
}