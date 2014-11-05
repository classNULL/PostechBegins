#include "cell.hpp"
int normal::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	//칸에 맞는 옵션을 출력하여 사용자로 부터 옵션을 선택하도록 한다.
	cin>>option;

	return 10+option;
}
int weekend::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 집가기"<<endl;
	cin>>option;

	return 10+option;
}

int march::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 밥사달라고하기"<<endl;
	cin>>option;
	if(option==6) option++;// option이 6일때 7로 바꿔줌
	return 10+option;
}
int before_exam::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;

	return 20+option
}
int exam::call_option(){
	return 30;
}

int after_exam::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 연애하기"<<endl;

	return 40+option;
}
int festival::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 집에 가기"<<endl;


	return 50+option;
}

int dance::call_option(){
	int option;
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 춤 연습하기"<<endl;


	return 60+option;
}

int special::call_option(){
	int option;
	cout<<"1. 참가한다"<<endl;
	cout<<"2. 참가하지 않는다"<<endl;

	return 70+option;
}
//아래와 같이 사용
select_option(_character,cell->call_option(),day);

void GameCenter::select_option(hero* _hero,int option,int day){
	if(option==11)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		_hero->change_energy(), _hero->change_study(2,day), _hero->change_relationship(-2,day), _hero->change_self_develop(0,day), _hero->change_love(0,day), _hero->change_stress(8,day);
	else if(option==12)
		_hero->change_energy(), _hero->change_study(-4,day), _hero->change_relationship(5,day), _hero->change_self_develop(0,day), _hero->change_love(1,day), _hero->change_stress(5,day);
	else if(option==13)
		_hero->change_energy(), _hero->change_study(-4,day), _hero->change_relationship(5,day), _hero->change_self_develop(1,day), _hero->change_love(1,day), _hero->change_stress(-3,day);
	else if(option==14)
		_hero->change_energy(), _hero->change_study(-4,day), _hero->change_relationship(-2,day), _hero->change_self_develop(0,day), _hero->change_love(5,day), _hero->change_stress(0,day);
	else if(option==15)
		_hero->change_energy(), _hero->change_study(0,day), _hero->change_relationship(0,day), _hero->change_self_develop(0,day), _hero->change_love(0,day), _hero->change_stress(-5,day);
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
void hero::change_study(int a, int day){study=study+(a+b)*day;}//b는 title로부터 오는 값
