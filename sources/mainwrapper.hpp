#ifndef POSTECHBEGINS_MAINWRAPPER_H
#define POSTECHBEGINS_MAINWRAPPER_H

#include "global.hpp"
#include "gamecenter.hpp"
#include "hero.hpp"
#include "monthday.hpp"
#include "maptable.hpp"
#include "cell.hpp"
#include "celloption.hpp"
#include "event.hpp"
#include "score.hpp"

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

#endif
