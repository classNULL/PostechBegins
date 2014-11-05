#ifndef HERO
#define HERO

#include <iostream>
#include "global.hpp"
#include "hero.hpp"
class hero{
public:
  hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, sexuality sex);
	void change_love(float);
	void change_energy(float);
	void change_relationship(float);
	void change_self_develop(float);
	void change_study(float);
	void change_title(float*); //status 변화시키는 method
	float get_MAX_ENERGY() const;
	float get_MAX_LOVE() const;
	float get_MAX_RELATIONSHIP() const;
	float get_MAX_SELF_DEVELOP() const;
	float get_study() const;
	float get_self_develop() const;
	float get_relationship() const;
	float get_energy() const;
	float get_love() const; //status return 받는 method
private:
	const float MAX_ENERGY;
	const float MAX_LOVE;
	const float MAX_RELATIONSHIP;
	const float MAX_SELF_DEVELOP;
	const float MAX_STUDY;
	float energy;
	float love;
	float relationship;
	float self_develop;
	float study;
	sexuality sex;
	float title[5][5];
	bool energy_is_zero; //에너지가 0인지 아닌지 구별함. 만약 체력이 0 일경우 다른 행동을 하지 못함
};
#endif
