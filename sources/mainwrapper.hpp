#ifndef POSTECHBEGINS_MAINWRAPPER_H
#define POSTECHBEGINS_MAINWRAPPER_H

#include "global.hpp"
#include "gamecenter.hpp"
#include "hero.hpp"

#ifndef EMBIND_H
#define EMBIND_H
#include <emscripten/bind.h>
#endif

using namespace emscripten;

class MainWrapper {
private:
  GameCenter center;

public:

};

EMSCRIPTEN_BINDINGS(PostechBegins_Main) {
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
}

#endif
