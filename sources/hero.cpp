#include <iostream>
#include "global.hpp"
#include "hero.hpp"

hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, float max_study, float max_stress, sexuality sex) :
//const 변수 초기화
MAX_LOVE(max_love), MAX_ENERGY(max_energy), MAX_RELATIONSHIP(max_relationship), MAX_SELF_DEVELOP(max_selfdevelop), MAX_STUDY(max_study), MAX_STRESS(max_stress) {
	if (sex == sexuality::man){
		this->sex = man;
		love = 10;
		relationship = 30;
		self_develop = 30;
		study = 100;
		energy = 100;
		stress = 0;
		energy_is_zero = false;
		//성별이 남자일 때
	}
	else if (sex == sexuality::woman){
		this->sex = woman;
		energy = 80;
		love = 100;
		relationship = 30;
		self_develop = 30;
		study = 100;
		stress = 0;
		energy_is_zero = false;
		//성별이 여자일 때
	}
	title_list = { false, false, false, false, false, false, false }
		titles[7][6][6] = {
				{ { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }, //아싸
				{ { 1, 1.1, 1, 1, -1, 1 }, { 1, 1, 1, 0.9, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }, //술쟁이
				{ { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1.05, 1, 1, 1, 1.05 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }, //동방충
				{ { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 } }, // 공부벌레
				{ { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 } }, // 연애중
				{ { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 } },//무동아리
				{ { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 }, { 1, 1, 1, 1, 1, 1 } }//체력낮음
	};
}

bool hero::get_title(int index){
	return title_list[index];
}
void hero::set_title(int, index, bool data){
	title_list[index] = data;
}
bool hero::get_energy_is_zero(){
	return energy_is_zero;
}
bool titles
//모든 title 초기화
//각종 status 변화를 구현함. 이 때, MAX치보다 크면 MAX치로 되고, 0보다 작아지면 0으로 초기화
void hero::change_love(float love_, int day){ // love status 변화
	love += (love_*day);
	if (love > MAX_LOVE)
		love = MAX_LOVE;
	else if (love<0)
		love = 0;
}

void hero::change_stress(float stress_, int day){
	stress += (stress_*day);
	if (stress>MAX_STRESS){
		stress - MAX_STRESS;
	}
	else if (stress<0)
		stress = 0;
}
void hero::change_energy(float energy_, int day){ //energy status 변화
	//1이 일반 선택지, 2가 휴식, 3이 집
	energy_is_zero = false; //energy_is_zero가 0 이 아니도록 만들고 method 끝내기 전에 energy가 0보다 작거나 같으면 energy_is_zero 를 1로 변경
	float change_energy;
	if (energy_ == 1){ //일반선택지의 경우 stress에 따라서 stress가 변하는 정도가 다르다.
		if (stress >= 0 && stress< 30){
			change_energy = -3;
		}
		else if (stress >= 30 && stress <= 70){
			change_energy = -4;
		}
		else if (stress >= 70 && stress <= MAX_STRESS){
			change_energy = -5;
		}
	}
	else if (energy_ == 2){
		change_energy = 8; //휴식으을 취하는 경우 8을 회복
	}
	else if (energy_ == 3){ // 집갔다 오는 경우 전체 회복
		change_energy = MAX_ENERGY;
	}
	energy += (change_energy*day);
	if (energy > MAX_ENERGY)
		energy = MAX_ENERGY;
	else if (energy <= 0){
		energy = 0;
		energy_is_zero = true;
	}
}
void hero::change_relationship(float relationship_, int day){ //relationship status 변화
	relationship += (relationship_*day);
	if (relationship > MAX_RELATIONSHIP)
		relationship = MAX_RELATIONSHIP;
	else if (relationship<0){
		relationship = 0;
	}
}
void hero::change_self_develop(float self_develop_, int day){
	self_develop += (self_develop_*day);
	if (self_develop > MAX_SELF_DEVELOP)
		self_develop = MAX_SELF_DEVELOP;
	else if (self_develop<0){
		self_develop = 0;
	}
}
void hero::change_study(float study_, int day){
	study += (study_*day);
	if (study>MAX_STUDY)
		study = MAX_STUDY;
	else if (study<0){
		study = 0;
	}
}
float hero::get_study() const{
	return stress;
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
void hero::end_the_game(){
	float final_point;


}
sexuality hero::get_sexuality() const {
	return sex;
}