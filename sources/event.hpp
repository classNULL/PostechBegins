#ifndef EVENT_H
#define EVENT_H

#include "global.hpp"
#include "hero.hpp"
#include "monthday.hpp"
#include <iostream>

using namespace std;

class month_event{//각각 event의 base class
protected:
	Month month;//월 정보를 갖는다.

public:
	virtual wstring check_success(hero* hero, const PersonalStatus& increased_status) = 0;
	//이벤트 달성에 성공하였는지 체크하고 상황에 맞는 메시지를 return한다.
	Month get_month() const { return month; }
	//월 정보를 넘겨준다.
	virtual wstring introduction_message() const = 0;
	//이벤트를 설명하는 메시지를 전달한다. 즉, 이벤트 정보가 들어있다.
};

class march_event : public month_event{
	//각 월 별 이벤트는 base class를 상속받아 만들어진다.
protected:
	Month month = Month::March;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class april_event : public month_event{
protected:
	Month month = Month::April;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class may_event : public month_event{
protected:
	Month month = Month::May;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class june_event : public month_event{
protected:
	Month month = Month::June;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class september_event : public month_event{
protected:
	Month month = Month::September;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class october_event : public month_event{
protected:
	Month month = Month::October;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class november_event : public month_event{
protected:
	Month month = Month::November;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

class december_event : public month_event{
protected:
	Month month = Month::December;
public:
	wstring introduction_message() const;
	wstring check_success(hero* hero, const PersonalStatus& increased_status);
};

#endif
