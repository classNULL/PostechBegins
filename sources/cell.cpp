#include "cell.hpp"
void cell::change(hero* _hero,int study,int relationship,int self_develop, int love, int stress, int day){ 
	_hero->change_energy();
	_hero->change_study(study, day);
	_hero->change_relationship(relationship, day);
	_hero->change_self_develop(self_develop, day);
	_hero->change_love(love, day);
	_hero->change_stress(stress, day);
}
void normal::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cin << option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 2, -2, 0, 0, 8, day);
	else if (option == 2)
		change(_hero, -4, 5, 0, 1, 5, day);
	else if (option == 3)
		change(_hero, -4, 5, 1, 1, -3, day);
	else if (option == 4)
		change(_hero, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 0, 0, 0, 0, -5, day);
}
void weekend::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 집가기"<<endl;
}

void march::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 밥사달라고하기"<<endl;
}
void before_exam::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;

}
void exam::call_option(hero* _hero,int day);{
	return 30;
}

void after_exam::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 연애하기"<<endl;

}
void festival::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 집에 가기"<<endl;


}

void dance::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 춤 연습하기"<<endl;


}

void special::call_option(hero* _hero,int day);{
	int option;
	cout<<"1. 참가한다"<<endl;
	cout<<"2. 참가하지 않는다"<<endl;

}

void GameCenter::select_option(hero* _hero,int option,int day){
	
	else if(option==16)
		_hero->change_energy();
	else if(option==17)
		//밥사달라고하기
	else if(option==21)//시험기간이므로 세부수치 변경 필요
		_hero->change_energy(), _hero->change_study(2,day), _hero->change_relationship(-2,day), _hero->change_self_develop(0,day), _hero->change_love(0,day), _hero->change_stress(8,day);
	else if(option==22)
		_hero->change_energy(), _hero->change_study(2,day), _hero->change_relationship(-2,day), _hero->change_self_develop(0,day), _hero->change_love(0,day), _hero->change_stress(8,day);
	//이하 구현 필요
}