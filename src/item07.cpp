/*
 * item07.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */

#include <iostream>

using namespace std;

class AWOV {
public:
	/*
	 * 만약 definition을 지금처럼 정의안하면 linker error가 발생
	 */
	virtual ~AWOV() = 0;

};

class TimeKeeper {
public:
	TimeKeeper() {
		cout << "TimeKeeper()" << endl;
	}
	virtual ~TimeKeeper() {
		cout << "~TimeKeeper()" << endl;
	}
};

class AtomicClock: public TimeKeeper {
public:
	AtomicClock() {
		cout << "AtomicClock()" << endl;
	}
	~AtomicClock() {
		cout << "~()" << endl;
	}
};

class WaterClock: public TimeKeeper {
public:
	WaterClock() {
		cout << "WaterClock()" << endl;
	}
	~WaterClock() {
		cout << "~WaterClock()" << endl;
	}
};

class WristWatch: public TimeKeeper {
public:
	WristWatch() {
		cout << "WristWatch()" << endl;
	}
	~WristWatch() {
		cout << "~WristWatch()" << endl;
	}
};

TimeKeeper* getTimeKeeper() {
	return new WristWatch;
}

int main() {
	TimeKeeper* tk = getTimeKeeper();
	AWOV* awov = NULL;

	delete tk;
}

