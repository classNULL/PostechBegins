#include <iostream>
#include "global.h"
#include "hero.h"
class hero{
public:
	hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number, float max_study);
	void change_love(float);
	void change_energy(float);
	void change_relationship(float);
	void change_self_develop(float);
	void change_study(float);
	void change_title(float*);
	void change_MAX_ENERGY(const float);
	void change_MAX_LOVE(const float);
	void change_MAX_RELATIONSHIP(const float);
	void change_MAX_SELF_DEVELOP(const float); //status ��ȭ��Ű�� method
	float get_MAX_ENERGY();
	float get_MAX_LOVE();
	float get_MAX_RELATIONSHIP();
	float get_MAX_SELF_DEVELOP();
	float get_study();
	float get_self_develop();
	float get_relationship();
	float get_energy();
	float get_love(); //status return �޴� method
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
	float title[5][5];
	bool energy_is_zero; //�������� 0���� �ƴ��� ������. ���� ü���� 0 �ϰ�� �ٸ� �ൿ�� ���� ����
};
hero::hero(float max_love, float max_energy, float max_relationship, float max_selfdevelop, int sex_number, float max_study) : 
//const ���� �ʱ�ȭ
MAX_LOVE(max_love),MAX_ENERGY(max_energy),MAX_RELATIONSHIP(max_relationship), MAX_SELF_DEVELOP(max_selfdevelop),MAX_STUDY(max_study) { 
	if(sex_number ==1){
		sex = man;
		love = 10;
		relationship = 30;
		self_develop = 30;
		study = 100;
		//������ ������ ��
	}
	else if(sex_number == 2){
		sex = woman;
		love = 100;
		relationship = 30;
		self_develop = 30;
		study = 100;
		}
	//������ ������ ��
	for(int i =0; i<5;i++){
		for(int j = 0;j<5;j++){
			title[i][j] = 0;
		}
	}
	energy_is_zero = 0;
}
//��� title �ʱ�ȭ
//���� status ��ȭ�� ������. �� ��, MAXġ���� ũ�� MAXġ�� �ǰ�, 0���� �۾����� 0���� �ʱ�ȭ
void hero::change_love(float love_){ // love status ��ȭ
	love =+ love_;
	if(love > MAX_LOVE) 
		love = MAX_LOVE;
	else if(love<0)
		love = 0;
}
void hero::change_energy(float energy_){ //energy status ��ȭ
	energy_is_zero = 0; //energy_is_zero�� 0 �� �ƴϵ��� ����� method ������ ���� energy�� 0���� �۰ų� ������ energy_is_zero �� 1�� ����
	energy =+ energy_;
	if(energy > MAX_ENERGY)
		energy = MAX_LOVE;
	else if(energy<=0){
		energy = 0;
		energy_is_zero = 1;
	}
}
void hero::change_relationship(float relationship_){ //relationship status ��ȭ
	relationship =+ relationship_;
	if(relationship > MAX_RELATIONSHIP)
		relationship = MAX_RELATIONSHIP;
	else if(relationship<0){
		relationship = 0;
	}
}
void hero::change_self_develop(float self_develop_){
	self_develop =+ self_develop_;
	if(self_develop > MAX_SELF_DEVELOP)
		self_develop = MAX_SELF_DEVELOP;
	else if(self_develop<0){
		self_develop = 0;
	}
}
void hero::change_study(float study_){
	study =+ study_;
	if(study>MAX_STUDY)
		study = MAX_STUDY;
	else if(study<0){
		study = 0;
	}
}
void hero::change_title(float* new_title){
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
