#include "cell.hpp"

void cell::change(hero* _hero, float energy, float study, float relationship, float self_develop, float love, float stress, int day){
	_hero->change_energy(energy,day);
	_hero->change_study(study, day);
	_hero->change_relationship(relationship, day);
	_hero->change_self_develop(self_develop, day);
	_hero->change_love(love, day);
	//_hero->change_stress(stress, day);
}
void normal::call_option(hero* _hero,int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero,1, 2, -2, 0, 0, 8, day);
	else if (option == 2)
		change(_hero,1, -4, 5, 0, 1, 5, day);
	else if (option == 3)
		change(_hero,1, -4, 5, 1, 1, -3, day);
	else if (option == 4)
		change(_hero,1, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero,2, 0, 0, 0, 0, -5, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option == 1)
			change(_hero,2, 0, 0, 0, 0, -5, day);
	}

}
void weekend::call_option(hero* _hero,int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout << "6. 집가기" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, 2, -2, 0, 0, 8, day);
	else if (option == 2)
		change(_hero, 1, -4, 5, 0, 1, 5, day);
	else if (option == 3)
		change(_hero, 1, -4, 5, 1, 1, -3, day);
	else if (option == 4)
		change(_hero, 1, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 2, 0, 0, 0, 0, -5, day);
	else
		change(_hero, 3, 0, 0, 0, 0, 0, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cout<<"2. 집가기"<<endl;
		cin>>option;
		if(option == 1)
			change(_hero,2, 0, 0, 0, 0, -5, day);
		else if(option == 2)
			change(_hero, 3, 0, 0, 0, 0, 0, day);
	}
}

void march::call_option(hero* _hero,int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 밥사달라고하기"<<endl;
	cin>>option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero,1, 2, -2, 0, 0, 8, day);
	else if (option == 2)
		change(_hero,1, -4, 5, 0, 1, 5, day);
	else if (option == 3)
		change(_hero,1, -4, 5, 1, 1, -3, day);
	else if (option == 4)
		change(_hero,1, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero,2, 0, 0, 0, 0, -5, day);
	else if (option == 6)
		change(_hero,1, -2, 5, 0, 1, -3, day);
	}
	else
	{
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero,2, 0, 0, 0, 0, -5, day);
	}
}

void before_exam::call_option(hero* _hero,int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, 3, -1.6, 0, 0, 9.6, day);
	else if (option == 2)
		change(_hero, 1, -8, 6, 0, 1, 7.5, day);
	else if (option == 3)
		change(_hero, 1, -6, 6, 0.8, 1, -3.6, day);
	else if (option == 4)
		change(_hero, 1, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 2, -3, 0, 0, 0, -2.5, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero, 2, -3, 0, 0, 0, -2.5, day);
	}


}
void exam::call_option(hero* _hero,int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, 3, -1.6, 0, 0, 9.6, day);
	else if (option == 2)
		change(_hero, 1, -8, 6, 0, 1, 7.5, day);
	else if (option == 3)
		change(_hero, 1, -6, 6, 0.8, 1, -3.6, day);
	else if (option == 4)
		change(_hero, 1, -4, -2, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 2, -3, 0, 0, 0, -2.5, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero, 2, -6, 0, 0, 0, -1, day);
	}
}

void after_exam::call_option(hero* _hero,int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, 1.4, -4, 0, 0, 8, day);
	else if (option == 2)
		change(_hero, 1, -2, 7.5, 0, 1, 4, day);
	else if (option == 3)
		change(_hero, 1, -2, 6, 1, 1, -3, day);
	else if (option == 4)
		change(_hero, 1, -2, -3, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 2, 0, 0, 0, 0, -5, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero, 2, 0, 0, 0, 0, -5, day);
	}
}

void festival::call_option(hero* _hero, int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 연애하기" << endl;
	cout << "4. 휴식" << endl;
	cout << "5. 집가기" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, 2, -10, 0, 0, 8, day);
	else if (option == 2)
		change(_hero, 1, -0.8, 15, 0, 1, 4, day);
	else if (option == 3)
		change(_hero, 1, -4, -12, 0, 5, 0, day);
	else if (option == 4)
		change(_hero, 2, 0, -10, 0, 0, -4, day);
	else if (option == 5)
		change(_hero, 3, 0, -12, 0, 0, 0, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cout<<"2. 집가기"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero, 2, 0, -10, 0, 0, -4, day);
		else if(option==2)
			change(_hero, 3, 0, -12, 0, 0, 0, day);
	}
}

void dance::call_option(hero* _hero, int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cout << "6. 춤 연습하기" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, 2, -3, 0, 0, 8, day);
	else if (option == 2)
		change(_hero, 1, -4, 5, 0, 1, 5, day);
	else if (option == 3)
		change(_hero, 1, -4, 4, 1, 1, -3, day);
	else if (option == 4)
		change(_hero, 1, -4, -3, 0, 5, 0, day);
	else if (option == 5)
		change(_hero, 2, 0, -3, 0, 0, -5, day);
	else if (option == 6)
		change(_hero, 1, -4, 7, 0, 0, 6, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero, 2, 0, -3, 0, 0, -5, day);
	}
}

void special::call_option(hero* _hero, int day) {
	int option;
	if(get_energy_is_zero==false)
	{
	cout << "1. 참가한다" << endl;
	cout << "2. 참가하지 않는다" << endl;

	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		change(_hero, 1, -4, 8, 0, 0, 4, day);
	else if (option == 2)
		change(_hero, 1, 4, -8, 0, 0, -2, day);
	}
	else
	{
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero, 2, 0, -8, 0, 0, -5, day);
	}

}
