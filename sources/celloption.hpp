#ifndef POSTECHBEGINS_CELLOPTION_H
#define POSTECHBEGINS_CELLOPTION_H

#include "global.hpp"
#include "hero.hpp"

class cell_option {
private:
  string _title; // "휴식" 등
  function<string()> _changer; // 스탯 바꾸는 부분
  bool _applied;
public:
  cell_option(string title, function<string()> changer); // 생성자
  string apply();

  string title() { return this->_title; }
  bool applied() { return this->_applied; }
};

class cell_option_book {
private:
  string _book_title; // "에너지가 부족합니다" 하나에밖에 쓰이지 않네요
  vector<cell_option> _options;
public:
  cell_option_book(string title, const vector<cell_option>& options);
  cell_option* at(int index); // 선택지 객체 주는 함수

  string book_title() { return this->_book_title; }
  int size() { return this->_options.size(); };
};

#endif
