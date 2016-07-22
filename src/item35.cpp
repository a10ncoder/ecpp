/*
 * item35.cpp
 *
 *  Created on: 2016. 7. 21.
 *      Author: mailo
 */

#include <iostream>
#include <functional>

class GameCharacter;
class HelathCalcFunc {
public:
	HelathCalcFunc() {
	}

	virtual int calc(const GameCharacter& gc) const {
		return 0;
	}

	virtual ~HelathCalcFunc() {
	}
};

HelathCalcFunc defaultHealthCalc;

class GameCharacter {
public:
	explicit GameCharacter(HelathCalcFunc *hfc = &defaultHealthCalc) :
			healthFunc(hfc) {

	}

	int healthValue() const {
		return healthFunc->calc(*this);
	}

private:
	HelathCalcFunc* healthFunc;
};

#ifdef NO3
class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);

class GameCharacter {
public:
	typedef std::function<int(const GameCharacter&)> HealthCalcFunc;

	explicit GameCharacter(HealthCalcFunc hfc = defaultHealthCalc) :
	healthFunc(hfc) {
	}

	int healthValue() const {
		return healthFunc(*this);
	}

private:
	HealthCalcFunc healthFunc;
};
int defaultHealthCalc(const GameCharacter& gc) {
	return 2;
}

short calcHealth(const GameCharacter&) {
	return -1;
}
struct HealthCalculator {
	int operator()(const GameCharacter&) const {
		return 0;
	}
};
class GameLevel {
public:
	float health(const GameCharacter&) const {
		return 1;
	}
};

class EvilBadGuy: public GameCharacter {
public:
	explicit EvilBadGuy(HealthCalcFunc hfc = defaultHealthCalc) :
	GameCharacter(hfc) {

	}
};

class EyeCandyCharacter: public GameCharacter {
public:
	explicit EyeCandyCharacter(HealthCalcFunc hfc = defaultHealthCalc) :
	GameCharacter(hfc) {

	}
};
#endif

#ifdef NO2
class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);

class GameCharacter {
public:
	typedef int (*HealthCalcFunc)(const GameCharacter&);

	explicit GameCharacter(HealthCalcFunc hfc = defaultHealthCalc) :
	healthFunc(hfc) {

	}

	int healthValue() const {
		return healthFunc(*this);
	}

private:
	HealthCalcFunc healthFunc;
};

class EvilBadGuy: public GameCharacter {
public:
	explicit EvilBadGuy(HealthCalcFunc hfc = defaultHealthCalc) :
	GameCharacter(hfc) {

	}
};

int defaultHealthCalc(const GameCharacter& gc) {
	return 0;
}

int loseHealthQuickly(const GameCharacter& gc) {
	return -1;
}

int loseHealthSlowly(const GameCharacter& gc) {
	return 1;
}
#endif

#ifdef NO1

/**
 * NVI=Non Virtual Interface
 */
class GameCharacter {
public:

	/*
	 * wrapper
	 */
	int healthValue() const {

		// pre-action
		int retVal = doHealthValue();
		// post-action
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
#endif

#if 0
class GameCharacter {
public:
	virtual int healthValue() const;
};

#endif

int main() {
	GameCharacter gc;
	std::cout << gc.healthValue() << std::endl;

#ifdef NO3
	EvilBadGuy ebg1(calcHealth);
	std::cout << ebg1.healthValue() << std::endl;

	HealthCalculator hc;
	EyeCandyCharacter ecc1(hc);
	std::cout << ecc1.healthValue() << std::endl;

	GameLevel cl;
	EvilBadGuy ebg2(std::bind(&GameLevel::health, cl, std::placeholders::_1));
	std::cout << ebg2.healthValue() << std::endl;
#endif

#ifdef NO2
	EvilBadGuy p;
	EvilBadGuy p2(loseHealthQuickly);
	EvilBadGuy p3(loseHealthSlowly);
	std::cout << p.healthValue() << std::endl;
#endif

#ifdef NO1
	Poketmon p;
	std::cout << p.healthValue() << std::endl;
#endif
}
