#include <iostream>
#include "global.h"
#include "hero.h"
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
hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number) : 
MAX_LOVE(max_love),MAX_ENERGY(max_energy),MAX_RELATIONSHIP(max_relationship), MAX_SELF_DEVELOP(max_selfdevelop){
	if(sex_number ==1){
		sex = man;
		set_love(10);
		set_relationship(30);
		set_self_develop(30);
		set_study(100);
		set_MAX_ENERGY(100);
		set_MAX_RELATIONSHIP(100);
		
	}
	else if(sex_number == 2){
		sex = woman;
		set_love(100);
		set_relationship(30);
		set_self_develop(30);
		set_study(100);
		set_MAX_ENERGY(80);
		set_MAX_RELATIONSHIP(90);
	}
	set_MAX_SELF_DEVELOP(100);
	set_MAX_LOVE(100);
	for(int i =0; i<5;i++){
		for(int j = 0;j<5;j++){
			title[i][j] = 0;
		}
	}
}


void hero::set_love(float love_){
	love = love_;
}
void hero::set_energy(float energy_){
	energy = energy_;
}
void hero::set_relationship(float relationship_){
	relationship=relationship_;
}
void hero::set_self_develop(float self_develop_){
	self_develop = self_develop_;
}
void hero::set_study(float study_){
	study = study_;
}
void hero::set_title(float* new_title){
	int i;
	for(i=0;i<5;i++){
		if(title[0][i]==0){
			break;
		}
	}
	for(int j=0;j<5;j++){
		title[i][j]=new_title[j];
	}
}



float hero::get_study(){
	return study;
}
float hero::get_self_develop(){
	return self_develop;
}
float hero::get_relationship(){
	return relationship;
}
float hero::get_energy(){
	return energy;
}
float hero::get_love(){
	return love;
}

float hero::get_MAX_ENERGY(){
	return MAX_ENERGY;
}
float hero::get_MAX_LOVE(){
	return MAX_LOVE;
}
float hero::get_MAX_RELATIONSHIP(){
	return MAX_RELATIONSHIP;
}
float hero::get_MAX_SELF_DEVELOP(){
	return MAX_SELF_DEVELOP;
}
