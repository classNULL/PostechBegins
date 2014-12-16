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
    .constructor<const CharacterProperty&, const vector<string>&, int>()
    .property("map", &GameCenter::get_map)
    .property("currentPosition", &GameCenter::get_current_position)
    .property("character", &GameCenter::get_character)
    .function("mutableCharacter", &GameCenter::get_character_pointer, allow_raw_pointers())
    .function("dice", &GameCenter::dice)
    .function("move", &GameCenter::move)
    .function("passSkips", &GameCenter::pass_skips)
    .function("recordCurrentStatus", &GameCenter::record_current_status)
    .function("getStatusIncrease", &GameCenter::get_status_increase);

  value_object<CharacterProperty>("CharacterProperty")
    .field("maxStatus", &CharacterProperty::max_status)
    .field("status", &CharacterProperty::status)
    .field("gender", &CharacterProperty::gender);

  class_<MapTable>("MapTable")
    .class_function("generate", &MapTable::generate)
    .class_function("generateDefault", &MapTable::generate_default)
    .property("size", &MapTable::size)
    .function("checkStop", &MapTable::check_stop)
    .function("at", &MapTable::at, allow_raw_pointers())
    .function("set", &MapTable::set, allow_raw_pointers());

  class_<cell>("Cell")
    .property("isStop", &cell::stop_cell)
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
  class_<win_vac, base<cell>>("WinterVacationCell");

  class_<festival, base<cell>>("FestivalCell");
  class_<poka, base<festival>>("PokaCell");
  class_<pop, base<festival>>("POPCell");

  class_<special, base<cell>>("SpecialCell");
  class_<bunban_lecstart, base<special>>("BunbanLectureStartPartyCell");
  class_<bunban_lecend, base<special>>("BunbanLectureEndPartyCell");
  class_<bunban_mt, base<special>>("BunbanMTCell");
  class_<bunban_face, base<special>>("BunbanFacePartyCell");
  class_<dept_lecstart, base<special>>("DepartmentLectureStartPartyCell");
  class_<dept_lecend, base<special>>("DepartmentLectureEndPartyCell");
  class_<dept_mt, base<special>>("DepartmentMtCell");
  class_<dept_face, base<special>>("DepartmentFacePartyCell");
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
    .property("sexuality", &hero::get_sexuality)
    .property("spring", &hero::is_spring)
    .property("status", &hero::status)
    .property("maxStatus", &hero::max_status)
    .property("titleBook", &hero::get_title_book)
    .property("mosol", &hero::is_mosol)
    .function("couple", &hero::couple)
    .function("mutableTitleBook", &hero::get_title_book_pointer, allow_raw_pointers())
    .function("getSemesterGrade", &hero::get_semester_grade)
    .function("getAverageGrade", &hero::get_average_grade)
    .function("takeExam", &hero::take_exam)
    .function("finishSemester", &hero::finish_semester)
    .function("getCurrentProperty", &hero::get_current_property);

  value_object<TitleEffect>("TitleEffect")
    .field("alcohol", &TitleEffect::alcohol)
    .field("study", &TitleEffect::study)
    .field("circle", &TitleEffect::circle)
    .field("love", &TitleEffect::love)
    .field("rest", &TitleEffect::rest)
    .field("home", &TitleEffect::home);

  class_<TitleBook>("TitleBook")
    .property("totalTitleEffect", &TitleBook::get_total_title_effect)
    .property("size", &TitleBook::size)
    .function("containingTitles", &TitleBook::containing_titles)
    .function("hasTitle", &TitleBook::has_title)
    .function("addTitle", &TitleBook::add_title)
    .function("removeTitle", &TitleBook::remove_title);

  class_<Score>("Score")
    .class_function("score", &Score::score)
    .property("total", &Score::get_total)
    .property("gradeScore", &Score::get_grade_score)
    .property("relationship", &Score::get_relationship)
    .property("selfImprovement", &Score::get_self_develop)
    .function("evaluateTotal", &Score::evaluate_total)
    .function("evaluateGradeScore", &Score::evaluate_grade_score)
    .function("evaluateRelationship", &Score::evaluate_relationship)
    .function("evaluateSelfImprovement", &Score::evaluate_self_develop);

  class_<month_event>("MonthEvent")
    .property("month", &month_event::get_month)
    .property("introduction", &month_event::introduction_message)
    .function("checkSuccess", &month_event::check_success, allow_raw_pointers());
  class_<march_event, base<month_event>>("MarchEvent").constructor();
  class_<april_event, base<month_event>>("AprilEvent").constructor();
  class_<may_event, base<month_event>>("MayEvent").constructor();
  class_<june_event, base<month_event>>("JuneEvent").constructor();
  class_<september_event, base<month_event>>("SeptemberEvent").constructor();
  class_<october_event, base<month_event>>("OctoberEvent").constructor();
  class_<november_event, base<month_event>>("NovemberEvent").constructor();
  class_<december_event, base<month_event>>("DecemberEvent").constructor();

  register_vector<string>("EmscriptenStringVector");
  // class_<vector<string>>("EmscriptenStringVector")
  //   .constructor()
  //   .function("at", select_overload<string&(unsigned int)>(&vector<string>::at))
  //   .function("insert", select_overload<vector<string>::iterator(vector<string>::const_iterator, const string&)>(&vector<string>::insert))
  //   .property("begin", &vector<string>::begin)
  //   .property("end", &vector<string>::end)
  //   .property("size", &vector<string>::size);
  // class_<vector<string>::iterator>("EmscriptenStringVectorIterator")
  //   .function("plus", &vector<string>::iterator::operator+);
}
