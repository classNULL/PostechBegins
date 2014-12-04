#include "cell.hpp"

void normal::call_option(hero* _hero,int day) {
	if (_hero->get_energy() == 0)
		return this->call_option_zero(_hero, day);

	if (rand() % 100 == 1)
		return this->call_option_special(_hero, day);

	vector<cell_option> options;

	options.push_back(cell_option("공부하기", [&_hero, day]() {
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
			_hero->get_title_book().get_total_title_effect().study,
			day);
	}));
	options.push_back(cell_option("술마시기", [&_hero, day]() {
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
			_hero->get_title_book().get_total_title_effect().alcohol,
			day);
	}));
	options.push_back(cell_option("동아리 활동하기", [&_hero, day]() {
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
			_hero->get_title_book().get_total_title_effect().circle,
			day);
	}));
	options.push_back(cell_option("연애하기", [&_hero, day]() {
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().love,
			day);
	}));
	options.push_back(cell_option("휴식", [&_hero, day]() {
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			_hero->get_title_book().get_total_title_effect().rest,
			day);
	}));

	return cell_option_book(options);
}
void normal::call_option_zero(hero* _hero, int day) {
	vector<cell_option> options;

	options.push_back(cell_option("휴식", [&_hero, day]() {
		_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);
	}));

	return cell_option_book("에너지가 부족합니다.", options);
}
void normal::call_option_special(hero* _hero, int day) {
	vector<cell_option> options;

	options.push_back(cell_option("공부하기", [&_hero, day]() {
		_hero->change(
			{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
			day);
		return "날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다.";
	}));
	options.push_back(cell_option("술마시기", [&_hero, day]() {
		_hero->change(
			{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
			day);
		return "....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다..";
	}));
	options.push_back(cell_option("연애하기", [&_hero, day]() {
		bool is_inLove = _hero->get_title_book().has_title("couple");
		if(is_inLove){
			_hero->get_title_book().remove_title("couple");
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
				day);
			return "........오늘 헤어졌다.아..스트레스 받아.....";
		}
		else {
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
				day);
			return "....어장관리 당했다....괜히 시간만 날렸다..";
		}
	}));
	options.push_back(cell_option("휴식", [&_hero, day]() {
		_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
			day);
		return "..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다...";
	}));

	return cell_option_book(options);
}

void weekend::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cout<<"2. 집가기"<<endl;
		cin>>option;
		if(option == 1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);
			else if(option == 2)
			_hero->change(
			{ .energy = 3, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 0 },
			day);

		return;
	}

	if (rand() % 100 == 1) {
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				 day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
				 day);
		}
		else if(option==4){
			bool is_inLove = _hero->get_title_book().has_title("couple");
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->get_title_book().remove_title("couple");
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
					 day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
					 day);
			}
		}
		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
				 day);
		}
		else if(option==6){
			cout<<"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다...."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 3, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 3 },
				 day);
		}

		return;
	}

	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout << "6. 집가기" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
			_hero->get_title_book().get_total_title_effect().study,
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
			_hero->get_title_book().get_total_title_effect().alcohol,
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
			_hero->get_title_book().get_total_title_effect().circle,
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().love,
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			_hero->get_title_book().get_total_title_effect().rest,
			day);
	else {
		_hero->change(
			{ .energy = 0, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().home,
			day);
		_hero->recover_energy();
	}
}

void march::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}
	if (rand() % 100 == 1) {
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				 day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
				 day);
		}
		else if(option==4){
			bool is_inLove = _hero->get_title_book().has_title("couple");
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->get_title_book().remove_title("couple");
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
					 day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
					 day);
			}
		}
		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
				 day);
		}

		return;
	}

	cout<<"1. 공부하기"<<endl;
	cout<<"2. 술마시기"<<endl;
	cout<<"3. 동아리 활동하기"<<endl;
	cout<<"4. 연애하기"<<endl;
	cout<<"5. 휴식"<<endl;
	cout<<"6. 밥사달라고하기"<<endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 8 },
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 1, .love = 1, .stress = -3 },
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);
	else if (option == 6)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 5, .self_develop = 0, .love = 1, .stress = -3 },
			day);
	//3월달은 어차피 칭호가 없음
}

