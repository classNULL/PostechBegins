#ifndef HERO
#define HERO

#include <iostream>
#include "global.hpp"
#include "hero.hpp"
class hero{
public:
  hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, float max_stress, sexuality sex);
	void change_love(float, int);
	void change_energy(float, int);
	void change_relationship(float, int);
	void change_self_develop(float, int);
	void change_study(float, int);//status 변화시키는 method
	void change_stress(float, int);
	void up_event();
	float get_MAX_STRESS();
	float get_MAX_ENERGY() const;
	float get_MAX_LOVE() const;
	float get_MAX_RELATIONSHIP() const;
	float get_MAX_SELF_DEVELOP() const;
	float get_study() const;
	float get_self_develop() const;
	float get_relationship() const;
	float get_energy() const;
	float get_love() const; //status return 받는 method
	bool get_energy_is_zero() const;
	void end_the_game();
	bool get_title(int);
	void set_title(int, bool);
	sexuality get_sex() const;
	int get_clear_event();
private:
	const float MAX_ENERGY;
	const float MAX_LOVE;
	const float MAX_RELATIONSHIP;
	const float MAX_SELF_DEVELOP;
	const float MAX_STUDY;
	const float MAX_STRESS;
	float stress;
	float energy;
	float love;
	float relationship;
	float self_develop;
	float study;
	float gpa;
	sexuality sex;
	bool energy_is_zero; //에너지가 0인지 아닌지 구별함. 만약 체력이 0 일경우 다른 행동을 하지 못함
	bool title_list[7];
	float titles[7][6][6] ;
	int clear_event;
  /*
  체력	인간관계	연애	공부중	스트레스	자기개발
  술
  공부
  동아리
  연애
  휴식
  집

  */

};
#endif
