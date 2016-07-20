/*
 * item33.cpp
 *
 *  Created on: 2016. 7. 20.
 *      Author: sanghyuck.na
 */

#include <iostream>

class Base { // 1
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int t) {
		std::cout << "Base::mf1(int)" << t << std::endl;
	}

	virtual void mf2() {
	}

	void mf3() {
	}
	void mf3(double) {
	}

	virtual ~Base() {
	}
};

class Derived: private Base { // 2
public:

	virtual void mf1() {
		Base::mf1(20); // forwarding function
	}
	void mf3() {
	}
	void mf4() {

	}
};

// 3 error

int main() {

	Derived d;

	d.mf1();
}

#if 0
class Base { // 1
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf1(int) {
	}

	virtual void mf2() {
	}

	void mf3() {
	}
	void mf3(double) {
	}

	virtual ~Base() {
	}
};

class Derived: public Base { // 2
public:
	using Base::mf1;
	using Base::mf3;

	virtual void mf1() {
	}
	void mf3() {
	}
	void mf4() {

	}
};

// 3 error

int main() {

	Derived d;
	int x = 50;

	d.mf1();
	d.mf1(x);
	d.mf2();

	d.mf3();
	d.mf3(x);
}

#endif

#if 0
class Base {
private:
	int x;
public:
	virtual void mf1() = 0;
	virtual void mf2();
	void mf3();

	virtual ~Base() {
	}
};

class Derived: public Base {
public:
	virtual void mf1();
	void mf4() {
		mf2();

	}
};
#endif
