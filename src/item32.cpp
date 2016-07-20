/*
 * item32.cpp
 *
 *  Created on: 2016. 7. 20.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <exception>
#include <assert.h>

class Rectangle {
public:
	virtual void setHeight(int newHeight)=0;
	virtual void setWidth(int newWidht)=0;
	virtual int height() const=0;
	virtual int width() const=0;

	virtual ~Rectangle() {
	}
};

void makeBigger(Rectangle& r) {
	int oldHeight = r.height();
	r.setWidth(r.width() + 10);
	assert(r.height() == oldHeight);
}

class Square: public Rectangle {

private:
	int w;
	int h;

public:
	Square(int _w, int _h) :
			w(_w), h(_h) {

	}
	virtual void setHeight(int newHeight) {
		h = newHeight;
	}
	virtual void setWidth(int newWidht) {
		w = newWidht;
	}
	virtual int height() const {
		return w;
	}
	virtual int width() const {
		return h;
	}
};

#if 0
class Bird {
public:
	virtual ~Bird() {

	}
	virtual void fly();
};

class Penguin: public Bird {
public:
	virtual ~Penguin() {

	}
};
#endif

#if 0
class Bird {
public:
	virtual ~Bird() {

	}
	virtual void fly() {
		std::cout << "Bird.fly()" << std::endl;
	}
};

class Penguin: public Bird {
public:
	virtual ~Penguin() {

	}
	virtual void fly() {
		throw std::exception();
	}
};
#endif

#if 0
class Bird {
public:
	virtual ~Bird() {

	}
};

class Penguin: public Bird {
public:
	virtual ~Penguin() {

	}
	virtual void fly() {
		std::cout << "Penguin.fly()" << std::endl;
	}
};

#endif

#if 0
class Bird {
public:
	virtual ~Bird() {

	}
	virtual void fly() {
		std::cout << "Bird.fly()" << std::endl;
	}
};

class Penguin: public Bird {
public:
	virtual ~Penguin() {

	}
	virtual void fly() {
		std::cout << "Penguin.fly()" << std::endl;
	}
};

#endif

#if 0
class Person {

};

class Student: public Person {

};

#endif

int main() {
#if 0
	Bird b;
	Penguin p;

	try {
		p.fly();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
#endif

#if 0
	Penguin p;
#endif

	Square s(20, 20);

	assert(s.width() == s.height());
	makeBigger(s);
	assert(s.width() == s.height());
}

