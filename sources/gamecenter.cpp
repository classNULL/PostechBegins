#include "gamecenter.hpp"

#include <fstream>

GameCenter::GameCenter(sexuality sex) {
  if (sex == sexuality::man)
    this->_character = new hero({.energy = 100,
                                 .love = 100,
                                 .relationship = 100,
                                 .self_develop = 100,
                                 .study = 100,
                                 .stress = 100},
                                sex);
  else if (sex == sexuality::woman)  // woman
    this->_character = new hero({.energy = 80,
                                 .love = 100,
                                 .relationship = 80,
                                 .self_develop = 100,
                                 .study = 100,
                                 .stress = 100},
                                sex);
}

GameCenter::GameCenter(const CharacterProperty& property,
                       const vector<string>& titles, int position) {
  this->_character =
      new hero(property.max_status, property.status,
               property.gender == "male" ? sexuality::man : sexuality::woman);
  this->_current_position = position;

  for (const auto& item : titles) {
    this->_character->get_title_book_pointer()->add_title(item);
  }
}

int GameCenter::move(int step) {
  if (this->_map.check_birth(this->_current_position, step)) {
    _character->change_energy(8, 1);
    _character->change_stress(-5, 1);
  }

  int stop = this->_map.check_stop(this->_current_position, step);
  this->_current_position = stop;

  return stop;
}

int GameCenter::pass_skips() {
  int next = this->_map.check_skip(this->_current_position);
  this->_current_position = next;

  return next;
}

// int main() {
//   srand(time(NULL));
//   Manager manager;
//   // cout << "study 100 " <<  manager.generate_grade(100) << endl;
//   // cout << "study 0 " <<  manager.generate_grade(0) << endl;
//   // cout << "study 50 1 " <<  manager.generate_grade(50) << endl;
//   // cout << "study 50 2 " <<  manager.generate_grade(50) << endl;
//   cout << manager.score(manager.generate_grade(70), 0.3, 0.4) << endl;
//   cout << manager.score(manager.generate_grade(100), 1.0, 1.0) << endl;
//   cout << manager.score(manager.generate_grade(0), 0.0, 0.0) << endl;
//
//
// }

void GameCenter::record_current_status() {  //매 달 첫 날의 status 저장
  recorded_status = _character->status();
}
//현재의 status - 과거의 status
PersonalStatus GameCenter::get_status_increase() {
  return _character->status().minus(recorded_status);
}
