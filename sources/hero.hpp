#ifndef HERO
#define HERO

#include <vector>
#include <map>
#include <algorithm>
#include "global.hpp"
#include "hero.hpp"
#include "score.hpp"
#include "title.hpp"
class hero{
public:
  hero(const PersonalStatus& status_max, sexuality sex);
  float get_energy_consuming_rate();
  void recover_energy();
  void change_energy(float, int);
	void change_love(float, int);
	void change_relationship(float, int);
	void change_self_develop(float, int);
	void change_study(float, int);//status 변화시키는 method
  void change_stress(float, int);
  void change_status(PersonalStatus status_change, int day);
	void up_event();
  const PersonalStatus& max_status() const;
  const PersonalStatus& status() const;
  void take_exam(bool is_spring);
  float hero::get_average_grade(bool is_spring) const;
	sexuality get_sexuality() const;
  const TitleBook& get_title_book() const;
  TitleBook& get_title_book();
  int get_cleared_event();
private:
  const PersonalStatus MAX_STATUS;
  PersonalStatus current_status = {
    .energy = 0,
    .love = 0,

    .relationship = 30,
    .self_develop = 30,
    .study = 100,
    .stress = 0
  };
	vector<float> spring_grades; // 시험 기간에 결정
  vector<float> autumn_grades; // 시험 기간에 결정
	sexuality sex;
  TitleBook title_book;
  int cleared_event = 0;
};
#endif
