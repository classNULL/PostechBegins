declare module Module {
    class EmscriptenClass {
        delete(): void;
    }
    interface EmscriptenEnum {
        value: number;
    }
}

declare module Module {
    function srand(seed: number): void;
    class MonthDay extends EmscriptenClass {
        static fromIndex(dateIndex: number): MonthDay;
        static fromCalendar(month: Month, day: number): MonthDay;
        static containingDays(month: Month): number;

        index: number;
        month: Month;
        day: number;
    }
    interface Month extends EmscriptenEnum {
    }
    module Month {
        var March: Month;
        var April: Month;
        var May: Month;
        var June: Month;
        var July: Month;
        var August: Month;
        var September: Month;
        var October: Month;
        var November: Month;
        var December: Month;
    }
    interface Sexuality extends EmscriptenEnum {
    }
    module Sexuality {
        var Man: Sexuality;
        var Woman: Sexuality;
    }
    interface PersonalStatus {
        energy: number;
        relationship: number;
        love: number;
        study: number;
        selfImprovement: number;
        stress: number;
    }

    class GameCenter extends EmscriptenClass {
        constructor(sex: Sexuality);

        date: number;
        currentPosition: number;
        character: Hero;
        map: MapTable;

        mutableCharacter(): Hero;
        dice(): number;
        move(step: number): number;
        passSkips(): number;
    }

    class MapTable extends EmscriptenClass {
        at(index: number): Cell;
    }

    class Cell extends EmscriptenClass {
        isStop: boolean;
        cellName: string;
        cellMessage: string;
        callOption(hero: Hero, day: number): CellOptionBook;        
    }
    class NormalCell extends Cell { }
    class WeekendCell extends Cell { }
    class MarchCell extends Cell { }
    class BeforeExamCell extends Cell { }
    class ExamCell extends Cell { }
    class AfterExamCell extends Cell { }
    class DanceCell extends Cell { }

    class FestivalCell extends Cell { }
    class PokaCell extends FestivalCell { }
    class POPCell extends FestivalCell { }

    class SpecialCell extends Cell { }
    class LectureStartPartyCell extends SpecialCell { }
    class LectureEndPartyCell extends SpecialCell { }
    class MTCell extends SpecialCell { }
    class FacePartyCell extends SpecialCell { }
    class Event1Cell extends SpecialCell { }
    class Event2Cell extends SpecialCell { }
    class Event3Cell extends SpecialCell { }

    class CellOption extends EmscriptenClass {
        title: string;
        applied: boolean;
        apply(): string;
    }
    class CellOptionBook extends EmscriptenClass {
        bookTitle: string;
        size: number;
        at(index: number): CellOption;
    }

    class Hero extends EmscriptenClass {
        constructor(maxStatus: PersonalStatus, sex: Sexuality);
        status: PersonalStatus;
        maxStatus: PersonalStatus;
    }
}
