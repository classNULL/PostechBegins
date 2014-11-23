#include <iostream>
#include "global.h"
#include "hero.h"
class hero{
public:
	hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number, float max_study);
	void change_love(float,float);
	void change_energy(float, float);
	void change_relationship(float, float);
	void change_self_develop(float, float);
	void change_study(float, float);
	void change_MAX_ENERGY(const float);
	void change_MAX_LOVE(const float);
	void change_MAX_RELATIONSHIP(const float);
	void change_MAX_SELF_DEVELOP(const float); //status 변화시키는 method
	float get_MAX_ENERGY();
	float get_MAX_LOVE();
	float get_MAX_RELATIONSHIP();
	float get_MAX_SELF_DEVELOP();
	float get_study();
	float get_self_develop();
	float get_relationship();
	float get_energy();
	float get_love(); //status return 받는 method
private:
	const float MAX_ENERGY;
	const float MAX_LOVE;
	const float MAX_RELATIONSHIP;
	const float MAX_SELF_DEVELOP;
	const float MAX_STUDY;
	float energy;
	float love;
	float relationship;
	float self_develop;
	float study;
	enum sexuality sex;
	bool energy_is_zero; //에너지가 0인지 아닌지 구별함. 만약 체력이 0 일경우 다른 행동을 하지 못함
	float titles[7][6][6];
};
hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number, float max_study) : 
//const 변수 초기화
MAX_LOVE(max_love),MAX_ENERGY(max_energy),MAX_RELATIONSHIP(max_relationship), MAX_SELF_DEVELOP(max_selfdevelop),MAX_STUDY(max_study) { 
	if(sex_number ==1){
		sex = man;
		love = 10;
		relationship = 30;
		self_develop = 30;
		study = 100;
		energy = 100;
		//성별이 남자일 때
	}
	else if(sex_number == 2){
		sex = woman;
		energy = 80;
		love = 100;
		relationship = 30;
		self_develop = 30;
		study = 100;
		}
	//성별이 여자일 때
	energy_is_zero = 0;
	/*
			체력	인간관계	연애	공부중	스트레스	자기개발
	술
	공부
	동아리
	연애
	휴식
	집
	
	*/
	titles[0] = { { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }, { 1, 1.1, 1, 1, 1, 1 }{1, 1.1, 1, 1, 1, 1}, { 1, 1, 1, 1, 1, 1 }{1, 1, 1, 1, 1, 1} }; //아싸
	titles[1] = { { 1, 1.1, 1, 1, -1, 1 }, { 1, 1, 1, 0.9, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }; //술쟁이
	titles[2] = { { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1.05, 1, 1, 1, 1.05 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 } }; //동방충
	titles[3] = { { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 }, { 1, 0.95, 1, 1.1, 1, 0.95 } }; // 공부벌레
	titles[4] = { { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 }, { 1.1, 0.9, 1, 0.9, 0, 0.9 } }; // 연애중
	titles[5] = { { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 }, { 1, 0.9, 1, 1, 1, 1 } };//무동아리
	titles[6] = { { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1 }, { 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 }, { 1, 1, 1, 1, 1, 1 } };//체력낮음
}
//모든 title 초기화
//각종 status 변화를 구현함. 이 때, MAX치보다 크면 MAX치로 되고, 0보다 작아지면 0으로 초기화
void hero::change_love(float love_, float day){ // love status 변화
	love =+ love_;
	if(love > MAX_LOVE) 
		love = MAX_LOVE;
	else if(love<0)
		love = 0;
}
void hero::change_energy(float energy_, float day){ //energy status 변화
	energy_is_zero = 0; //energy_is_zero가 0 이 아니도록 만들고 method 끝내기 전에 energy가 0보다 작거나 같으면 energy_is_zero 를 1로 변경
	energy =+ (energy_*day);
	if(energy > MAX_ENERGY)
		energy = MAX_ENERGY;
	else if(energy<=0){
		energy = 0;
		energy_is_zero = 1;
	}
}
void hero::change_relationship(float relationship_, float day){ //relationship status 변화
	relationship =+ (relationship_*day);
	if(relationship > MAX_RELATIONSHIP)
		relationship = MAX_RELATIONSHIP;
	else if(relationship<0){
		relationship = 0;
	}
}
void hero::change_self_develop(float self_develop_, float day){
	self_develop =+ (self_develop_*day);
	if(self_develop > MAX_SELF_DEVELOP)
		self_develop = MAX_SELF_DEVELOP;
	else if(self_develop<0){
		self_develop = 0;
	}
}
void hero::change_study(float study_, float day){
	study =+ (study_*day);
	if(study>MAX_STUDY)
		study = MAX_STUDY;
	else if(study<0){
		study = 0;
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

EMSCRIPTEN_BINDINGS(PostechBegins_Hero) {
	class_<hero>("Hero")
		.constructor<sexuality>()
		.property("love", &hero::get_love, &hero::set_love)
		.property("energy", &hero::get_energy, &hero::set_energy)
		.property("relationship", &hero::get_relationship, &hero::set_relationship)
		.property("selfImprovement", &hero::get_self_develop, &hero::set_self_develop)
		.property("study", &hero::get_study, &hero::set_study)
		.property("MAX_ENERGY", &hero::get_MAX_ENERGY, &hero::set_MAX_ENERGY)
		.property("MAX_LOVE", &hero::get_MAX_LOVE, &hero::set_MAX_LOVE)
		.property("MAX_RELATIONSHIP", &hero::get_MAX_RELATIONSHIP, &hero::set_MAX_RELATIONSHIP)
		.property("MAX_SELFIMPROVEMENT", &hero::get_MAX_SELF_DEVELOP, &hero::set_MAX_SELF_DEVELOP);
}
