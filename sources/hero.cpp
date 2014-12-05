#include "hero.hpp"

hero::hero(const PersonalStatus& status_max, sexuality sex) : MAX_STATUS(status_max) {
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

void hero::take_exam(bool is_spring) {
	if (is_spring) {
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
	if (is_spring) {
		for (const auto& grade: this->spring_grades)
			result += grade;
	}
	else {
		for (const auto& grade: this->autumn_grades)
			result += grade;
	}
	return result / 2;
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
void hero::change_status(PersonalStatus status_change, int day) {
	clog << "'this' pointer:" << this << endl;
	clog << "Applying change... Energy: " << this->status().energy << endl;
	this->current_status = this->current_status.plus(status_change.multiply(day));
	clog << "Applied. Energy: " << this->status().energy << endl;
}
void hero::change_status(PersonalStatus status_change, PersonalStatus title_effect, int day) {
	clog << "'this' pointer:" << this << endl;
	clog << "Applying change with title... Energy: " << this->status().energy << endl;
	if (status_change.energy > 0)
		this->change_energy(status_change.energy * title_effect.energy,day);
	else
		this->change_energy(status_change.energy, day);
	this->change_study(status_change.study * title_effect.study, day);
	this->change_relationship(status_change.relationship * title_effect.relationship, day);
	this->change_self_develop(status_change.self_develop * title_effect.self_develop, day);
	this->change_love(status_change.love * title_effect.love, day);
	this->change_stress(status_change.stress * title_effect.stress, day);
	clog << "Applied. Energy: " << this->status().energy << endl;
}

const PersonalStatus& hero::max_status() const {
	return this->MAX_STATUS;
}
const PersonalStatus& hero::status() const {
	return this->current_status;
}
bool hero::exhausted() const {
	return (this->current_status.energy == 0);
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
