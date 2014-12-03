#include "mainwrapper.hpp"

EMSCRIPTEN_BINDINGS(PostechBegins_Main) {
  emscripten::function("srand", &srand);
  class_<MonthDay>("MonthDay")
    .property("index", &MonthDay::get_index)
    .property("month", &MonthDay::get_month)
    .property("day", &MonthDay::get_day)
    .class_function("fromIndex", &MonthDay::from_index)
    .class_function("fromCalendar", &MonthDay::from_calendar)
    .class_function("containingDays", &MonthDay::containing_days);
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
    .property("map", &GameCenter::get_map)
    .property("currentPosition", &GameCenter::get_current_position)
    .property("character", &GameCenter::get_character)
    .function("dice", &GameCenter::dice)
    .function("move", &GameCenter::move);

  class_<MapTable>("MapTable")
    .class_function("generate", &MapTable::generate)
    .class_function("generateDefault", &MapTable::generate_default)
    .function("checkStop", &MapTable::check_stop)
    .function("at", &MapTable::at, allow_raw_pointers());

  class_<cell>("Cell")
    .property("isStop", &cell::stop_cell);
  class_<normal, base<cell>>("NormalCell");
  class_<weekend, base<cell>>("WeekendCell");
  class_<march, base<cell>>("MarchCell");
  class_<before_exam, base<cell>>("BeforeExamCell");
  class_<exam, base<cell>>("ExamCell");
  class_<after_exam, base<cell>>("AfterExamCell");
  class_<dance, base<cell>>("DanceCell");
  class_<vacation, base<cell>>("VacationCell");

  class_<festival, base<cell>>("FestivalCell");
  class_<poka, base<festival>>("PokaCell");
  class_<pop, base<festival>>("POPCell");

  class_<special, base<cell>>("SpecialCell");
  class_<lecstartparty, base<special>>("LectureStartPartyCell");
  class_<lecendparty, base<special>>("LectureEndPartyCell");
  class_<mt, base<special>>("MTCell");
  class_<faceparty, base<special>>("FacePartyCell");

  class_<hero>("Hero")
    .constructor<float, float, float, float, float, float, sexuality>()
    .property("love", &hero::get_love)
    .property("energy", &hero::get_energy)
    .property("relationship", &hero::get_relationship)
    .property("selfImprovement", &hero::get_self_develop)
    .property("study", &hero::get_study)
    .property("stress", &hero::get_stress)
    .property("MAX_ENERGY", &hero::get_MAX_ENERGY)
    .property("MAX_LOVE", &hero::get_MAX_LOVE)
    .property("MAX_RELATIONSHIP", &hero::get_MAX_RELATIONSHIP)
    .property("MAX_SELFIMPROVEMENT", &hero::get_MAX_SELF_DEVELOP);
}
