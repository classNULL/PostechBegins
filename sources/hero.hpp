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
  hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, float max_stress, sexuality sex);
  void consume_energy(int);
  void rest(int);
  void recover_energy();
	void change_love(float, int);
	void change_relationship(float, int);
	void change_self_develop(float, int);
	void change_study(float, int);//status 변화시키는 method
  void change_stress(float, int);
	float get_MAX_ENERGY() const;
	float get_MAX_LOVE() const;
	float get_MAX_RELATIONSHIP() const;
	float get_MAX_SELF_DEVELOP() const;
  float get_MAX_STRESS();
	float get_study() const;
	float get_self_develop() const;
	float get_relationship() const;
	float get_energy() const;
	float get_love() const; //status return 받는 method
  float get_stress() const;
  float get_average_grade() const;
	bool has_title(string) const;
	void add_title(string);
  void remove_title(string);
  void take_exam();
	sexuality get_sexuality() const;
private:
	const float MAX_ENERGY;
	const float MAX_LOVE;
	const float MAX_RELATIONSHIP;
	const float MAX_SELF_DEVELOP;
	const float MAX_STUDY;
  const float MAX_STRESS;
	float energy; // 만약 체력이 0 일경우 다른 행동을 하지 못함
	float love;
	float relationship = 30;
	float self_develop = 30;
	float study = 100;
  float stress = 0;
	vector<float> grades; // 시험 기간에 결정
	sexuality sex;
  map<string, TitleEffect> titles;
};
#endif
