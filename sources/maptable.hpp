#ifndef POSTECHBEGINS_MAPTABLE_H
#define POSTECHBEGINS_MAPTABLE_H

#include <vector>
#include "global.hpp"
#include "cell.hpp"
#include "monthday.hpp"

class MapTable {
private:
  MapTable() = default;
  bool check;//랜덤 이벤트 설정할 지 안할지 저장
  vector<cell*> _map;
  static bool is_new_month(Month month, vector<Month> previous_list);
  bool is_proper_new_event_day(MonthDay monthday, vector<Month> previous_monthes);
  void install_events();
  void set_birthday();
  int event_arr[3];//save information of each event
public:
  static MapTable generate_default();
  static MapTable generate(const std::vector<cell*>& map) {
    MapTable maptable;
    maptable._map = map;
    maptable.install_events(bool);
    maptable.set_birthday();
    int get_event(int i);
    void set_check(bool);
    void set_cell(cell*,int);
    return maptable;
  }

  cell* at(int i) { return this->_map.at(i); }
  ~MapTable();

  int check_stop(int reference, int step);
  bool check_birth(int reference, int step);
};

#endif
