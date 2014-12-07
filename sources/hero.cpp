#include "hero.hpp"

hero::hero(const PersonalStatus& status_max, sexuality sex) : MAX_STATUS(status_max) {
	if(sex == sexuality::man){
		this->sex = man;
		current_status.relationship = 20;
		current_status.love = 10;
		current_status.energy = 100;
		//성별이 남자일 때
	}
	else if(sex == sexuality::woman){
		this->sex = woman;
		current_status.relationship = 40;
		current_status.love = 80;
		current_status.energy = 80;
		//성별이 여자일 때
	}
}

void hero::take_exam() {
	if (this->_is_spring) {
		if (this->spring_grades.size() < 2)
			this->spring_grades.push_back(Score::generate_grade(this->status().study));
		else
			throw runtime_error("시험은 두 번만 봅니다.");
	}
	else {
		if (this->autumn_grades.size() < 2)
			this->autumn_grades.push_back(Score::generate_grade(this->status().study));
		else
			throw runtime_error("시험은 두 번만 봅니다.");
	}
}
float hero::get_semester_grade(bool is_spring) const {
	float result;
	auto& semester_grades = is_spring ? this->spring_grades : this->autumn_grades;
	for (const auto& grade: semester_grades) {
		result += grade;
	}
	return result / semester_grades.size();
}
float hero::get_average_grade() const {
	return (this->get_semester_grade(true) + this->get_semester_grade(false)) / 2;
}

void hero::up_event(){ //event 클리어 할 때마다 1씩 업
	this->cleared_event++;
}
//모든 title 초기화
//각종 status 변화를 구현함. 이 때, MAX치보다 크면 MAX치로 되고, 0보다 작아지면 0으로 초기화
float hero::get_energy_consuming_rate() {
	auto stress = this->status().stress;
	if(stress < 30)
		return -3;
	else if(stress >= 30 && stress < 70)
		return -4;
	else if(stress >= 70)
		return -5;
	else
		throw runtime_error("스트레스 지수에 이상이 있습니다.");
}

void hero::change_energy(float energy, int day){ // energy status 변화
	auto result = this->current_status.energy + energy * day;
	this->current_status.energy = max(0.0f, min(MAX_STATUS.energy, result));
}
void hero::change_love(float love, int day){ // love status 변화
	auto result = this->current_status.love + love * day;
	this->current_status.love = max(0.0f, min(MAX_STATUS.love, result));
}
void hero::change_relationship(float relationship, int day){ //relationship status 변화
	auto result = this->current_status.relationship + relationship * day;
	this->current_status.relationship = max(0.0f, min(MAX_STATUS.relationship, result));
}
void hero::change_self_develop(float self_develop, int day){
	auto result = this->current_status.self_develop + self_develop * day;
	this->current_status.self_develop = max(0.0f, min(MAX_STATUS.self_develop, result));
}
void hero::change_study(float study, int day){
	auto result = this->current_status.study + study * day;
	this->current_status.study = max(0.0f, min(MAX_STATUS.study, result));
}
void hero::change_stress(float stress,int day){
	auto result = this->current_status.stress + stress * day;
	this->current_status.stress = max(0.0f, min(MAX_STATUS.stress, result));
}
void hero::change_status(PersonalStatus status_change, int day) {
	this->change_energy(status_change.energy, day);
	this->change_study(status_change.study, day);
	this->change_relationship(status_change.relationship, day);
	this->change_self_develop(status_change.self_develop, day);
	this->change_love(status_change.love, day);
	this->change_stress(status_change.stress, day);
}
void hero::change_status(PersonalStatus status_change, PersonalStatus title_effect, int day) {
	if (status_change.energy > 0)
		this->change_energy(status_change.energy * title_effect.energy,day);
	else
		this->change_energy(status_change.energy, day);
	this->change_study(status_change.study * title_effect.study, day);
	this->change_relationship(status_change.relationship * title_effect.relationship, day);
	this->change_self_develop(status_change.self_develop * title_effect.self_develop, day);
	this->change_love(status_change.love * title_effect.love, day);
	this->change_stress(status_change.stress * title_effect.stress, day);
}

bool hero::exhausted() const {
	return (this->current_status.energy == 0);
}

void hero::finish_semester() {
	this->_is_spring = !this->_is_spring;
}