void before_exam::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			_hero->change(
			{ .energy = 2, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
			day);

		return;
	}
	if (rand() % 100 == 1) {
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				 day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
				 day);
		}
		else if(option==4){
			bool is_inLove = _hero->get_title_book().has_title("couple");
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->get_title_book().remove_title("couple");
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
					 day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
					 day);
			}
		}
		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
				 day);
		}

		return;
	}

	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 3, .relationship = -1.6, .self_develop = 0, .love = 0, .stress = 9.6 },
			_hero->get_title_book().get_total_title_effect().study,
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -8, .relationship = 6, .self_develop = 0, .love = 1, .stress = 7.5 },
			_hero->get_title_book().get_total_title_effect().alcohol,
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -6, .relationship = 6, .self_develop = 0.8, .love = 1, .stress = -3.6 },
			_hero->get_title_book().get_total_title_effect().circle,
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().love,
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
			_hero->get_title_book().get_total_title_effect().rest,
			day);
}
void exam::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			_hero->change(
			{ .energy = 2, .study = -6, .relationship = 0, .self_develop = 0, .love = 0, .stress = -1 },
			day);

		return;
	}

	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)//변화량이 0이라도 적어주는 이유는 칭호를 고려하였기 때문
		_hero->change(
			{ .energy = 1, .study = 3, .relationship = -1.6, .self_develop = 0, .love = 0, .stress = 9.6 },
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = 1, .study = -8, .relationship = 6, .self_develop = 0, .love = 1, .stress = 7.5 },
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = 1, .study = -6, .relationship = 6, .self_develop = 0.8, .love = 1, .stress = -3.6 },
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = 5, .stress = 0 },
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 2, .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2.5 },
			day);
}

void after_exam::call_option(hero* _hero,int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}
	if (rand() % 100 == 1) {
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				 day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
				 day);
		}
		else if(option==4){
			bool is_inLove = _hero->get_title_book().has_title("couple");
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->get_title_book().remove_title("couple");
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
					 day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
					 day);
			}
		}
		else if(option==5){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
				 day);
		}

		return;
	}

	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 1.4, .relationship = -4, .self_develop = 0, .love = 0, .stress = 8 },
			_hero->get_title_book().get_total_title_effect().study,
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 7.5, .self_develop = 0, .love = 1, .stress = 4 },
			_hero->get_title_book().get_total_title_effect().alcohol,
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = 6, .self_develop = 1, .love = 1, .stress = -3 },
			_hero->get_title_book().get_total_title_effect().circle,
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -2, .relationship = -3, .self_develop = 0, .love = 5, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().love,
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			_hero->get_title_book().get_total_title_effect().rest,
			day);
}

void festival::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cout<<"2. 집가기"<<endl;
		cin>>option;
		if (option == 1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = -10, .self_develop = 0, .love = 0, .stress = -4 },
			day);
			else if(option==2)
			_hero->change(
			{ .energy = 3, .study = 0, .relationship = -12, .self_develop = 0, .love = 0, .stress = 0 },
			day);

		return;
	}
	if (rand() % 100 == 1) {
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				 day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
				 day);
		}
		else if(option==3){
			bool is_inLove = _hero->get_title_book().has_title("couple");
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->get_title_book().remove_title("couple");
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
					 day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
					 day);
			}
		}
		else if(option==4){
			cout<<"..퀴즈 점수가 나왔다..나는 먼지같은 인간이다..이 상황에 쉴 생각을 하다니.. 쉬어도 쉰 것 같지 않다..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -2 },
				 day);
		}
		else if(option==5){
			cout<<"..알고보니 나는 제주도 사람이었다... 비행기가 결항되어 집에 갈 수 없다...."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 3, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = 3 },
				 day);
		}

		return;
	}

	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 연애하기" << endl;
	cout << "4. 휴식" << endl;
	cout << "5. 집가기" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -10, .self_develop = 0, .love = 0, .stress = 8 },
			_hero->get_title_book().get_total_title_effect().study,
			1);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -0.8, .relationship = 15, .self_develop = 0, .love = 1, .stress = 4 },
			_hero->get_title_book().get_total_title_effect().alcohol,
			1);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -12, .self_develop = 0, .love = 5, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().love,
			1);
	else if (option == 4)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = -10, .self_develop = 0, .love = 0, .stress = -4 },
			_hero->get_title_book().get_total_title_effect().rest,
			1);
	else if (option == 5) {
		_hero->change(
			{ .energy = 0, .study = 0, .relationship = -12, .self_develop = 0, .love = 0, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().home,
			1);
		_hero->recover_energy();
	}
}

