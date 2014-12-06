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

  value_object<PersonalStatus>("PersonalStatus")
    .field("energy", &PersonalStatus::energy)
    .field("relationship", &PersonalStatus::relationship)
    .field("love", &PersonalStatus::love)
    .field("study", &PersonalStatus::study)
    .field("selfImprovement", &PersonalStatus::self_develop)
    .field("stress", &PersonalStatus::stress);

  class_<GameCenter>("GameCenter")
    .constructor<sexuality>()
    .property("map", &GameCenter::get_map)
    .property("currentPosition", &GameCenter::get_current_position)
    .property("character", &GameCenter::get_character)
    .function("mutableCharacter", &GameCenter::get_character_pointer, allow_raw_pointers())
    .function("dice", &GameCenter::dice)
    .function("move", &GameCenter::move)
    .function("passSkips", &GameCenter::pass_skips)
    .function("recordCurrentStatus", &GameCenter::record_current_status)
    .function("getStatusIncrease", &GameCenter::get_status_increase);

  class_<MapTable>("MapTable")
    .class_function("generate", &MapTable::generate)
    .class_function("generateDefault", &MapTable::generate_default)
    .function("checkStop", &MapTable::check_stop)
    .function("at", &MapTable::at, allow_raw_pointers());

  class_<cell>("Cell")
    .property("isStop", &cell::stop_cell)
    .property("cellName", &cell::get_cell_name)
    .property("cellMessage", &cell::get_cell_message)
    .function("callOption", &cell::call_option, allow_raw_pointers());
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
  class_<eve_1, base<special>>("Event1Cell");
  class_<eve_2, base<special>>("Event2Cell");
  class_<eve_3, base<special>>("Event3Cell");

  class_<cell_option>("CellOption")
    .property("title", &cell_option::title)
    .property("applied", &cell_option::applied)
    .function("apply", &cell_option::apply);

  class_<cell_option_book>("CellOptionBook")
    .property("bookTitle", &cell_option_book::book_title)
    .property("size", &cell_option_book::size)
    .function("at", &cell_option_book::at, allow_raw_pointers());

  class_<hero>("Hero")
    .constructor<PersonalStatus, sexuality>()
    .property("status", &hero::status)
    .property("maxStatus", &hero::max_status)
    .property("titleBook", &hero::get_title_book)
    .function("mutableTitleBook", &hero::get_title_book_pointer, allow_raw_pointers());

  value_object<TitleEffect>("TitleEffect")
    .field("alcohol", &TitleEffect::alcohol)
    .field("study", &TitleEffect::study)
    .field("circle", &TitleEffect::circle)
    .field("love", &TitleEffect::love)
    .field("rest", &TitleEffect::rest)
    .field("home", &TitleEffect::home);

  class_<TitleBook>("TitleBook")
    .property("totalTitleEffect", &TitleBook::get_total_title_effect)
    .function("hasTitle", &TitleBook::has_title)
    .function("addTitle", &TitleBook::add_title)
    .function("removeTitle", &TitleBook::remove_title);
}
