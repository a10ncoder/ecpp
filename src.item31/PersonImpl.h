/*
 * PersonImpl.h
 *
 *  Created on: 2016. 7. 20.
 *      Author: sanghyuck.na
 */

#ifndef PERSONIMPL_H_
#define PERSONIMPL_H_

#include <string>
#include <tr1/memory>

#include <Person.h>
class RealPerson: public Person {
public:
	RealPerson(const std::string& n) :
			name(n) {
	}

	virtual ~RealPerson() {
	}

	virtual const std::string getName() const {
		return name;
	}

	virtual void toString() const {
		std::cout << "[Person name=" << getName() << "]" << std::endl;
	}

private:
	std::string name;
};

std::tr1::shared_ptr<Person> Person::create(const std::string& name) {
	return std::tr1::shared_ptr<Person>(new RealPerson(name));
}

#if 0
struct PersonImpl {
	std::string name;

	PersonImpl(const std::string& n) :
	name(n) {

	}
};
#endif

#endif /* PERSONIMPL_H_ */

