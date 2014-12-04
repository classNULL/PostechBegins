#include "monthday.hpp"
#include <iostream>

using namespace std;

class month_event{
protected:
	Month month;
	bool successed = 0;
public:
	virtual bool check_success()=0;
	Month get_month();
	virtual void reward()=0;
	virtual void introduction_message()=0;
};

class march_event : public month_event{
protected:
	Month month = Month::March;
public:
	void introduction_message();
	bool success();
	void check_success();
};

class april_event : public month_event{
protected:
	Month month = Month::April;
public:
	void introduction_message();
	bool success();
};

class may_event : public month_event{
protected:
	Month month = Month::May;
public:
	void introduction_message();
	bool success();
};

class june_event : public month_event{
protected:
	Month month = Month::June;
public:
	void introduction_message();
	bool success();
};

class september_event : public month_event{
protected:
	Month month = Month::September;
public:
	void introduction_message();
	bool success();
};

class october_event : public month_event{
protected:
	Month month = Month::October;
public:
	void introduction_message();
	bool success();
};

class november_event : public month_event{
protected:
	Month month = Month::November;
public:
	void introduction_message();
	bool success();
};

class december_event : public month_event{
protected:
	Month month = Month::December;
public:
	void introduction_message();
	bool success();
};
