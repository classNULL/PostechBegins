#ifndef POSTECHBEGINS_SCORE_H
#define POSTECHBEGINS_SCORE_H

#include "global.hpp"
#include "hero.hpp"
#include <algorithm>

class hero;

struct Score {
  //점수 계산에 대한 계산을 담당하는 struct이다. 각 점수의 정보를 변환하고 합산하는 등의 역할을 한다.
private:
  Score() = default;
  static float calc_grade_score(float grade);
  //게임에서 받은 학점을 총점 합산에 넣을 수 있는 점수로 변환해준다.
public:
  int grade_score;
  int relationship;
  int self_develop;
  int love;

  static float generate_grade(float study);
  //게임에서 받은 공부 스탯에 따라 학점을 계산한다. 이때 학점에는 운이 어느 정도 따라야하므로, 학점은 변환 점수에 +/-0.15 범위 안에서 결정된다.

  static Score score(const hero& _hero);
  //학점 및 인간관계, 자기계발 스탯을 통해 총 점수를 결정한다.

  int get_total() const { return this->grade_score + this->relationship + this->self_develop + this->love; }
  int get_grade_score() const { return this->grade_score; }
  int get_relationship() const { return this->relationship; }
  int get_self_develop() const { return this->self_develop; }
  wstring evaluate_total();
  wstring evaluate_grade_score();
  //학점에 대한 점수를 평가하여 그에 대한 메세지를 출력한다.
  wstring evaluate_relationship();
  //인간관계에 대한 점수를 평가하여 그에 대한 메세지를 출력한다.
  wstring evaluate_self_develop();
  //자기계발에 대한 평가를 하여 이에 대한 메세지를 출력한다.
};

#endif
