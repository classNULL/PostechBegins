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
class march_event : public event_{

public:
	march_event();
	void introduction_message();
	bool success();
	void check_success();

};
class april_event : public event_{

public:
	april_event();
	void introduction_message();
	bool success();
};
class may_event : public event_{

public:
	may_event();
	void introduction_message();
	bool success();
};
class june_event : public event_{

public:
	june_event();
	void introduction_message();
	bool success();
};
class september_event : public event_{

public:
	september_event();
	void introduction_message();
	bool success();
};
class october_event : public event_{

public:
	october_event();
	void introduction_message();
	bool success();
};
class november_event : public event_{

public:
	november_event();
	void introduction_message();
	bool success();
};
class december_event : public event_{
public:
	december_event();
	void introduction_message();
	bool success();
};
