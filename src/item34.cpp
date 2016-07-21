/*
 * item34.cpp
 *
 *  Created on: 2016. 7. 20.
 *      Author: mailo
 */

#include <iostream>
#if 0
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
#endif

#if 0
class GameCharacter {
public:
	virtual int healthValue const;
};

#endif

class Airport {

};

class Airplane {
public:
	virtual void fly(const Airport& dest) = 0;

	virtual ~Airplane() {
	}
};

void Airplane::fly(const Airport& dest) {
	std::cout << "Airplane.fly()" << std::endl;
}

class ModelA: public Airplane {
public:
	virtual void fly(const Airport& dest) {
		Airplane::fly(dest);
	}
};

class ModelB: public Airplane {
public:
	virtual void fly(const Airport& dest) {
		Airplane::fly(dest);
	}
};

class ModelC: public Airplane {
public:
	virtual void fly(const Airport& dest) {
		std::cout << "ModelC.fly()" << std::endl;
	}
};

#if 0
class Airport {

};

class Airplane {
public:
	virtual void fly(const Airport& dest) = 0;

	virtual ~Airplane() {
	}
protected:
	void defaultFly(const Airport& dest) {
		std::cout << "Airplane.fly()" << std::endl;
	}
};

class ModelA: public Airplane {
public:
	virtual void fly(const Airport& dest) {
		Airplane::defaultFly(dest);
	}
};

class ModelB: public Airplane {
public:
	virtual void fly(const Airport& dest) {
		Airplane::defaultFly(dest);
	}
};

class ModelC: public Airplane {
public:
	virtual void fly(const Airport& dest) {
		std::cout << "ModelC.fly()" << std::endl;
	}
};

#endif

#if 0
class Airport {

};

class Airplane {
public:
	virtual void fly(const Airport& dest) {
		std::cout << "Airplane.fly()" << std::endl;
	}

	virtual ~Airplane() {
	}
};

class ModelA:public Airplane {

};

class ModelB:public Airplane {

};

class ModelC:public Airplane {

};

#endif

#if 0
class Shape {
public:
	virtual void draw() const = 0;
	virtual void error(const std::string& msg) {
	}
	int objectId() const {
		return 0;
	}

	virtual ~Shape() {
	}
};

class Rectangle: public Shape {
public:
	virtual void draw() const {
		std::cout << "Rectangle.draw()" << std::endl;
	}
};
class Ellipse: public Shape {
public:
	virtual void draw() const {
		std::cout << "Ellipse.draw()" << std::endl;
	}
};

#endif

int main() {

#if 0
	Poketmon p;

	std::cout << p.healthValue() << std::endl;
#endif

#if 1
	Airport pdx;
	Airplane *pa = new ModelC;
	pa->fly(pdx);
#endif

#if 0
// Shape *ps = new Shape;// error
	Shape *ps1 = new Rectangle;
	ps1->draw();
	Shape *ps2 = new Ellipse;
	ps2->draw();
//ps1->Shape::draw();//undefined reference
//ps2->Shape::draw();// undefined reference

#endif

}

