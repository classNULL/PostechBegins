#include <iostream>
#include "global.hpp"
#include "hero.hpp"

hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, float max_stress, sexuality sex) :
//const 변수 초기화
MAX_LOVE(max_love),MAX_ENERGY(max_energy),MAX_RELATIONSHIP(max_relationship), MAX_SELF_DEVELOP(max_selfdevelop),MAX_STUDY(max_study),MAX_STRESS(max_stress) {
	if(sex == sexuality::man){
		this->sex = man;
		love = 10;
		energy = 100;
		//성별이 남자일 때
	}
	else if(sex == sexuality::woman){
		this->sex = woman;
		love = 100;
		energy = 80;
		//성별이 여자일 때
	}
}

void hero::take_exam() {
	if (this->size() < 2)
		this->grades.push_back(Score::generate_grade(this->study));
	else
		throw runtime_error("시험은 두 번만 봅니다.");
}
float hero::get_average_grade() const {
	float result;
	for (const auto& grade: this->grades)
		result += grade
	return result / 2;
}

bool hero::get_title(int index) const {
	return title_list[index];
}
void hero::set_title(int, index, bool data){
	title_list[index] = data;
}
//모든 title 초기화
//각종 status 변화를 구현함. 이 때, MAX치보다 크면 MAX치로 되고, 0보다 작아지면 0으로 초기화
void hero::consume_energy(int day) {
	int change_energy;
	if(stress < 30)
		change_energy = -3;
		else if(stress >= 30 && stress < 70)
		change_energy = -4;
		else if(stress >= 70)
		change_energy = -5;

		auto result = energy + (change_energy * day);
		energy = max(0, min(MAX_ENERGY, result));
	}
void hero::rest(int day) {
	auto result = energy + (8 * day);
	energy = max(0, min(MAX_ENERGY, result));
}
void hero::recover_energy() {
	energy = MAX_ENERGY;
}

void hero::change_love(float love_, int day){ // love status 변화
	love += (love_*day);
	if(love > MAX_LOVE)
		love = MAX_LOVE;
	else if(love<0)
		love = 0;
}
void hero::change_relationship(float relationship_, int day){ //relationship status 변화
	relationship += (relationship_*day);
	if(relationship > MAX_RELATIONSHIP)
		relationship = MAX_RELATIONSHIP;
	else if(relationship<0){
		relationship = 0;
	}
}
void hero::change_self_develop(float self_develop_, int day){
	self_develop += (self_develop_*day);
	if(self_develop > MAX_SELF_DEVELOP)
		self_develop = MAX_SELF_DEVELOP;
	else if(self_develop<0){
		self_develop = 0;
	}
}
void hero::change_study(float study_, int day){
	study += (study_*day);
	if(study>MAX_STUDY)
		study = MAX_STUDY;
	else if(study<0){
		study = 0;
	}
}
void hero::change_stress(float stress_,int day){
	stress += (stress_*day);
	if(stress>MAX_STRESS){
		stress=MAX_STRESS;
	}
	else if(stress<0)
		stress = 0;
}

float hero::get_study() const {
	return study;
}
float hero::get_self_develop() const {
	return self_develop;
}
float hero::get_relationship() const {
	return relationship;
}
float hero::get_energy() const {
	return energy;
}
float hero::get_love() const {
	return love;
}
float hero::get_stress() const{
	return stress;
}

float hero::get_MAX_ENERGY() const {
	return MAX_ENERGY;
}
float hero::get_MAX_LOVE() const {
	return MAX_LOVE;
}
float hero::get_MAX_RELATIONSHIP() const {
	return MAX_RELATIONSHIP;
}
float hero::get_MAX_SELF_DEVELOP() const {
	return MAX_SELF_DEVELOP;
}
sexuality hero::get_sexuality() const {
   return sex;
}
