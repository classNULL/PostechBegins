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
	if (this->grades.size() < 2)
		this->grades.push_back(Score::generate_grade(this->study));
	else
		throw runtime_error("시험은 두 번만 봅니다.");
}
float hero::get_average_grade() const {
	float result;
	for (const auto& grade: this->grades)
		result += grade;
	return result / 2;
}

//모든 title 초기화
//각종 status 변화를 구현함. 이 때, MAX치보다 크면 MAX치로 되고, 0보다 작아지면 0으로 초기화
float hero::get_energy_consuming_rate() {
	if(stress < 30)
		return -3;
	else if(stress >= 30 && stress < 70)
		return -4;
	else if(stress >= 70)
		return -5;
	else
		throw runtime_error("스트레스 지수에 이상이 있습니다.");
}
void hero::recover_energy() {
	this->energy = MAX_ENERGY;
}

void hero::change_energy(float energy, int day){ // love status 변화
	this->energy = max(0.0f, min(MAX_ENERGY, energy * day));
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
float hero::get_stress() const {
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
const TitleBook& hero::get_title_book() const {
	return this->title_book;
}
TitleBook& hero::get_title_book() {
	return this->title_book;
}
