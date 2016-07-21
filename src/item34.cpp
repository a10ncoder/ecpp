/*
 * item34.cpp
 *
 *  Created on: 2016. 7. 20.
 *      Author: mailo
 */

#include <iostream>

class GameCharacter {
public:
	int healthValue() const {
		int retVal = doHealthValue();

		return retVal;
	}

	virtual ~GameCharacter() {

	}
private:
	virtual int doHealthValue() const {
		return 100;
	}
};

class Poketmon: public GameCharacter {
public:
	virtual ~Poketmon() {

	}
private:
	virtual int doHealthValue() const {
		return 200;
	}
};

#if 0
class GameCharacter {
public:
	virtual int healthValue const;
};

#endif

int main() {
	Poketmon p;

	std::cout << p.healthValue() << std::endl;
}

