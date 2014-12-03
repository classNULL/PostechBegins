#ifndef GLOBAL
#define GLOBAL
#include <iostream>
#include <cstdlib>
using namespace std;

enum sexuality{
	man,woman
};

struct PersonalStatus {
	float energy;
	float relationship;
	float love;
	float study;
	float self_develop;
	float stress;

	static PersonalStatus get_ones() {
		return {
			.energy = 1,
			.relationship = 1,
			.love = 1,
			.study = 1,
			.self_develop = 1,
			.stress = 1
		};
	}

	PersonalStatus multiply(PersonalStatus status) {
		auto result = *this;
		
		result.energy *= status.energy;
		result.relationship *= status.relationship;
		result.love *= status.love;
		result.study *= status.study;
		result.self_develop *= status.self_develop;
		result.stress *= status.stress;

		return result;
	}
};

#endif
