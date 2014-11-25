#include "gamecenter.hpp"

float GameCenter::calc_grade_score(float grade) {
  if (grade < 0)
    throw runtime_error("0보다 작으면 안됨");
  else if (grade < 2.0)
    return (grade) / 2 * 5;
  else if (grade < 2.3)
    return 20 + (grade - 2) / 0.3 * 10;
  else if (grade < 3.0)
    return 50 + (grade - 2.3) / 0.7 * 50;
  else if (grade < 3.3)
    return 200 + (grade - 3.0) / 0.3 * 20;
  else if (grade < 3.7)
    return 230 + (grade - 3.3) / 0.4 * 30;
  else if (grade < 4.0)
    return 280 + (grade - 3.7) / 0.3 * 30;
  else if (grade < 4.3)
    return 350 + (grade - 4.0) / 0.3 * 30;
  else if (grade == 4.3)
    return 400;
  else
    throw runtime_error("4.3보다 큼");
}

int GameCenter::score(float study, float relationship, float improvement) {
  //grade 400
  //relationship 300
  //improvement 300
  return calc_grade_score(generate_grade(study)) + (relationship * 300) + (improvement * 300);
}

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
