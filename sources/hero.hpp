#ifndef HERO
#define HERO

#include <iostream>

class hero{
public:
	hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number);
	void set_love(float);
	void set_energy(float);
	void set_relationship(float);
	void set_self_develop(float);
	void set_study(float);
	void set_title(float*);
	void set_MAX_ENERGY(const float);
	void set_MAX_LOVE(const float);
	void set_MAX_RELATIONSHIP(const float);
	void set_MAX_SELF_DEVELOP(const float);
	float get_MAX_ENERGY();
	float get_MAX_LOVE();
	float get_MAX_RELATIONSHIP();
	float get_MAX_SELF_DEVELOP();
	float get_study();
	float get_self_develop();
	float get_relationship();
	float get_energy();
	float get_love();
private:
	const float MAX_ENERGY;
	const float MAX_LOVE;
	const float MAX_RELATIONSHIP;
	const float MAX_SELF_DEVELOP;
	float energy;
	float love;
	float relationship;
	float self_develop;
	float study;
	enum sexuality sex;
	float title[5][5];
};
#endif