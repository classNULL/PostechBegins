#include "cell.hpp"

void cell::change(hero* _hero, PersonalStatus status_change, int day) {
	_hero->change_energy(status_change.energy, day);
	_hero->change_study(status_change.study, day);
	_hero->change_relationship(status_change.relationship, day);
	_hero->change_self_develop(status_change.self_develop, day);
	_hero->change_love(status_change.love, day);
	_hero->change_stress(status_change.stress, day);
}
void cell::change(hero* _hero, PersonalStatus status_change, PersonalStatus title_effect, int day) {
	if (status_change.energy > 0)
		_hero->change_energy(status_change.energy * title_effect.energy,day);
	else
		_hero->change_energy(status_change.energy, day);
	_hero->change_study(status_change.study * title_effect.study, day);
	_hero->change_relationship(status_change.relationship * title_effect.relationship, day);
	_hero->change_self_develop(status_change.self_develop * title_effect.self_develop, day);
	_hero->change_love(status_change.love * title_effect.love, day);
	_hero->change_stress(status_change.stress * title_effect.stress, day);
}

void normal::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout<<"1. 공부하기"<<endl;
		cout<<"2. 술마시기"<<endl;
		cout<<"3. 동아리 활동하기"<<endl;
		cout<<"4. 연애하기"<<endl;
		cout<<"5. 휴식"<<endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
				_hero->get_title_book().get_total_title_effect().study,
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
				_hero->get_title_book().get_total_title_effect().alcohol,
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
				_hero->get_title_book().get_total_title_effect().circle,
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().love,
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				_hero->get_title_book().get_total_title_effect().rest,
				day);
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option == 1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}
void weekend::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout<<"1. 공부하기"<<endl;
		cout<<"2. 술마시기"<<endl;
		cout<<"3. 동아리 활동하기"<<endl;
		cout<<"4. 연애하기"<<endl;
		cout<<"5. 휴식"<<endl;
		cout << "6. 집가기" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
				_hero->get_title_book().get_total_title_effect().study,
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
				_hero->get_title_book().get_total_title_effect().alcohol,
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
				_hero->get_title_book().get_total_title_effect().circle,
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().love,
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				_hero->get_title_book().get_total_title_effect().rest,
				day);
		else {
			change(_hero,
				{ .energy = 0, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().home,
				day);
			_hero->recover_energy();
		}
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cout<<"2. 집가기"<<endl;
		cin>>option;
		if(option == 1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
		else if(option == 2)
			change(_hero,
				{ .energy = 3, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 0 },
				day);
	}
}

void march::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout<<"1. 공부하기"<<endl;
		cout<<"2. 술마시기"<<endl;
		cout<<"3. 동아리 활동하기"<<endl;
		cout<<"4. 연애하기"<<endl;
		cout<<"5. 휴식"<<endl;
		cout<<"6. 밥사달라고하기"<<endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
		else if (option == 6)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 5, .self_develop = 0, .love = 1, .stress = -3 },
				day);
		//3월달은 어차피 칭호가 없음
	}
	else {
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}

void before_exam::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 연애하기" << endl;
		cout << "5. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 3, .relationship = -1.6, .self_develop = 0, .love = 0, .stress = 9.6 },
				_hero->get_title_book().get_total_title_effect().study,
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -8, .relationship = 6, .self_develop = 0, .love = 1, .stress = 7.5 },
				_hero->get_title_book().get_total_title_effect().alcohol,
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -6, .relationship = 6, .self_develop = 0.8, .love = 1, .stress = -3.6 },
				_hero->get_title_book().get_total_title_effect().circle,
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().love,
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
				_hero->get_title_book().get_total_title_effect().rest,
				day);
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero,
				{ .energy = 2, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
				day);
	}
}
void exam::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 연애하기" << endl;
		cout << "5. 휴식" << endl;
		cin >> option;
		if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
			change(_hero,
				{ .energy = 1, .study = 3, .relationship = -1.6, .self_develop = 0, .love = 0, .stress = 9.6 },
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = 1, .study = -8, .relationship = 6, .self_develop = 0, .love = 1, .stress = 7.5 },
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = 1, .study = -6, .relationship = 6, .self_develop = 0.8, .love = 1, .stress = -3.6 },
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 2, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
				day);
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero,
				{ .energy = 2, .study = -6, .relationship = 0, .self_develop = 0, .love = 0, .stress = -1 },
				day);
	}
}

