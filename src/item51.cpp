/*
 * item51.cpp
 *
 *  Created on: 2016. 7. 26.
 *      Author: sanghyuck.na
 */

#include<iostream>

class Base {
public:
	static void* operator new(std::size_t size) throw (std::bad_alloc) {
		if (size != sizeof(Base)) {
			return ::operator new(size);

		}
		return malloc(size);
	}

	static void operator delete(void* r, std::size_t size) throw () {

		if (r == 0)
			return;
		if (size != sizeof(Base)) {
			::operator delete(r);
			return;
		}

		free(r);
	}
};

class Derived: public Base {

};

void* operator new(std::size_t size) throw (std::bad_alloc) {
	using namespace std;

	if (size == 0) {
		size = 1;
	}

	void *p = 0;

	while (true) {
		p = malloc(size);
		if (p)
			return p;
		std::new_handler g = set_new_handler(0);
		set_new_handler(g);
		if (g)
			(*g)();
		else
			throw bad_alloc();
	}
}

void operator delete(void* p) throw () {
	if (p == 0)
		return;

	::delete (p);
}

int main() {
	Derived *p = new Derived;
	delete p;
}

