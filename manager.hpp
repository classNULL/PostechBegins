#include <array>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Manager {
private:
  array<int, 2> date;
  float calc_grade_score(float grade);
public:
  array<int, 2> get_date();
  void set_date(const array<int, 2>& new_date) { date = new_date; }

  int dice() { return rand() % 6; }

  float generate_grade(int study) {
    return max(min(study / 100.0f * 4.3 + ((rand() % 30 - 15) / 100.0f), 4.3), 0.0);
  }

  //칭호
  int score(float grade, float relationship, float improvement);
};
