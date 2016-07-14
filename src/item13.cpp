/*
 * item13.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */
#include <iostream>
#include <memory>
using namespace std;

class Investment {
public:
	Investment() {
		cout << "Investment()" << endl;
	}
	~Investment() {
		cout << "~Investment()" << endl;
	}
};

Investment* createInvestment() {
	return new Investment;
}

void f() {
	cout << "start void f()" << endl;
	auto_ptr<Investment> pInv(createInvestment());

	cout << "end void f()" << endl;
}

#if 0
void f() {
	cout << "start void f()" << endl;
	Investment* pInv = createInvestment();

	delete pInv;

	cout << "end void f()" << endl;
}
#endif

int main() {
	f();
}

