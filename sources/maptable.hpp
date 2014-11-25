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
public:
  static MapTable generate_default();
  static MapTable generate(const std::vector<cell*>& map) {
    MapTable maptable;
    maptable._map = map;
    return maptable;
  }

  cell* at(int i) { return this->_map.at(i); }
  ~MapTable();

  int check_stop(int reference, int step);
};

#endif
