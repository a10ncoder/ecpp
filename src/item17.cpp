/*
 * item17.cpp
 *
 *  Created on: 2016. 7. 15.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <tr1/memory>
using namespace std;

class Widget {

};

int priority() {
	return 1;
}

void processWidget(std::tr1::shared_ptr<Widget> pw, int p) {

}
int main() {
	std::tr1::shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());
}
#if 0
int main() {
	processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
}

#endif
