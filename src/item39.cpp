/*
 * item39.cpp
 *
 *  Created on: 2016. 7. 22.
 *      Author: sanghyuck.na
 */

#include <iostream>

class Empty {

};

/**
 * EBO=empty base optimization
 */
class HoldsAnInt: private Empty {
private:
	int x;

};

#ifdef NO2
class Empty {

};

class HoldsAnInt {
private:
	int x;
	Empty e;
};
#endif

class Timer {
public:
	explicit Timer(int tickFrequency) {

	}
	virtual void onTick() {

	}
	virtual ~Timer() {

	}
};

class Widget {
	virtual ~Widget() {

	}

	class WidgetTimer: public Timer {
	public:
		virtual void onTick() const {

		}
	};
private:
	WidgetTimer timer;
};

#ifdef NO1
class Timer {
public:
	explicit Timer(int tickFrequency) {

	}
	virtual void onTick() {

	}
	virtual ~Timer() {

	}
};

class Widget: private Timer {
private:
	virtual void onTick() {

	}
};

#endif

int main() {
	std::cout << "sizeof(HoldsAnInt)=" << sizeof(HoldsAnInt) << std::endl;

	return 0;
}
