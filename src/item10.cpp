/*
 * item10.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */

#include <iostream>

using namespace std;

class Widget {
public:
	Widget& operator=(const Widget& rhs) {
		return *this;
	}

	Widget& operator=(int rhs) {
		return *this;
	}

	Widget& operator+=(const Widget& rhs) {
		return *this;
	}
};

int main() {

}

