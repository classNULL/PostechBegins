#ifndef POSTECHBEGINS_MONTHDAY_H
#define POSTECHBEGINS_MONTHDAY_H

#include <tuple>
#include "global.hpp"

enum Month {
  March = 3,
  April = 4,
  May = 5,
  June = 6,
  July = 7,
  August = 8,
  September = 9,
  October = 10,
  November = 11,
  December = 12
};

class MonthDay {
private:
  int _date_index;
  Month _month;
  int _day;

public:
  MonthDay() = default;
  static MonthDay from_index(int date_index);
  static MonthDay from_calendar(Month month, int day);
  static int containing_days(Month month);

  int get_index() const { return this->_date_index; }
  Month get_month() const { return this->_month; }
  int get_day() const { return this->_day; }
};

#endif
