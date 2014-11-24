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

        dateIndex: number;
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
    class GameCenter extends EmscriptenClass {
        constructor(sex: Sexuality);

        date: number;
        currentPosition: number;
        character: Hero;

        dice(): number;
        score(study: number, relationship: number, improvement: number): number;
        move(step: number): number;
    }
    class Hero extends EmscriptenClass {
        constructor(maxLove: number, maxEnergy: number, maxRelationship: number, maxSelfImprovement: number, maxStudy: number, sex: Sexuality);
        love: number;
        energy: number;
        relationship: number;
        selfImprovement: number;
        study: number;
        MAX_ENERGY: number;
        MAX_LOVE: number;
        MAX_RELATIONSHIP: number;
        MAX_SELFIMPROVEMENT: number;
    }
}
