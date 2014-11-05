#include <iostream>
#include "global.hpp"
#include "hero.hpp"

#ifndef EMBIND_H
#define EMBIND_H
#include <emscripten/bind.h>
#endif

using namespace emscripten;

hero::hero(sexuality sex) {
	this->sex = sex;
	if(sex == sexuality::man){
		set_love(10);
		set_relationship(30);
		set_self_develop(30);
		set_study(100);
		set_MAX_ENERGY(100);
		set_MAX_RELATIONSHIP(100);

	}
	else if(sex == sexuality::woman){
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

void hero::set_MAX_ENERGY(float value){
	MAX_ENERGY = value;
}
void hero::set_MAX_LOVE(float value){
	MAX_LOVE = value;
}
void hero::set_MAX_RELATIONSHIP(float value){
	MAX_RELATIONSHIP = value;
}
void hero::set_MAX_SELF_DEVELOP(float value){
	MAX_SELF_DEVELOP = value;
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