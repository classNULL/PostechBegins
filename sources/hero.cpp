#include <iostream>
#include "global.hpp"
#include "hero.hpp"

hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, sexuality sex) :
//const 변수 초기화
MAX_LOVE(max_love),MAX_ENERGY(max_energy),MAX_RELATIONSHIP(max_relationship), MAX_SELF_DEVELOP(max_selfdevelop),MAX_STUDY(max_study) {
	if(sex == sexuality::man){
		this->sex = man;
		love = 10;
		relationship = 30;
		self_develop = 30;
		study = 100;
		energy = 100;
		//성별이 남자일 때
	}
	else if(sex == sexuality::woman){
		this->sex = woman;
		energy = 80;
		love = 100;
		relationship = 30;
		self_develop = 30;
		study = 100;
		//성별이 여자일 때
	}
}
//모든 title 초기화
//각종 status 변화를 구현함. 이 때, MAX치보다 크면 MAX치로 되고, 0보다 작아지면 0으로 초기화
void hero::change_love(float love_, int day){ // love status 변화
	love += (love_*day);
	if(love > MAX_LOVE)
		love = MAX_LOVE;
	else if(love<0)
		love = 0;
}
void hero::change_energy(float energy_, int day){ //energy status 변화
	energy_is_zero = 0; //energy_is_zero가 0 이 아니도록 만들고 method 끝내기 전에 energy가 0보다 작거나 같으면 energy_is_zero 를 1로 변경
	energy += (energy_*day);
	if(energy > MAX_ENERGY)
		energy = MAX_ENERGY;
	else if(energy<=0){
		energy = 0;
		energy_is_zero = 1;
	}
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
float hero::calc_grade_score(float grade) {
	if (grade < 0)
		throw runtime_error("0보다 작으면 안됨");
	else if (grade < 2.0)
		return (grade) / 2 * 5;
	else if (grade < 2.3)
		return 20 + (grade - 2) / 0.3 * 10;
	else if (grade < 3.0)
		return 50 + (grade - 2.3) / 0.7 * 50;
	else if (grade < 3.3)
		return 200 + (grade - 3.0) / 0.3 * 20;
	else if (grade < 3.7)
		return 230 + (grade - 3.3) / 0.4 * 30;
	else if (grade < 4.0)
		return 280 + (grade - 3.7) / 0.3 * 30;
	else if (grade < 4.3)
		return 350 + (grade - 4.0) / 0.3 * 30;
	else if (grade == 4.3)
		return 400;
	else
		throw runtime_error("4.3보다 큼");
}

/*int hero::score() {
	//grade 400
	//relationship 300
	//improvement 300
	return (calc_grade_score(grade1) + calc_grade_score(grade2))/2 + (relationship * 3) + (self_develop * 3);
}*/
float hero::grade(){
	test++;
	switch (test){
	case 1://1학기 중간고사
		grade1 = generate_grade();
		return grade1;
	case 2://1학기 기말고사
		grade1 = grade1*0.5 + generate_grade()*0.5;
		return grade1;
	case 3://2학기 중간고사
		grade2 = generate_grade();
		return grade2;
	case 4://2학기 기말고사
		grade2 = grade2*0.5 + generate_grade()*0.5;
		return grade2;
	default://error
	}
}
void hero::game_exit(){
	int grade_score = (calc_grade_score(grade1) + calc_grade_score(grade2)) / 2;
	int relationship_score = relationship * 3;
	int self_develop_score = self_develop * 3;
	int score = grade_score + relationship_score + self_develop_score;
	switch (grade_score / 100){
	case 4:
	case 3://300이상
		break;
	case 2://200이상
		break;
	case 1://100이상
		break;
	case 0://100미만
		break;
	}
	switch (relationship_score / 100){
	case 3:
	case 2://200이상
		break;
	case 1://100이상
		break;
	case 0://100미만
		break;
	}
	switch (self_develop_score / 100){
	case 3:
	case 2://200이상
		break;
	case 1://100이상
		break;
	case 0://100미만
		break;
	}
}