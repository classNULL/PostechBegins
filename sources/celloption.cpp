#include "celloption.hpp"

cell_option::cell_option(wstring title, function<void()> changer) {
  this->_title = title;
  this->_silent_changer = changer;
}
cell_option::cell_option(wstring title, function<wstring()> changer) {
  this->_title = title;
  this->_tweeting_changer = changer;
  this->_has_result_message = true;
}
wstring cell_option::apply() {
  if (this->_applied)
    throw runtime_error("이미 적용한 옵션을 다시 적용하면 안 됩니다.");
  this->_applied = true;

  if (!this->_has_result_message) {
    this->_silent_changer();
    return L"";
  }
  else
    return this->_tweeting_changer();
}

cell_option_book::cell_option_book(const vector<cell_option>& options) {
  this->_options = options;
}
cell_option_book::cell_option_book(wstring title, const vector<cell_option>& options) {
  this->_book_title = title;
  this->_options = options;
}
cell_option* cell_option_book::at(int index) {
  return &(this->_options.at(index));
}
