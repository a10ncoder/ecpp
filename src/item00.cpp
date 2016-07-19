/*
 * Item00.cpp
 *
 *  Created on: 2016. 7. 12.
 *      Author: mailo
 */
#include <iostream>

int x; // object def

std::size_t numDIgits(int number) { // function def
	std::size_t digitsSoFar = 1;
	while ((number /= 10) != 0)
		++digitsSoFar;
	return digitsSoFar;
}

template<typename T>
class GraphNode { // template def
public:
	GraphNode() {
	}
	~GraphNode() {
	}
};

class B {
public:
	explicit B(int x = 0, bool b = true) {
		// explicit type casting
	}
};

void doSomething(B obj) {

}

class Widget {  // class def
public:
	Widget() { //default ctor
	}
	Widget(const Widget& rhs) { // copy ctor
	}

	Widget& operator=(const Widget& rhs) { // copy assign operator
		return *this;
	}

	~Widget() { //dtor
	}
};

int main() {
	std::cout << "item00" << std::endl;

	doSomething(B(23)); // copy ctor
	//doSomething(23); // errors
	B obj2(32);

	///////////////////////
	Widget w1; //default ctor
	Widget w2(w1); //copy ctor
	w1 = w2; // copy assignment

	///////////////////////

	int *p = 0;
	//std::cout << *p; // undefined behavior

	char name[] = "asdfasdf";
	char c = name[10]; // undefined behavior
	//boost.org
}

