#include "hero.hpp"

hero::hero(PersonalStatus status_max, sexuality sex) : MAX_STATUS(status_max) {
	if(sex == sexuality::man){
		this->sex = man;
		current_status.love = 10;
		current_status.energy = 100;
		//성별이 남자일 때
	}
	else if(sex == sexuality::woman){
		this->sex = woman;
		current_status.love = 100;
		current_status.energy = 80;
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

void hero::up_event(){ //event 클리어 할 때마다 1씩 업
	this->cleared_event++;
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
	this->current_status.energy = MAX_STATUS.energy;
}

void hero::change_energy(float energy, int day){ // energy status 변화
	this->current_status.energy = max(0.0f, min(MAX_STATUS.energy, energy * day));
}
void hero::change_love(float love, int day){ // love status 변화
	this->current_status.love = max(0.0f, min(MAX_STATUS.love, love * day));
}
void hero::change_relationship(float relationship, int day){ //relationship status 변화
	this->current_status.relationship = max(0.0f, min(MAX_STATUS.relationship, relationship * day));
}
void hero::change_self_develop(float self_develop, int day){
	this->current_status.self_develop = max(0.0f, min(MAX_STATUS.self_develop, self_develop * day));
}
void hero::change_study(float study, int day){
	this->current_status.study = max(0.0f, min(MAX_STATUS.study, study * day));
}
void hero::change_stress(float stress,int day){
	this->current_status.stress = max(0.0f, min(MAX_STATUS.stress, stress * day));
}

const hero::max_status() const {
	return this->MAX_STATUS;
}
const hero::status() const {
	return this->current_status;
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
int hero::get_cleared_event(){
	return this->cleared_event;
}
