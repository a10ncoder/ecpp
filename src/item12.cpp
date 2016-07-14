/*
 * item12.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <string>

using namespace std;

class Customer {
public:

	Customer(string _name) :
			name(_name) {
	}

	Customer(const Customer& rhs) :
			name(rhs.name) {
	}

	Customer& operator=(const Customer rhs) {

		return const_cast<Customer&>(static_cast<const Customer&>(*this));
	}

	const Customer& operator=(const Customer rhs) const {
		name = rhs.name;
		return static_cast<const Customer&>(*this);
	}

	virtual string toString() {
		return name;
	}

private:
	mutable std::string name;
	int lastTransaction; // missing target
};

class PriorityCustomer: public Customer {
public:
	PriorityCustomer(string _string, int _priority) :
			Customer(_string), priority(_priority) {

	}
	PriorityCustomer(const PriorityCustomer& rhs) :
			Customer(rhs), priority(rhs.priority) {
	}
	PriorityCustomer& operator=(const PriorityCustomer& rhs) {
		Customer::operator=(static_cast<const Customer&>(rhs));
		priority = rhs.priority;
		return *this;
	}

	virtual string toString() {
		return Customer::toString() + std::to_string(priority);
	}

private:
	int priority;
};

int main() {
	PriorityCustomer c("hahaha", 54);
	cout << c.toString() << endl;
}

