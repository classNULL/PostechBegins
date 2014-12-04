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
  // int date;
  // int check_num(char *);
  // void savefile();
  // void loadfile();
  // void put_ranking();
public:
  // /** 저장된 날짜를 리턴한다. */
  // int get_date() const { return this->date; };
  // /** 새 날짜를 저장한다. */
  // void set_date(int new_date) { this->date = new_date; }

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

public:
	void set_start_status();
	float get_energy_increase();
	float get_love_increase();
	float get_relationship_increase();
	float get_self_develop_increase();
	float get_study_increase();
private:
	float start_energy;
	float start_love;
	float start_relationship;
	float start_self_develop;
	float start_study;
};

#endif
