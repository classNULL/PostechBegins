#ifndef POSTECHBEGINS_MAPTABLE_H
#define POSTECHBEGINS_MAPTABLE_H

#include <vector>
#include "global.hpp"
#include "cell.hpp"
#include "monthday.hpp"

class MapTable {
private:
  MapTable() = default;
  vector<cell*> _map;
  static bool is_new_month(Month month, const vector<Month>& previous_list);
  bool is_proper_new_event_day(MonthDay monthday, const vector<Month>& previous_monthes);
  void install_events();
  void set_birthday();
public:
  static MapTable generate_default();
  void set_event(int i, int j);
  static MapTable generate(const std::vector<cell*>& map) {
    MapTable maptable;
    maptable._map = map;
    maptable.install_events();
    maptable.set_birthday();
    return maptable;
  }

  cell* at(int i) { return this->_map.at(i); }
  ~MapTable();

  int check_stop(int reference, int step);
  bool check_birth(int reference, int step);
};

#endif
