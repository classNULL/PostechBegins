#ifndef POSTECHBEGINS_SCORE_H
#define POSTECHBEGINS_SCORE_H

#include "global.hpp"
#include "hero.hpp"
#include <algorithm>

class hero;

struct Score {
private:
  Score() = default;
  /**
  학점에 따라 게임 결과 총점에 들어갈 점수를 계산한다.

  @param grade 학점. 0에서 4.3 사이.
  */
  static float calc_grade_score(float grade);
public:
  int grade_score;
  int relationship;
  int self_develop;

  /**
  공부 스탯에 따라 학점을 계산한다.
  학점은 스탯에 비례한 값에 +/-0.15 범위 안에서 결정된다.

  @param study 공부 스탯. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  */
  static float generate_grade(float study);
  /**
  학점 및 인간관계, 자기계발 스탯을 통해 총 점수를 결정한다.

  @param _hero 캐릭터. 캐릭터의 스탯을 통해 점수가 결정된다.
  @return 총 점수.
  */
  static Score score(const hero& _hero);

  int get_total() const { return this->grade_score + this->relationship + this->self_develop; }
  int get_grade_score() const { return this->grade_score; }
  int get_relationship() const { return this->relationship; }
  int get_self_develop() const { return this->self_develop; }
  wstring evaluate_total();
  wstring evaluate_grade_score();
  wstring evaluate_relationship();
  wstring evaluate_self_develop();
};

#endif
