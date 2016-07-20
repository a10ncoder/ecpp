/*
 * Person.h
 *
 *  Created on: 2016. 7. 20.
 *      Author: sanghyuck.na
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <tr1/memory>

class Person {
public:
	virtual ~Person() {};
	virtual const std::string getName() const = 0;
	virtual void toString() const = 0;

	static std::tr1::shared_ptr<Person>
	create(const std::string& name);
};


#if 0
class PersonImpl;

class Person {

private:
	std::tr1::shared_ptr<PersonImpl> pImpl;
public:
	Person(const std::string& n);
	const std::string& getName() const;

	void toString() const;
};
#endif

#endif /* PERSON_H_ */
