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
  hero* get_character_pointer() { return this->_character; }

private:
  MapTable _map = MapTable::generate_default();
  int _current_position = 2;
  GameCenter() = default;
public:
  const MapTable& get_map() const { return this->_map; }
  int get_current_position() const { return this->_current_position; }
  GameCenter(sexuality sex);
  GameCenter(const CharacterProperty& property, const vector<string>& titles, int position);

public:
  /** 1과 6 사이 숫자를 무작위로 리턴한다. */
  int dice() { return rand() % 6 + 1; }
  int move(int step);
  int pass_skips();

public:
	void record_current_status();
	PersonalStatus get_status_increase();
private:
  PersonalStatus recorded_status;
};

#endif
