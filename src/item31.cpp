/*
 * item31.cpp
 *
 *  Created on: 2016. 7. 20.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include "PersonImpl.h"


int main() {

#if 0
	Person p("James");
	p.toString();
#endif

	std::tr1::shared_ptr<Person> p(Person::create("James"));
	p->toString();
}
