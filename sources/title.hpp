#ifndef POSTECHBEGINS_TITLE_H
#define POSTECHBEGINS_TITLE_H

#include "global.hpp"
#include <map>
//칭호를 설정해주는 것에 대해서 설정을 하는 struct이다. 
struct TitleEffect {
public:
  PersonalStatus alcohol;
  PersonalStatus study;
  PersonalStatus circle;
  PersonalStatus love;
  PersonalStatus rest;
  PersonalStatus home;

  static TitleEffect get_base() {
    return {
      .alcohol = PersonalStatus::get_ones(),
      .study = PersonalStatus::get_ones(),
      .circle = PersonalStatus::get_ones(),
      .love = PersonalStatus::get_ones(),
      .rest = PersonalStatus::get_ones(),
      .home = PersonalStatus::get_ones()
    };
  }

  TitleEffect multiply(const TitleEffect& effect) {//칭호의 효과를 원래의 효과에 곱해서 실현될 수 있도록한다. 
    auto result = *this;

    result.alcohol = result.alcohol.multiply(effect.alcohol);
    result.study  = result.study.multiply(effect.study);
    result.circle = result.circle.multiply(effect.circle);
    result.love = result.love.multiply(effect.love);
    result.rest = result.rest.multiply(effect.rest);
    result.home = result.home.multiply(effect.home);

    return result;
  }
};

class TitleBook {//칭호를 설정하는데 필요한 기능들을 모두 모아놓은 class이다. 
private:
  map<string, TitleEffect> titles;
  TitleEffect total_title_effect = TitleEffect::get_base();
  void calc_total_title_effect();
public:
  bool has_title(string) const;
  void add_title(string);
  void remove_title(string);
  const TitleEffect get_total_title_effect() const {
    return this->total_title_effect;
  };
};

class Titles {//칭호가 어떤 역할을 하는지에 대해서 정의를 하는 class 이다. 
private:
  Titles() = delete;

  static TitleEffect outsider; // 아싸
  static TitleEffect alcoholic; // 술쟁이
  static TitleEffect circle_resident; // 동방충
  static TitleEffect nerd; // 공부벌레
  static TitleEffect couple; // 연애중
  static TitleEffect circle_independent; // 무동아리
  static TitleEffect weak; // 체력낮음
public:
  static const map<string, const TitleEffect&> map;
};

#endif
