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
  template<typename T>
  static bool is_new(T month, const vector<T>& previous_list);
  bool is_proper_new_event_day(MonthDay monthday, const vector<Month>& previous_monthes, const vector<int>& previous_indices);
  void install_events();
  void set_birthday();
public:
  static MapTable generate_default();
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
  int check_skip(int reference);
  bool check_birth(int reference, int step);
};

template<typename T>
bool MapTable::is_new(T item, const vector<T>& previous_list) {
  for (const auto& previous: previous_list) {
    if (item == previous)
      return false;
  }

  return true;
}

#endif
