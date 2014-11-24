#include "mainwrapper.hpp"

EMSCRIPTEN_BINDINGS(PostechBegins_Main) {
  emscripten::function("srand", &srand);
  class_<MonthDay>("MonthDay")
    .property("index", &MonthDay::get_index)
    .property("month", &MonthDay::get_month)
    .property("day", &MonthDay::get_day)
    .class_function("fromIndex", &MonthDay::from_index)
    .class_function("fromCalendar", &MonthDay::from_calendar);
  enum_<Month>("Month")
    .value("March", Month::March)
    .value("April", Month::April)
    .value("May", Month::May)
    .value("June", Month::June)
    .value("July", Month::July)
    .value("August", Month::August)
    .value("September", Month::September)
    .value("October", Month::October)
    .value("November", Month::November)
    .value("December", Month::December);
  enum_<sexuality>("Sexuality")
    .value("Man", sexuality::man)
    .value("Woman", sexuality::woman);
  class_<GameCenter>("GameCenter")
    .constructor<sexuality>()
    .property("date", &GameCenter::get_date, &GameCenter::set_date)
    .property("currentPosition", &GameCenter::get_current_position)
    .property("character", &GameCenter::get_character)
    .function("dice", &GameCenter::dice)
    .function("score", &GameCenter::score)
    .function("move", &GameCenter::move);
  class_<MapTable>("MapTable")
    .function("generate", &MapTable::generate)
    .function("at", &MapTable::at);
  class_<hero>("Hero")
    .constructor<float, float, float, float, float, sexuality>()
    .property("love", &hero::get_love)
    .property("energy", &hero::get_energy)
    .property("relationship", &hero::get_relationship)
    .property("selfImprovement", &hero::get_self_develop)
    .property("study", &hero::get_study)
    .property("MAX_ENERGY", &hero::get_MAX_ENERGY)
    .property("MAX_LOVE", &hero::get_MAX_LOVE)
    .property("MAX_RELATIONSHIP", &hero::get_MAX_RELATIONSHIP)
    .property("MAX_SELFIMPROVEMENT", &hero::get_MAX_SELF_DEVELOP);
}
