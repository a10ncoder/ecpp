/*
 * item54.cpp
 *
 *  Created on: 2016. 7. 26.
 *      Author: sanghyuck.na
 */
#include <iostream>
#include <tr1/array>
namespace std {
//namespace tr1 = ::boost;
}
;

//http://aristeia.com/EC3E/TR1_info.html

int main() {
	std::tr1::array<int, 4> x = { 0, 1, 2, 3 };
	std::cout << x.size() << std::endl;
	for (auto it = x.begin(); it != x.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

}

