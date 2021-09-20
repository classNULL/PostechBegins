#include "maptable.hpp"

MapTable::~MapTable() {
  for (const auto& cellp: this->_map) {
    if (cellp != NULL)
      delete cellp;
  }
}

int MapTable::check_stop(int reference, int step) {//board에서 구현되어야하는 함수로, 주사위의 굴려진 값에따라 이동해야 하는 칸의 위치를 return한다.
  //인자로는 현재 캐릭터의 위치(예를 들어 3일), 주사위를 굴려서 나온 숫자, 그리고 현재 달에 해당하는 cell 배열을 가리키는 cell pointer를 받는다(예를들어 march, november등 월에 해당하는 cell array가 될것)
  int max = reference + step;
  for(int i = reference + 1; i <= max; i++) {
    //만약 현재가 3일에 위치해 있는데 주사위를 굴려 5가 나왔다고 가정하자.
    //이때, 7일이 특수칸일 경우 캐릭터는 8일이 아니라 7일에서 멈추어야 하므로,
    //그 사이에 stop정보가 true인 값이 있는지를 파악하여야 한다.
    if(this->at(i)->stop_cell() == true)
      return i;
  }
  return max;
}

static bool has_same_type(const cell& cell1, const cell& cell2) {
  return typeid(cell1) == typeid(cell2);
}

int MapTable::check_skip(int reference){
  int next = reference;
  while(this->at(next)->skip_cell() == true && has_same_type(*(this->at(reference)), *(this->at(next)))) {
    next += 1;
  }
  return next;
}

bool MapTable::check_birth(int reference, int step) {
    int max = reference + step;
    for(int i = reference + 1; i <= max; i++) {
        if(this->at(i)->birth_cell() == true)
            return true;
    }
    return false;
}

bool MapTable::is_proper_new_event_day(MonthDay monthday, const vector<Month>& previous_monthes, const vector<int>& previous_indices) {
  clog << "Checking: " << monthday.get_index() << endl;
  auto* cell = this->at(monthday.get_index());
  if (cell == NULL || typeid(*cell)!= typeid(normal))
    return false;

  clog << "Passing: " << monthday.get_index() << endl;
  return MapTable::is_new(monthday.get_month(), previous_monthes) && MapTable::is_new(monthday.get_index(), previous_indices);
}

void MapTable::install_events() {
  vector<int> indices;
  vector<Month> monthes;

  for (int i = 0; i < 3; i++) {
    int index;
    MonthDay monthday;
    do {
      index = rand() % this->_map.size();
      monthday = MonthDay::from_index(index);

    } while (!this->is_proper_new_event_day(monthday, monthes, indices));

    indices.push_back(index);
    monthes.push_back(monthday.get_month());

    delete this->at(index);
    this->_map.at(index) = NULL;
  }

  this->_map.at(indices.at(0)) = new eve_1;
  this->_map.at(indices.at(1)) = new eve_2;
  this->_map.at(indices.at(2)) = new eve_3;
}

void MapTable::set(int index, cell* input){
		this->_map.at(index) = input;
}

void MapTable::set_birthday() {
  int birthday = rand() % this->_map.size();
  this->_map.at(birthday)->set_birth(true);
}

