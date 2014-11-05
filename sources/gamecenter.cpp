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


int GameCenter::move(int step){//board에서 구현되어야하는 함수로, 주사위의 굴려진 값에따라 이동해야 하는 칸의 위치를 return한다.
  //인자로는 현재 캐릭터의 위치(예를 들어 3일), 주사위를 굴려서 나온 숫자, 그리고 현재 달에 해당하는 cell 배열을 가리키는 cell pointer를 받는다(예를들어 march, november등 월에 해당하는 cell array가 될것)
  int max = this->_current_position + step;
  for(int i = this->_current_position + 1; i <= max; i++) {
  	//만약 현재가 3일에 위치해 있는데 주사위를 굴려 5가 나왔다고 가정하자.
    //이때, 7일이 특수칸일 경우 캐릭터는 8일이 아니라 7일에서 멈추어야 하므로,
    //그 사이에 stop정보가 true인 값이 있는지를 파악하여야 한다.
    if(this->_map.at(i)->stop_cell() == true) {
      this->_current_position = i;
      return i;
    }
  }
  this->_current_position = max;
  return max;
}

GameCenter::GameCenter(sexuality sex): _character(sex) {
  this->_map.at(4) = new festival();
  for (auto& item: this->_map) {
    if (item == NULL)
      item = new normal();
  }
}

GameCenter::~GameCenter() {
  for (const auto& item: this->_map) {
    if (item != NULL)
      delete item;
  }
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
