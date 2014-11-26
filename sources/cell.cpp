﻿#include "cell.hpp"

void cell::change(hero* _hero, float energy, float study, float relationship, float self_develop, float love, float stress, int day){
	_hero->change_energy(energy,day);
	_hero->change_study(study, day);
	_hero->change_relationship(relationship, day);
	_hero->change_self_develop(self_develop, day);
	_hero->change_love(love, day);
	_hero->change_stress(stress, day);
}
/*031524
체력	인간관계	연애	공부중	스트레스	자기개발
술
공부
동아리
연애
휴식
집
*/
float title[6][6];
for (int i = 0; i < 6; i++)
	for (int j = 0; j < 6; j++)
		title[i][j] = 1;
for (int a = 0, i < 7; i++){
	if (get_title(a)){
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				title[i][j] *= titles[a][i][j];
	}
}
void normal::call_option(hero* _hero,int day) {
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cin >> option;
	if (option == 1)
		change(_hero, 1 * title[1][0], 2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 8 * title[1][4], day);
	else if (option == 2)
		change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 5 * title[0][4], day);
	else if (option == 3)
		change(_hero, 1 * title[2][0], -4 * title[2][3], 5 * title[2][1], 1 * title[2][5], 1 * title[2][2], -3 * title[2][4], day);
	else if (option == 4)
		change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], 5 * title[3][2], 0 * title[3][4], day);
	else if (option == 5)
		change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -5 * title[4][4], day);
}
void weekend::call_option(hero* _hero,int day) {
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout << "6. 집가기" << endl;
	cin >> option;
	if (option == 1)
		change(_hero, 1 * title[1][0], 2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 8 * title[1][4], day);
	else if (option == 2)
		change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 5 * title[0][4], day);
	else if (option == 3)
		change(_hero, 1 * title[2][0], -4 * title[2][3], 5 * title[2][1], 1 * title[2][5], 1 * title[2][2], -3 * title[2][4], day);
	else if (option == 4)
		change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], 5 * title[3][2], 0 * title[3][4], day);
	else if (option == 5)
		change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -5 * title[4][4], day);
	else
		change(_hero, 3 * title[5][0], 0 * title[5][3], 0 * title[5][1], 0 * title[5][5], 0 * title[5][2], 0 * title[5][4], day);
}

void march::call_option(hero* _hero,int day) {
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 밥사달라고하기"<<endl;
}
void before_exam::call_option(hero* _hero,int day) {
	int option;
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)
		change(_hero, 1 * title[1][0], 3 * title[1][3], -1.6 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9.6 * title[1][4], day);
	else if (option == 2)
		change(_hero, 1 * title[0][0], -8 * title[0][3], 6 * title[0][1], 0 * title[0][5], 1 * title[0][2], 7.5 * title[0][4], day);
	else if (option == 3)
		change(_hero, 1 * title[2][0], -6 * title[2][3], 6 * title[2][1], 0.8 * title[2][5], 1 * title[2][2], -3.6 * title[2][4], day);
	else if (option == 4)
		change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], 5 * title[3][2], 0 * title[3][4], day);
	else if (option == 5)
		change(_hero, 2 * title[4][0], -3 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2.5 * title[4][4], day);


}
void exam::call_option(hero* _hero,int day) {

}

void after_exam::call_option(hero* _hero,int day) {
	int option;
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)
		change(_hero, 1 * title[1][0], 1.4 * title[1][3], -4 * title[1][1], 0 * title[1][5], 0 * title[1][2], 8 * title[1][4], day);
	else if (option == 2)
		change(_hero, 1 * title[0][0], -2 * title[0][3], 7.5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 4 * title[0][4], day);
	else if (option == 3)
		change(_hero, 1 * title[2][0], -2 * title[2][3], 6 * title[2][1], 1 * title[2][5], 1 * title[2][2], -3 * title[2][4], day);
	else if (option == 4)
		change(_hero, 1 * title[3][0], -2 * title[3][3], -3 * title[3][1], 0 * title[3][5], 5 * title[3][2], 0 * title[3][4], day);
	else if (option == 5)
		change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -5 * title[4][4], day);

}
void festival::call_option(hero* _hero, int day) {
	int option;
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 연애하기" << endl;
	cout << "4. 휴식" << endl;
	cout << "5. 집가기" << endl;
	cin >> option;
	if (option == 1)
		change(_hero, 1 * title[1][0], 2 * title[1][3], -10 * title[1][1], 0 * title[1][5], 0 * title[1][2], 8 * title[1][4], 1);
	else if (option == 2)
		change(_hero, 1 * title[0][0], -0.8 * title[0][3], 15 * title[0][1], 0 * title[0][5], 1 * title[0][2], 4 * title[0][4], 1);
	else if (option == 3)
		change(_hero, 1 * title[3][0], -4 * title[3][3], -12 * title[3][1], 0 * title[3][5], 5 * title[3][2], 0 * title[3][4], 1);
	else if (option == 4)
		change(_hero, 2 * title[4][0], 0 * title[4][3], -10 * title[4][1], 0 * title[4][5], 0 * title[4][2], -4 * title[4][4], 1);
	else
		change(_hero, 3 * title[5][0], 0 * title[5][3], -12 * title[5][1], 0 * title[5][5], 0 * title[5][2], 0 * title[5][4], 1);

}

void dance::call_option(hero* _hero, int day) {
	int option;
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cout << "6. 춤 연습하기" << endl;
	cin >> option;
	if (option == 1)
		change(_hero, 1 * title[1][0], 2 * title[1][3], -3 * title[1][1], 0 * title[1][5], 0 * title[1][2], 8 * title[1][4], day);
	else if (option == 2)
		change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 5 * title[0][4], day);
	else if (option == 3)
		change(_hero, 1 * title[2][0], -4 * title[2][3], 4 * title[2][1], 1 * title[2][5], 1 * title[2][2], -3 * title[2][4], day);
	else if (option == 4)
		change(_hero, 1 * title[3][0], -4 * title[3][3], -3 * title[3][1], 0 * title[3][5], 5 * title[3][2], 0 * title[3][4], day);
	else if (option == 5)
		change(_hero, 2 * title[4][0], 0 * title[4][3], -3 * title[4][1], 0 * title[4][5], 0 * title[4][2], -5 * title[4][4], day);
	else if (option == 6)
		change(_hero, 1, -4, 7, 0, 0, 6, day);


}

void special::call_option(hero* _hero, int day) {
	int option;
	cout << "1. 참가한다" << endl;
	cout << "2. 참가하지 않는다" << endl;

	if (option == 1)
		change(_hero, 1, -4, 8, 0, 0, 4, 1);
	else if (option == 2)
		change(_hero, 1, 4, -8, 0, 0, -2, 1);

}