void dance::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if (option == 1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}
	if (rand() % 100 == 1) {
		if(option==1){
			cout<<"날씨가 너무 화창한 바람에 공부가 되지 않는다...괜히 시간만 날렸다."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -2, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
				 day);
		}
		else if(option==2){
			cout<<"....실연당한 친구의 이야기를 들어주며 술을 마셨다..같은 이야기만 38번들었다..괜히 시간만 날렸다.."<<endl;
			//히어로, 에너지, 스터디, 릴레이션십,자기계발,러브,스트레스,day
			_hero->change(
				{ .energy = 1, .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 6 },
				 day);
		}
		else if(option==4){
			bool is_inLove = _hero->get_title_book().has_title("couple");
			if(is_inLove){
				cout<<"........오늘 헤어졌다.아..스트레스 받아....."<<endl;
				_hero->get_title_book().remove_title("couple");
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -15, .stress = 15 },
					 day);
			}
			else{
				cout<<"....어장관리 당했다....괜히 시간만 날렸다.."<<endl;
				//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
				_hero->change(
					{ .energy = 1, .study = -4, .relationship = -2, .self_develop = 0, .love = -8, .stress = 6 },
					 day);
			}
		}

		else if(option==5){
			cout<<"..헉 몰래 쉰 것을 선배들한테 들켰다 ㅜㅜㅜ 망했다..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = 5 },
				 day);
		}
		else if(option==6){
			cout<<"..다리를 삐어서 춤연습을 제대로 할 수 없다 ㅜㅜ..."<<endl;
			//히어로,       에너지,              스터디,          릴레이션십,       자기계발,       러브,           스트레스,day
			_hero->change(
				{ .energy = 2, .study = 0, .relationship = 2, .self_develop = 0, .love = 0, .stress = 5 },
				 day);
		}

		return;
	}

	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cout << "6. 춤 연습하기" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -3, .self_develop = 0, .love = 0, .stress = 8 },
			_hero->get_title_book().get_total_title_effect().study,
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 1, .stress = 5 },
			_hero->get_title_book().get_total_title_effect().alcohol,
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 1, .love = 1, .stress = -3 },
			_hero->get_title_book().get_total_title_effect().circle,
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 0, .love = 5, .stress = 0 },
			_hero->get_title_book().get_total_title_effect().love,
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = -3, .self_develop = 0, .love = 0, .stress = -5 },
			_hero->get_title_book().get_total_title_effect().rest,
			day);
	else if (option == 6)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 7, .self_develop = 0, .love = 0, .stress = 6 },
			day);
}

void special::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = -8, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}

	cout << "1. 참가한다" << endl;
	cout << "2. 참가하지 않는다" << endl;

	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 8, .self_develop = 0, .love = 0, .stress = 4 },
			1);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 4, .relationship = -8, .self_develop = 0, .love = 0, .stress = -2 },
			1);
}
void eve_1::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"학교에 태풍이 몰아닥쳤는데 에너지도 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}

	cout << "학교에 태풍이 몰아닥쳤습니다. " << endl;
	cout << "1. 수업가기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 나들이" << endl;
	cout << "4. 휴식" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 4, .relationship = -2, .self_develop = 0, .love = 0, .stress = 10 },
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 6, .self_develop = 0, .love = 2, .stress = 7 },
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 5, .self_develop = 0, .love = 3, .stress = -2 },
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);
}

void eve_2::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"과제가 밀린 이유로 밤을 새서 에너지가 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}

	cout << "과제가 밀려서 밤을 샜습니다. " << endl;
	cout << "1. 공부하기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 연애하기" << endl;
	cout << "5. 휴식" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 1, .relationship = -2, .self_develop = 0, .love = 0, .stress = 9 },
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 0, .love = 1, .stress = 6 },
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = 4, .self_develop = 1, .love = 1, .stress = 1 },
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -2, .self_develop = 0, .love = 4, .stress = 3 },
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);
}

void eve_3::call_option(hero* _hero, int day) {
	int option;
	if (_hero->get_energy() == 0) {
		cout<<"빨래가 밀렸는데 에너지도 부족합니다. "<<endl;
		cout<<"1. 휴식"<<endl;
		cin>>option;
		if(option==1)
			_hero->change(
			{ .energy = 2, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);

		return;
	}

	cout << "빨래를 안 해서 입을 옷이 없습니다. " << endl;
	cout << "1. 수업가기" << endl;
	cout << "2. 술마시기" << endl;
	cout << "3. 동아리 활동하기" << endl;
	cout << "4. 빨래하기" << endl;
	cout << "5. 옷 빌리기" << endl;
	cout << "6. 휴식" << endl;
	cin >> option;
	if (option == 1)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = 2, .relationship = -5, .self_develop = 0, .love = 0, .stress = 8 },
			day);
	else if (option == 2)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 0, .love = -1, .stress = 5 },
			day);
	else if (option == 3)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -4, .relationship = -3, .self_develop = 1, .love = -1, .stress = -3 },
			day);
	else if (option == 4)
		_hero->change(
			{ .energy = _hero->get_energy_consuming_rate(), .study = -3, .relationship = 0, .self_develop = 0, .love = 0, .stress = 1 },
			day);
	else if (option == 5)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 1, .self_develop = 0, .love = 0, .stress = -3 },
			day);
	else if (option == 6)
		_hero->change(
			{ .energy = 8, .study = 0, .relationship = 0, .self_develop = 0, .love = 0, .stress = -5 },
			day);
}