void after_exam::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 연애하기" << endl;
		cout << "5. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 1.4, .relationship = -4, .self_develop = 0, .love = 0, .stress = 8 },
				_hero->get_title_book().get_total_title_effect().study,
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 7.5, .self_develop = 0, .love = 1, .stress = 4 },
				_hero->get_title_book().get_total_title_effect().alcohol,
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 6, .self_develop = 1, .love = 1, .stress = -3 },
				_hero->get_title_book().get_total_title_effect().circle,
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -3, .self_develop = 0, .love = 5, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().love,
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				_hero->get_title_book().get_total_title_effect().rest,
				day);
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}

void festival::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 연애하기" << endl;
		cout << "4. 휴식" << endl;
		cout << "5. 집가기" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -10, .self_develop = 0, .love = 0, .stress = 8 },
				_hero->get_title_book().get_total_title_effect().study,
				1);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -0.8, .relationship = 15, .self_develop = 0, .love = 1, .stress = 4 },
				_hero->get_title_book().get_total_title_effect().alcohol,
				1);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -12, .self_develop = 0, .love = 5, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().love,
				1);
		else if (option == 4)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = -10, .self_develop = 0, .love = 0, .stress = -4 },
				_hero->get_title_book().get_total_title_effect().rest,
				1);
		else if (option == 5) {
			change(_hero,
				{ .energy = 0, .study = 0, .relationship = -12, .self_develop = 0, .love = 0, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().home,
				1);
			_hero->recover_energy();
		}
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cout<<"2. 집가기"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = -10, .self_develop = 0, .love = 0, .stress = -4 },
				day);
		else if(option==2)
			change(_hero,
				{ .energy = 3, .study = 0, .relationship = -12, .self_develop = 0, .love = 0, .stress = 0 },
				day);
	}
}

void dance::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 연애하기" << endl;
		cout << "5. 휴식" << endl;
		cout << "6. 춤 연습하기" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -3, .self_develop = 0, .love = 0, .stress = 8 },
				_hero->get_title_book().get_total_title_effect().study,
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
				_hero->get_title_book().get_total_title_effect().alcohol,
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 1, .love = 1, .stress = -3 },
				_hero->get_title_book().get_total_title_effect().circle,
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 0, .love = 5, .stress = 0 },
				_hero->get_title_book().get_total_title_effect().love,
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = -5 },
				_hero->get_title_book().get_total_title_effect().rest,
				day);
		else if (option == 6)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 7, .self_develop = 0, .love = 0, .stress = 6 },
				day);
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}

void special::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "1. 참가한다" << endl;
		cout << "2. 참가하지 않는다" << endl;

		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 8, .self_develop = 0, .love = 0, .stress = 4 },
				1);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 4, .relationship = -8, .self_develop = 0, .love = 0, .stress = -2 },
				1);
	}
	else {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = -8, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}
void eve_1::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "학교에 태풍이 몰아닥쳤습니다. " << endl;
		cout << "1. 수업가기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 나들이" << endl;
		cout << "4. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 4, .relationship = -2, .self_develop = 0, .love = 0, .stress = 10 },
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 6, .self_develop = 0, .love = 2, .stress = 7 },
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 3, .stress = -2 },
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
	else {
		cout<<"학교에 태풍이 몰아닥쳤는데 에너지도 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}

void eve_2::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "과제가 밀려서 밤을 샜습니다. " << endl;
		cout << "1. 공부하기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 연애하기" << endl;
		cout << "5. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 1, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 0, .love = 1, .stress = 6 },
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 1, .love = 1, .stress = 1 },
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 4, .stress = 3 },
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
	else {
		cout<<"과제가 밀린 이유로 밤을 새서 에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}

void eve_3::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() != 0) {
		cout << "빨래를 안 해서 입을 옷이 없습니다. " << endl;
		cout << "1. 수업가기" << endl;
		cout << "2. 술마시기" << endl;
		cout << "3. 동아리 활동하기" << endl;
		cout << "4. 빨래하기" << endl;
		cout << "5. 옷 빌리기" << endl;
		cout << "6. 휴식" << endl;
		cin >> option;
		if (option == 1)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -5, .self_develop = 0, .love = 0, .stress = 8 },
				day);
		else if (option == 2)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 0, .love = -1, .stress = 5 },
				day);
		else if (option == 3)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 1, .love = -1, .stress = -3 },
				day);
		else if (option == 4)
			change(_hero,
				{ .energy = _hero->get_energy_consuming_rate(), .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = 1 },
				day);
		else if (option == 5)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 1, .self_develop = 0, .love = 0, .stress = -3 },
				day);
		else if (option == 6)
			change(_hero,
				{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
	else {
		cout<<"빨래가 밀렸는데 에너지도 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			change(_hero,
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
				day);
	}
}
