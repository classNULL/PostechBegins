#ifndef POSTECHBEGINS_GAMECENTER_H
#define POSTECHBEGINS_GAMECENTER_H

#include "global.hpp"
#include "hero.hpp"
#include "cell.hpp"
#include "maptable.hpp"
#include <array>
#include <algorithm>

class GameCenter {
private:
  int date;
public:
  /** 저장된 날짜를 리턴한다. */
  int get_date() const { return this->date; };
  /** 새 날짜를 저장한다. */
  void set_date(int new_date) { this->date = new_date; }

private:
  hero* _character;
public:
  const hero& get_character() const { return *this->_character; }

private:
  MapTable _map = MapTable::generate_default();
  int _current_position = 0;
public:
  const MapTable& get_map() const { return this->_map; }
  int get_current_position() const { return this->_current_position; }
  GameCenter(sexuality sex);

public:
  /** 1과 6 사이 숫자를 무작위로 리턴한다. */
  int dice() { return rand() % 6 + 1; }
  int move(int step);

private:
  /**
  학점에 따라 게임 결과 총점에 들어갈 점수를 계산한다.

  @param grade 학점. 0에서 4.3 사이.
  */
  float calc_grade_score(float grade);

  /**
  공부 스탯에 따라 학점을 계산한다.
  학점은 스탯에 비례한 값에 +/-0.15 범위 안에서 결정된다.

  @param study 공부 스탯. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  */
  float generate_grade(float study) {
    return max(min(study * 4.3 + ((rand() % 30 - 15) / 100.0f), 4.3), 0.0);
  }
public:
  /**
  학점, 인간관계, 자기계발 스탯을 통해 총 점수를 결정한다.

  @param study 공부 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  @param relationship 인간관계 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  @param improvement 자기계발 점수. 만점에서 나눈 값을 받는다. 0에서 1 사이.
  @return 총 점수.
  */
  int score(float study, float relationship, float improvement);
};

#endif
