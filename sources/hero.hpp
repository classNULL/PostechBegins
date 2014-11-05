#ifndef HERO
#define HERO

#include <iostream>

class hero{
public:
	hero(sexuality sex);
	void set_love(float);
	void set_energy(float);
	void set_relationship(float);
	void set_self_develop(float);
	void set_study(float);
	void set_title(float*);
	void set_MAX_ENERGY(float);
	void set_MAX_LOVE(float);
	void set_MAX_RELATIONSHIP(float);
	void set_MAX_SELF_DEVELOP(float);
	float get_MAX_ENERGY() const;
	float get_MAX_LOVE() const;
	float get_MAX_RELATIONSHIP() const;
	float get_MAX_SELF_DEVELOP() const;
	float get_study() const;
	float get_self_develop() const;
	float get_relationship() const;
	float get_energy() const;
	float get_love() const;
private:
	float MAX_ENERGY;
	float MAX_LOVE;
	float MAX_RELATIONSHIP;
	float MAX_SELF_DEVELOP;

	float energy;
	float love;
	float relationship;
	float self_develop;
	float study;
	sexuality sex;
	float title[5][5];
};
#endif
