#include "gamecenter.hpp"


int GameCenter::move(int step){
  int stop = this->_map.check_stop(this->_current_position, step);
  this->_current_position = stop;
  return stop;
}

GameCenter::GameCenter(sexuality sex) {
  if (sex == sexuality::man)
    this->_character = new hero(100, 100, 100, 100, 100, sex);
  else if (sex == sexuality::woman) // woman
    this->_character = new hero(100, 80, 30, 30, 100, sex);
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
