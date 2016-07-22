/*
 * item36.cpp
 *
 *  Created on: 2016. 7. 22.
 *      Author: sanghyuck.na
 */

#include <iostream>

class B {
public:
	void mf() {
		std::cout << "B.mf()" << std::endl;
	}

};

class D: public B {
public:
	void mf() {
		std::cout << "D.mf()" << std::endl;
	}
};

int main() {
	D x;
	B*pb = &x;
	pb->mf();
	D*pd = &x;
	pd->mf();
}

