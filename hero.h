#ifndef HERO
#define HERO

#include <iostream>
class hero{
public:
	hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number, float max_study);
	void change_love(float);
	void change_energy(float);
	void change_relationship(float);
	void change_self_develop(float);
	void change_study(float);
	void change_title(float*);
	void change_MAX_ENERGY(const float);
	void change_MAX_LOVE(const float);
	void change_MAX_RELATIONSHIP(const float);
	void change_MAX_SELF_DEVELOP(const float); //status 변화시키는 method
	float get_MAX_ENERGY();
	float get_MAX_LOVE();
	float get_MAX_RELATIONSHIP();
	float get_MAX_SELF_DEVELOP();
	float get_study();
	float get_self_develop();
	float get_relationship();
	float get_energy();
	float get_love(); //status return 받는 method
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
	enum sexuality sex;
	float title[5][5];
	bool energy_is_zero; //에너지가 0인지 아닌지 구별함. 만약 체력이 0 일경우 다른 행동을 하지 못함
};
#endif