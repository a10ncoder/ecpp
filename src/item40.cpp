/*
 * item40.cpp
 *
 *  Created on: 2016. 7. 21.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <tr1/memory>
#include <string>
#include <cstring>

class IPerson {
public:
	virtual ~IPerson() {
	}
	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;
};

class PersonInfo {
public:
	explicit PersonInfo(int id) :
			theId(id) {
	}
	virtual ~PersonInfo() {
	}
	virtual const char* theName() const;
	virtual const char* theBirthDate() const;

private:
	virtual const char* valueDelimOpen() const;
	virtual const char* valueDelimClose() const;

	int theId;
};

const char* PersonInfo::valueDelimOpen() const {
	return "[";
}
const char* PersonInfo::valueDelimClose() const {
	return "]";
}

const char* PersonInfo::theName() const {
	static char value[1024];
	std::strcpy(value, valueDelimOpen());
	std::strcat(value, "at theName()");
	std::strcat(value, valueDelimClose());
	return value;
}

const char* PersonInfo::theBirthDate() const {
	static char value[1024];
	std::strcpy(value, "at theBirthDate()");
	return value;
}

class CPerson: public IPerson, private PersonInfo {
public:
	explicit CPerson(int pid) :
			PersonInfo(pid) {
	}

	virtual std::string name() const {
		return PersonInfo::theName();
	}
	virtual std::string birthDate() const {
		return PersonInfo::theBirthDate();
	}

private:
	virtual const char* valueDelimOpen() const {
		return "";
	}
	virtual const char* valueDelimClose() const {
		return "";
	}
};

std::tr1::shared_ptr<IPerson> makePerson(int id) {
	return std::tr1::shared_ptr<IPerson>(new CPerson(id));
}

#ifdef NO2
/*
 * virtual public inheritance
 * http://egloos.zum.com/Dplex/v/4308586
 */
class Borrowable {

};
class BorrowableItem: virtual public Borrowable {
public:
	void checkOut() {
		std::cout << "BorrowableItem.checkOut()" << std::endl;
	}
};

class Electronic {

};
class ElectronicGadget: virtual public Electronic {
public:
	void checkOut() const {
		std::cout << "ElectronicGadget.checkOut()" << std::endl;
	}
};

class Mp3Player: virtual public BorrowableItem, virtual public ElectronicGadget {
public:
	Mp3Player() :Borrowable(),
	BorrowableItem(), ElectronicGadget() {

	}
};
#endif

#ifdef NO1
class BorrowableItem {
public:
	void checkOut() {
		std::cout << "BorrowableItem.checkOut()" << std::endl;
	}
};

class ElectronicGadget {
public:
	void checkOut() const {
		std::cout << "ElectronicGadget.checkOut()" << std::endl;
	}
};

class Mp3Player: public BorrowableItem, public ElectronicGadget {

};
#endif

int main() {
	std::tr1::shared_ptr<IPerson> pp(makePerson(2));

	std::cout << "pp->name()=" << pp->name() << std::endl;

#ifdef NO2
	Mp3Player mp;
	mp.BorrowableItem::checkOut();

#endif

#ifdef NO1
	Mp3Player mp;
	//mp.checkOut();
	mp.BorrowableItem::checkOut();
#endif
}

