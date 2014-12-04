#include "celloption.hpp"

cell_option::cell_option(string title, function<string()> changer) {
  this->_title = title;
  this->_changer = changer;
}
string cell_option::apply() {
  if (this->_applied)
    throw runtime_error("이미 적용한 옵션을 다시 적용하면 안 됩니다.");

  return this->_changer();
}

cell_option_book::cell_option_book(string title, const vector<cell_option>& options) {
  this->_book_title = title;
  this->_options = options;
}
cell_option* cell_option_book::at(int index) {
  return &(this->_options.at(index));
}
