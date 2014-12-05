#include "monthday.hpp"
#include <iostream>

using namespace std;

class month_event{
protected:
	Month month;
	bool successed = 0;
public:
	virtual wstring check_success()=0;
	Month get_month();
	virtual void reward()=0;
	virtual wstring introduction_message()=0;
};

class march_event : public month_event{
protected:
	Month month = Month::March;
public:
	wstring introduction_message();

	wstring check_success();
};

class april_event : public month_event{
protected:
	Month month = Month::April;
public:
	wstring introduction_message();
	wstring check_success();
};

class may_event : public month_event{
protected:
	Month month = Month::May;
public:
	wstring introduction_message();
	wstring check_success();
};

class june_event : public month_event{
protected:
	Month month = Month::June;
public:
	wstring introduction_message();
	wstring check_success();
};

class september_event : public month_event{
protected:
	Month month = Month::September;
public:
	wstring introduction_message();
	wstring check_success();
};

class october_event : public month_event{
protected:
	Month month = Month::October;
public:
	wstring introduction_message();
	wstring check_success();
};

class november_event : public month_event{
protected:
	Month month = Month::November;
public:
	wstring introduction_message();
	wstring check_success();
};

class december_event : public month_event{
protected:
	Month month = Month::December;
public:
	wstring introduction_message();
	wstring check_success();
};
