#include "monthday.h"
#include <iostream>
using namespace std;
class event_{
protected:
	Month month; 
	bool successed;
public:
	virtual bool check_success()=0;
	Month get_month();
	virtual void reward()=0;
	virtual void introduction_message()=0;
};
event_::event_(){
	successed = 0;
}
class march_event : public event_{

public:
	march_event();
	void introduction_message();
	bool success();
	void check_success();

};
march_event::march_event() : event_(){
	month = March;
}
void march_event::check_success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		cout<<"Mission Clear! 사람을 많이 사귀었나봐요?"<<endl;
		hero->up_event();
	}
}
void march_event::introduction_message(){
	cout<<"대학을 처음왔으면! 일단 친해져보자!"<<endl;
}


class april_event : public event_{

public:
	april_event();
	void introduction_message();
	bool success();
};
april_event::april_event(): event_(){
	month = April;
}
void april_event::introduction_message(){
	cout<<"중간고사 기간이네! 노는거도 이때해야 재밌지!"<<endl;
}
bool april_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenger->get_temp_study()>0){ //식별자 정의 필요
		cout<<"Mission Clear! 시험기간엔 공부해야죠! 무슨소리를!"<<endl;
		hero->up_event();
	}
}

class may_event : public event_{

public:
	may_event();
	void introduction_message();
	bool success();
};
may_event::may_event(): event_(){
	month = May;
}
void may_event::introduction_message(){
	cout<<"시험도 끝났겠다. 공부가 뭐죠?"<<endl;
}
bool may_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_self_develop()>15){ //식별자 정의 필요
		cout<<"Mission Clear! 동아리 활동도 열심히 해야죠!"<<endl;
		hero->up_event();
	}
}

class june_event : public event_{

public:
	june_event();
	void introduction_message();
	bool success();
};
june_event::june_event(): event_(){
	month = June;
}
void june_event::introduction_message(){
	cout<<"와 벌써 방학이 한달남았다. 기말엔 공부를 좀 해야될거 같은데...?"<<endl;
}
bool june_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		cout<<"Mission Clear! 기말고사는 던져야 제맛!"<<endl;
		hero->up_event();
	}
}

class september_event : public event_{

public:
	september_event();
	void introduction_message();
	bool success();
};
september_event::september_event(): event_(){
	month = September;
}
void september_event::introduction_message(){
	cout<<"2학기 개강이라능. 개총개총개총개총!"<<endl;
}
bool september_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		cout<<"술은 많이 드셨나요?!"<<endl;
		hero->up_event();
	}
}

class october_event : public event_{

public:
	october_event();
	void introduction_message();
	bool success();
};
october_event::october_event: event_()(){
	month = October;
}
void october_event::introduction_message(){
	cout<<"중간고사? 공부가 뭐죠? 그거 1학기에 보니 해도 안되더라. 님들 공부하지말고 카이스트 미꾸라지들 먼저 처리하죠 ㄱㄱ"<<endl;
}
bool october_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_love()>60){ //식별자 정의 필요
		hero->up_event();
	}
}

class november_event : public event_{

public:
	november_event();
	void introduction_message();
	bool success();
};
november_event::november_event: event_()(){
	month = November;
}
void november_event::introduction_message(){
	cout<<"우왕 시험 끝 ㅋ 동아리 축제고 POP고 할게많네"<<endl;
}
bool november_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_energy()<-40){ //식별자 정의 필요
		hero()->up_event();
	}
}

class december_event : public event_{

public:
	december_event();
	void introduction_message();
	bool success();
};
december_event::december_event: event_()(){
	month = December;
}
void december_event::introduction_message(){
	cout<<"와 1학기 있으면 후배들어옴. 신입생으로써 마지막을 불태우자 술 ㄱㄱ"<<endl;
}
bool december_event::success(hero* hero, gamecenter* _gamecenter){
	if(_gamecenter->get_temp_relationship()>60){ //식별자 정의 필요
		hero->up_event();
	}
}