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
void set_title(hero* _hero){
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			title[i][j] = 1;
	float*** titles = _hero->get_titles();
	for (int a = 0, i < 7; i++){
		if (_hero->get_title(a)){
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					title[i][j] *= titles[a][i][j];
		}
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
	set_title(_hero);

	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==4){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2 * title[4][4], day);
		}
	
	
	}

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
	set_title(_hero);


	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==4){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2 * title[4][4], day);
		}
		else if(option==6){
			cout<<"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다...."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 3 * title[5][0], 0 * title[5][3], 0 * title[5][1], 0 * title[5][5], 0 * title[5][2], 3 * title[5][4], day);
		}
	
	
	}



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
	cin << option;
	set_title(_hero);

	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==4){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2 * title[4][4], day);
		}

		
	
	
	}





	if (option == 1)
		change(_hero, 1, 2, -2, 0, 0, 8, day);
	else if (option == 2)
		change(_hero, 1, -4, 5, 0, 1, 5, day);
	else if (option == 3)
		change(_hero, 1, -4, 5, 1, 1, -3, day);
	else if (option == 4)
		change(_hero, 1, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 2, 0, 0, 0, 0, -5, day);
	else if (option == 6)
		change(_hero, 1, -2, 5, 0, 1, -3, day);
	//3월달은 어차피 칭호가 없음
}
void before_exam::call_option(hero* _hero,int day) {
	int option;
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	set_title(_hero);

	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==4){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2 * title[4][4], day);
		}
	
	
	}



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
	set_title(_hero);

	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==4){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2 * title[4][4], day);
		}
	
	
	}

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
	set_title(_hero);


	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==3){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==4){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], 0 * title[4][1], 0 * title[4][5], 0 * title[4][2], -2 * title[4][4], day);
		}
		else if(option==5){
			cout<<"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다...."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 3 * title[5][0], 0 * title[5][3], 0 * title[5][1], 0 * title[5][5], 0 * title[5][2], 3 * title[5][4], day);
		}
	
	
	}


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
	set_title(_hero);


	srand(time(NULL)); 
	int random=rand()%100;
	//random이 1이면 변화가 일어나게
	if(random==1){
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[1][0], -2 * title[1][3], -2 * title[1][1], 0 * title[1][5], 0 * title[1][2], 9 * title[1][4], day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;	
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			change(_hero, 1 * title[0][0], -4 * title[0][3], 5 * title[0][1], 0 * title[0][5], 1 * title[0][2], 6 * title[0][4], day);
		}
		else if(option==4){
			bool is_inLove=get_title(4);
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->set_title(4,false);
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -15 * title[3][2], 15 * title[3][4], day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				change(_hero, 1 * title[3][0], -4 * title[3][3], -2 * title[3][1], 0 * title[3][5], -8 * title[3][2], 6 * title[3][4], day);
			}
		}

		else if(option==5){
			cout<<"..헉 몰래 쉰 것을 선배들한테 들켰다 ㅜㅜㅜ 망했다..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[4][0], 0 * title[4][3], -3 * title[4][1], 0 * title[4][5], 0 * title[4][2], 5 * title[4][4], day);
		}
		else if(option==6){
			cout<<"..다리를 삐어서 춤연습을 제대로 할 수 없다 ㅜㅜ..."<<endl;	
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			change(_hero, 2 * title[5][0], 0 * title[5][3], 2 * title[5][1], 0 * title[5][5], 0 * title[5][2], 5 * title[5][4], day);
		}
	
	
	}


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
void eve_1::call_option(hero* _hero, int day) {
	int option;
		cout << "학교에 태풍이 몰아닥쳤습니다. " << endl;
		cout << "1. 수업가기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 나들이" << endl;
		cout << "4. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero, 1, 4, -2, 0, 0, 10, day);
		else if (option == 2)
			change(_hero, 1, -4, 6, 0, 2, 7, day);
		else if (option == 3)
			change(_hero, 1, -4, 5, 0, 3, -2, day);
		else if (option == 5)
			change(_hero, 2, 0, 0, 0, 0, -5, day);
	
}

void eve_2::call_option(hero* _hero, int day) {
	int option;
		cout << "과제가 밀려서 밤을 샜습니다. " << endl;
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 연애하기" << endl;
		cout << "5. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero, 1, 1, -2, 0, 0, 9, day);
		else if (option == 2)
			change(_hero, 1, -4, 4, 0, 1, 6, day);
		else if (option == 3)
			change(_hero, 1, -4, 4, 1, 1, 1, day);
		else if (option == 4)
			change(_hero, 1, -4, -2, 0, 4, 3, day);
		else if (option == 5)
			change(_hero, 2, 0, 0, 0, 0, -5, day);
	
}

void eve_3::call_option(hero* _hero, int day) {
	int option;
		cout << "빨래를 안 해서 입을 옷이 없습니다. " << endl;
		cout << "1. 수업가기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 빨래하기" << endl;
		cout << "5. 옷 빌리기" << endl;
		cout << "6. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero, 1, 2, -5, 0, 0, 8, day);
		else if (option == 2)
			change(_hero, 1, -4, -3, 0, -1, 5, day);
		else if (option == 3)
			change(_hero, 1, -4, -3, 1, -1, -3, day);
		else if (option == 4)
			change(_hero, 1, -3, 0, 0, 0, 1, day);
		else if (option == 5)
			change(_hero, 2, 0, 1, 0, 0, -3, day);
		else if (option == 6)
			change(_hero, 2, 0, 0, 0, 0, -5, day);
}