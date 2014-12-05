#include "monthday.h"
#include <iostream>

using namespace std;

wstring march_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		
		hero->up_event();
		return L"Mission Clear! 사람을 많이 사귀었나봐요?";
	}
	return L"";
}
wstring march_event::introduction_message(){
	return L"대학을 처음왔으면! 일단 친해져보자!";
}

wstring april_event::introduction_message(){
	return L"중간고사 기간이네! 노는거도 이때해야 재밌지!";
}
wstring april_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenger->get_temp_study()>0){ //식별자 정의 필요
		
		hero->up_event();
		return L"Mission Clear! 시험기간엔 공부해야죠! 무슨소리를!";
	}
	return L"";
}

wstring may_event::introduction_message(){
	return L"시험도 끝났겠다. 공부가 뭐죠?";
}
wstring may_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_self_develop()>15){ //식별자 정의 필요
		
		hero->up_event();
		return L"Mission Clear! 동아리 활동도 열심히 해야죠!";
	}
	return L"";
}

wstring june_event::introduction_message(){
	return L"와 벌써 방학이 한달남았다. 기말엔 공부를 좀 해야될거 같은데...?";
}
wstring june_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		
		hero->up_event();
		return L"Mission Clear! 기말고사는 던져야 제맛!";
	}
	return L"";
}

wstring september_event::introduction_message(){
	return L"2학기 개강이라능. 개총개총개총개총!";
}
wstring september_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		
		hero->up_event();
		return L"술은 많이 드셨나요?!";
	}
	return L"";
}

wstring october_event::introduction_message(){
	return L"중간고사? 공부가 뭐죠? 그거 1학기에 보니 해도 안되더라. 님들 공부하지말고 카이스트 미꾸라지들 먼저 처리하죠 ㄱㄱ";
}
wstring october_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_love()>60){ //식별자 정의 필요
		hero->up_event();
		
	}
}

void november_event::introduction_message(){
	cout<<"우왕 시험 끝 ㅋ 동아리 축제고 POP고 할게많네"<<endl;
}
bool november_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_energy()<-40){ //식별자 정의 필요
		hero()->up_event();
	}
}

void december_event::introduction_message(){
	cout<<"와 1학기 있으면 후배들어옴. 신입생으로써 마지막을 불태우자 술 ㄱㄱ"<<endl;
}
bool december_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		hero->up_event();
	}
}
