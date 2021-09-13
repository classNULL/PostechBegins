#ifndef POSTECHBEGINS_CELLOPTION_H
#define POSTECHBEGINS_CELLOPTION_H

#include <functional>

#include "global.hpp"
#include "hero.hpp"

class cell_option {
private:
  wstring _title; // "휴식" 등

  function<wstring()> _changer; // 스탯 바꾸는 부분
  bool _applied = false;
public:
  cell_option(wstring title, function<wstring()> changer);
  wstring apply();

  wstring title() const { return this->_title; }
  bool applied() const { return this->_applied; }
};

class cell_option_book {
private:
  wstring _book_title; // "에너지가 부족합니다" 하나에밖에 쓰이지 않네요
  vector<cell_option> _options;
public:
  cell_option_book() = default;
  cell_option_book(const vector<cell_option>& options);
  cell_option_book(wstring title, const vector<cell_option>& options);
  cell_option* at(int index); // 선택지 객체 주는 함수

  wstring book_title() const { return this->_book_title; }
  int size() const { return this->_options.size(); };
};

#endif
