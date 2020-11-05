function colorize(maptable: Module.MapTable, month: Module.Month) {
    var map = <HTMLDivElement>document.querySelector(".map");

    var firstday = Module.MonthDay.fromCalendar(month, 1);
    var firstdayIndex = firstday.index;
    firstday.delete();
    var days = Module.MonthDay.containingDays(month);

    for (var i = 0; i < days; i++) {
        var cell = maptable.at(firstdayIndex + i);

        var type = "";
        if (cell instanceof Module.NormalCell || cell instanceof Module.NormalCell || cell instanceof Module.NormalCell || cell instanceof Module.NormalCell)
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

        var cellElement = <HTMLDivElement>map.querySelector(`.cell${i + 1}`);
        if (type)
            cellElement.dataset["cellType"] = type;
        else
            cellElement.dataset["cellType"] = "";
        cellElement.style.display = "";
    }
    for (var i = days; i < 31; i++) {
        var cellElement = <HTMLDivElement>map.querySelector(`.cell${i + 1}`);
        cellElement.style.display = "none";
    }
}
