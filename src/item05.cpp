/*
 * item05.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <string>




#if 1
template<typename T>
class NamedObject {
public:
	NamedObject(const char* name, const T& value) :
			nameValue(name), objectValue(value) {
	}
	NamedObject(const std::string name, const T& value) :
			nameValue(name), objectValue(value) {
	}

private:
	std::string nameValue;
	T objectValue;
};
#else
template<typename T>
class NamedObject {
public:
	NamedObject(const char* name, const T& value) :
			nameValue(name), objectValue(value) { // error
	}
	NamedObject(const std::string name, const T& value) :
			nameValue(name), objectValue(value) {
	}

private:
	std::string& nameValue;
	const T objectValue;
};
#endif

class Empty {
public:
	Empty() {
	}

	Empty(const Empty& rhs) {
	}

	Empty& operator=(const Empty& rhs) {
		return *this;
	}

	~Empty() {
	}

};

int main() {
	Empty e1; // default constructor
	Empty e2(e1); // copy constructor
	e2 = e1; // assignment operator

	std::cout << "main end" << std::endl;

	//de-constructor

	NamedObject<int> no1("Smallest Prime Number", 2);
	NamedObject<int> no2(no1);

}

