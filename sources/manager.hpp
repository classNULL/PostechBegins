#ifndef POSTECHBEGINS_MANAGER_H
#define POSTECHBEGINS_MANAGER_H

#include "global.hpp"
#include <array>
#include <cstdlib>
#include <algorithm>

class Manager {
private:
  array<int, 2> date;
  float calc_grade_score(float grade);
public:
  /** 저장된 날짜를 리턴한다. */
  array<int, 2> get_date();

  /** 새 날짜를 저장한다. */
  void set_date(const array<int, 2>& new_date) { date = new_date; }

  /** 1과 6 사이 숫자를 무작위로 리턴한다. */
  int dice() { return rand() % 6 + 1; }

  /**
  공부 스탯에 따라 학점을 계산한다.
  학점은 스탯에 비례한 값에 +/-0.15 범위 안에서 결정된다.

  @param study 공부 스탯. 0에서 100 사이.
  */
  float generate_grade(int study) {
    return max(min(study / 100.0f * 4.3 + ((rand() % 30 - 15) / 100.0f), 4.3), 0.0);
  }

  /**
  학점, 인간관계, 자기계발 스탯을 통해 총 점수를 결정한다.

  @param grade 학점. 0에서 4.3 사이.
  @param relationship 인간관계 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  @param improvement 자기계발 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  @return 총 점수.
  */
  int score(float grade, float relationship, float improvement);
};

#endif