MapTable MapTable::generate_default(bool random_event) {
  MapTable maptable;
  auto& array = maptable._map = vector<cell*>(306);
  array[MonthDay::from_calendar(March, 1).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 2).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 3).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 4).get_index()] = new march;
  array[MonthDay::from_calendar(March, 5).get_index()] = new bunban_lecstart;    //lecstartparty 개총. 후에 special을 상속.
  array[MonthDay::from_calendar(March, 6).get_index()] = new march;
  array[MonthDay::from_calendar(March, 7).get_index()] = new dept_lecstart;
  array[MonthDay::from_calendar(March, 8).get_index()] = new march;
  array[MonthDay::from_calendar(March, 9).get_index()] = new bunban_mt;       //mt 엠티, special을 상속.
  array[MonthDay::from_calendar(March, 10).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 11).get_index()] = new bunban_face;   //faceparty 대면식, special을 상속.
  array[MonthDay::from_calendar(March, 12).get_index()] = new march;
  array[MonthDay::from_calendar(March, 13).get_index()] = new march;
  array[MonthDay::from_calendar(March, 14).get_index()] = new dept_face;
  array[MonthDay::from_calendar(March, 15).get_index()] = new march;
  array[MonthDay::from_calendar(March, 16).get_index()] = new dept_mt;
  array[MonthDay::from_calendar(March, 17).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 18).get_index()] = new march;
  array[MonthDay::from_calendar(March, 19).get_index()] = new bunban_face;
  array[MonthDay::from_calendar(March, 20).get_index()] = new march;
  array[MonthDay::from_calendar(March, 21).get_index()] = new dept_face;
  array[MonthDay::from_calendar(March, 22).get_index()] = new march;
  array[MonthDay::from_calendar(March, 23).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 24).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 25).get_index()] = new march;
  array[MonthDay::from_calendar(March, 26).get_index()] = new march;
  array[MonthDay::from_calendar(March, 27).get_index()] = new march;
  array[MonthDay::from_calendar(March, 28).get_index()] = new march;
  array[MonthDay::from_calendar(March, 29).get_index()] = new march;
  array[MonthDay::from_calendar(March, 30).get_index()] = new weekend;
  array[MonthDay::from_calendar(March, 31).get_index()] = new weekend;

  array[MonthDay::from_calendar(April, 1).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 2).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 3).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 4).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 5).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 6).get_index()] = new weekend;
  array[MonthDay::from_calendar(April, 7).get_index()] = new weekend;
  array[MonthDay::from_calendar(April, 8).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 9).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 10).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 11).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 12).get_index()] = new normal;
  array[MonthDay::from_calendar(April, 13).get_index()] = new weekend;
  array[MonthDay::from_calendar(April, 14).get_index()] = new weekend;
  array[MonthDay::from_calendar(April, 15).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 16).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 17).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 18).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 19).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 20).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 21).get_index()] = new before_exam;
  array[MonthDay::from_calendar(April, 22).get_index()] = new exam;
  array[MonthDay::from_calendar(April, 23).get_index()] = new exam;
  array[MonthDay::from_calendar(April, 24).get_index()] = new exam;
  array[MonthDay::from_calendar(April, 25).get_index()] = new exam;
  array[MonthDay::from_calendar(April, 26).get_index()] = new exam;
  array[MonthDay::from_calendar(April, 27).get_index()] = new weekend;
  array[MonthDay::from_calendar(April, 28).get_index()] = new weekend;
  array[MonthDay::from_calendar(April, 29).get_index()] = new after_exam;
  array[MonthDay::from_calendar(April, 30).get_index()] = new after_exam;

  array[MonthDay::from_calendar(May, 1).get_index()] = new after_exam;
  array[MonthDay::from_calendar(May, 2).get_index()] = new after_exam;
  array[MonthDay::from_calendar(May, 3).get_index()] = new after_exam;
  array[MonthDay::from_calendar(May, 4).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 5).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 6).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 7).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 8).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 9).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 10).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 11).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 12).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 13).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 14).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 15).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 16).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 17).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 18).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 19).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 20).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 21).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 22).get_index()] = new dance;
  array[MonthDay::from_calendar(May, 23).get_index()] = new festival;
  array[MonthDay::from_calendar(May, 24).get_index()] = new festival;
  array[MonthDay::from_calendar(May, 25).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 26).get_index()] = new weekend;
  array[MonthDay::from_calendar(May, 27).get_index()] = new normal;
  array[MonthDay::from_calendar(May, 28).get_index()] = new normal;
  array[MonthDay::from_calendar(May, 29).get_index()] = new normal;
  array[MonthDay::from_calendar(May, 30).get_index()] = new normal;
  array[MonthDay::from_calendar(May, 31).get_index()] = new normal;

  array[MonthDay::from_calendar(June, 1).get_index()] = new weekend;
  array[MonthDay::from_calendar(June, 2).get_index()] = new weekend;
  array[MonthDay::from_calendar(June, 3).get_index()] = new bunban_lecend;     //lecendparty 종강
  array[MonthDay::from_calendar(June, 4).get_index()] = new normal;
  array[MonthDay::from_calendar(June, 5).get_index()] = new dept_lecend;
  array[MonthDay::from_calendar(June, 6).get_index()] = new weekend;
  array[MonthDay::from_calendar(June, 7).get_index()] = new normal;
  array[MonthDay::from_calendar(June, 8).get_index()] = new weekend;
  array[MonthDay::from_calendar(June, 9).get_index()] = new weekend;
  array[MonthDay::from_calendar(June, 10).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 11).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 12).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 13).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 14).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 15).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 16).get_index()] = new before_exam;
  array[MonthDay::from_calendar(June, 17).get_index()] = new exam;
  array[MonthDay::from_calendar(June, 18).get_index()] = new exam;
  array[MonthDay::from_calendar(June, 19).get_index()] = new exam;
  array[MonthDay::from_calendar(June, 20).get_index()] = new exam;
  array[MonthDay::from_calendar(June, 21).get_index()] = new exam;
  array[MonthDay::from_calendar(June, 22).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 23).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 24).get_index()] = new vacation;   //방학 vacation, 한꺼번에 다 넘기기.
  array[MonthDay::from_calendar(June, 25).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 26).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 27).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 28).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 29).get_index()] = new vacation;
  array[MonthDay::from_calendar(June, 30).get_index()] = new vacation;

  array[MonthDay::from_calendar(July, 1).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 2).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 3).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 4).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 5).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 6).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 7).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 8).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 9).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 10).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 11).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 12).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 13).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 14).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 15).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 16).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 17).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 18).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 19).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 20).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 21).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 22).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 23).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 24).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 25).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 26).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 27).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 28).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 29).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 30).get_index()] = new vacation;
  array[MonthDay::from_calendar(July, 31).get_index()] = new vacation;

  array[MonthDay::from_calendar(August, 1).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 2).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 3).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 4).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 5).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 6).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 7).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 8).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 9).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 10).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 11).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 12).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 13).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 14).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 15).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 16).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 17).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 18).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 19).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 20).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 21).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 22).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 23).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 24).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 25).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 26).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 27).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 28).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 29).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 30).get_index()] = new vacation;
  array[MonthDay::from_calendar(August, 31).get_index()] = new vacation;

  array[MonthDay::from_calendar(September, 1).get_index()] = new vacation;
  array[MonthDay::from_calendar(September, 2).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 3).get_index()] = new bunban_lecstart;
  array[MonthDay::from_calendar(September, 4).get_index()] = new dept_lecstart;
  array[MonthDay::from_calendar(September, 5).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 6).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 7).get_index()] = new bunban_mt;
  array[MonthDay::from_calendar(September, 8).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 9).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 10).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 11).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 12).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 13).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 14).get_index()] = new dept_mt;
  array[MonthDay::from_calendar(September, 15).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 16).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 17).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 18).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 19).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 20).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 21).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 22).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 23).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 24).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 25).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 26).get_index()] = new normal;
  array[MonthDay::from_calendar(September, 27).get_index()] = new poka;    //poka 포카전, festival을 상속.
  array[MonthDay::from_calendar(September, 28).get_index()] = new poka;
  array[MonthDay::from_calendar(September, 29).get_index()] = new weekend;
  array[MonthDay::from_calendar(September, 30).get_index()] = new normal;

  array[MonthDay::from_calendar(October, 1).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 2).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 3).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 4).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 5).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 6).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 7).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 8).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 9).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 10).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 11).get_index()] = new normal;
  array[MonthDay::from_calendar(October, 12).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 13).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 14).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 15).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 16).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 17).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 18).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 19).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 20).get_index()] = new before_exam;
  array[MonthDay::from_calendar(October, 21).get_index()] = new exam;
  array[MonthDay::from_calendar(October, 22).get_index()] = new exam;
  array[MonthDay::from_calendar(October, 23).get_index()] = new exam;
  array[MonthDay::from_calendar(October, 24).get_index()] = new exam;
  array[MonthDay::from_calendar(October, 25).get_index()] = new exam;
  array[MonthDay::from_calendar(October, 26).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 27).get_index()] = new weekend;
  array[MonthDay::from_calendar(October, 28).get_index()] = new after_exam;
  array[MonthDay::from_calendar(October, 29).get_index()] = new after_exam;
  array[MonthDay::from_calendar(October, 30).get_index()] = new after_exam;
  array[MonthDay::from_calendar(October, 31).get_index()] = new after_exam;

  array[MonthDay::from_calendar(November, 1).get_index()] = new after_exam;
  array[MonthDay::from_calendar(November, 2).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 3).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 4).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 5).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 6).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 7).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 8).get_index()] = new pop;     //pop 피오피, special을 상속.
  array[MonthDay::from_calendar(November, 9).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 10).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 11).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 12).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 13).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 14).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 15).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 16).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 17).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 18).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 19).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 20).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 21).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 22).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 23).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 24).get_index()] = new weekend;
  array[MonthDay::from_calendar(November, 25).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 26).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 27).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 28).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 29).get_index()] = new normal;
  array[MonthDay::from_calendar(November, 30).get_index()] = new weekend;

  array[MonthDay::from_calendar(December, 1).get_index()] = new weekend;
  array[MonthDay::from_calendar(December, 2).get_index()] = new bunban_lecend;
  array[MonthDay::from_calendar(December, 3).get_index()] = new weekend;
  array[MonthDay::from_calendar(December, 4).get_index()] = new normal;
  array[MonthDay::from_calendar(December, 5).get_index()] = new dept_lecend;
  array[MonthDay::from_calendar(December, 6).get_index()] = new normal;
  array[MonthDay::from_calendar(December, 7).get_index()] = new weekend;
  array[MonthDay::from_calendar(December, 8).get_index()] = new weekend;
  array[MonthDay::from_calendar(December, 9).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 10).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 11).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 12).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 13).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 14).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 15).get_index()] = new before_exam;
  array[MonthDay::from_calendar(December, 16).get_index()] = new exam;
  array[MonthDay::from_calendar(December, 17).get_index()] = new exam;
  array[MonthDay::from_calendar(December, 18).get_index()] = new exam;
  array[MonthDay::from_calendar(December, 19).get_index()] = new exam;
  array[MonthDay::from_calendar(December, 20).get_index()] = new exam;
  array[MonthDay::from_calendar(December, 21).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 22).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 23).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 24).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 25).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 26).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 27).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 28).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 29).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 30).get_index()] = new win_vac;
  array[MonthDay::from_calendar(December, 31).get_index()] = new win_vac;

  if (random_event)
    maptable.install_events();
  maptable.set_birthday();
  return maptable;
}
