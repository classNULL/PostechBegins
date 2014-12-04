#include "celloption.hpp"

cell_option::cell_option(string title, function<void()> changer) {
  this->_title = title;
  this->_silent_changer = changer;
}
cell_option::cell_option(string title, function<string()> changer) {
  this->_title = title;
  this->_tweeting_changer = changer;
  this->_has_result_message = true;
}
string cell_option::apply() {
  if (this->_applied)
    throw runtime_error("이미 적용한 옵션을 다시 적용하면 안 됩니다.");
  this->_applied = true;

  if (!this->_has_result_message)
    return this->_silent_changer();
  else
    return this->_tweeting_changer();
}

cell_option_book::cell_option_book(const vector<cell_option>& options) {
  this->_options = options;
}
cell_option_book::cell_option_book(string title, const vector<cell_option>& options) {
  this->_book_title = title;
  this->_options = options;
}
cell_option* cell_option_book::at(int index) {
  return &(this->_options.at(index));
}
