/*
 * item48.cpp
 *
 *  Created on: 2016. 7. 25.
 *      Author: sanghyuck.na
 */

#include <iostream>

template<unsigned n>
struct Factorial {
	enum {
		value = n * Factorial<n - 1>::value
	};
};

template<>
struct Factorial<0> {
	enum {
		value = 1
	};
};

int main() {
	Factorial<2> t;
	std::cout << "factorial=" << t.value << std::endl;
	std::cout << "factorial=" << Factorial<10>::value << std::endl;
}

