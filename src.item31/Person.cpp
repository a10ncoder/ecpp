/*
 * Person.cpp
 *
 *  Created on: 2016. 7. 20.
 *      Author: sanghyuck.na
 */

#if 0
#include "Person.h"

#include "PersonImpl.h"
#include <string>
#include <iostream>
Person::Person(const std::string& n) :
		pImpl(new PersonImpl(n)) {

}

const std::string& Person::getName() const {
	return pImpl->name;
}

void Person::toString() const {
	std::cout << "[Person name=" << getName() << "]" << std::endl;
}

#endif
