/*
 * item38.c
 *
 *  Created on: 2016. 7. 22.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <string>
#include <list>

template<typename T>
class Set {
public:
	bool member(const T& i) const;
	void insert(const T& i);
	void remove(const T& i);
	std::size_t size() const;
private:
	std::list<T> rep;
};

template<typename T>
bool Set<T>::member(const T& i) const {
	return std::find(rep.begin(), rep.end(), i) != rep.end();
}
template<typename T>
void Set<T>::insert(const T& i) {
	if (!member(i)) {
		rep.push_back(i);
	}
}

template<typename T>
void Set<T>::remove(const T& i) {
	typename std::list<T>::iterator it = std::find(rep.begin(), rep.end(), i);

	if (it != rep.end()) {
		rep.erase(it);
	}
}

template<typename T>
std::size_t Set<T>::size() const {
	return rep.size();
}

#ifdef NO2
template<typename T>
class Set: public std::list<T> {

};
#endif

#ifdef NO1
class Address {
};
class PhoneNumber {
};

class Person {
public:
private:
	std::string name;
	Address address;
	PhoneNumber pMobile;
	PhoneNumber pFax;
};
#endif

int main() {

}

