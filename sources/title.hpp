#ifndef POSTECHBEGINS_TITLE_H
#define POSTECHBEGINS_TITLE_H

#include "global.hpp"

struct TitleEffect {
  PersonalStatus alcohol;
  PersonalStatus study;
  PersonalStatus circle;
  PersonalStatus love;
  PersonalStatus rest;
  PersonalStatus home;
}

class Titles {
public:
  Titles() = delete;

  static const TitleEffect outsider = { // 아싸
    .alcohol = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .study = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .circle = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .love = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .rest = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
  };
  static const TitleEffect alcoholic = { // 술쟁이
    .alcohol = { .energy = 1, .relationship = 1.1, .love = 1, .study = 1, .self_develop = -1, .stress = 1 },
    .study = { .energy = 1, .relationship = 1, .love = 1, .study = 0.9, .self_develop = 1, .stress = 1 },
    .circle = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .love = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .rest = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
  };
  static const TitleEffect circle_resident = { // 동방충
    .alcohol = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .study = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .circle = { .energy = 1, .relationship = 1.05, .love = 1, .study = 1, .self_develop = 1, .stress = 1.05 },
    .love = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .rest = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
  };
  static const TitleEffect nerd = { // 공부벌레
    .alcohol = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
    .study = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
    .circle = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
    .love = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
    .rest = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 },
    .home = { .energy = 1, .relationship = 0.95, .love = 1, .study = 1.1, .self_develop = 1, .stress = 0.95 }
  };
  static const TitleEffect couple = { // 연애중
    .alcohol = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
    .study = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
    .circle = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
    .love = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
    .rest = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 },
    .home = { .energy = 1.1, .relationship = 0.9, .love = 1, .study = 0.9, .self_develop = 0, .stress = 0.9 }
  };
  static const TitleEffect circle_independent = { // 무동아리
    .alcohol = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .study = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .circle = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .love = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .rest = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .home = { .energy = 1, .relationship = 0.9, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
  };
  static const TitleEffect weak = { // 체력낮음
    .alcohol = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .study = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .circle = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .love = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 },
    .rest = { .energy = 1.1, .relationship = 1.1, .love = 1.1, .study = 1.1, .self_develop = 1.1, .stress = 1.1 },
    .home = { .energy = 1, .relationship = 1, .love = 1, .study = 1, .self_develop = 1, .stress = 1 }
  };
}

#endif
