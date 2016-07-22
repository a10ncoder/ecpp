/*
 * item37.cpp
 *
 *  Created on: 2016. 7. 22.
 *      Author: sanghyuck.na
 */

#include <iostream>

class Shape {
public:
	enum ShapeColor {
		Red, Green, Blue
	};

	virtual void draw(ShapeColor color = Red) {
		doDraw(color);
	}
	virtual ~Shape() {
	}

private:
	virtual void doDraw(ShapeColor color) const = 0;
};

class Rectangle: public Shape {
public:
	virtual void doDraw(ShapeColor color) const {
		std::cout << "Rectangle.draw(" << color << ")" << std::endl;
	}
};

class Circle: public Shape {
public:
	virtual void doDraw(ShapeColor color) const {
		std::cout << "Circle.draw(" << color << ")" << std::endl;
	}
};

#ifdef NO1
class Shape {
public:
	enum ShapeColor {
		Red, Green, Blue
	};

	virtual void draw(ShapeColor color = Red) const = 0;
	virtual ~Shape() {
	}
};

class Rectangle: public Shape {
public:
	// virtual void draw(ShapeColor color = Green) const {
	virtual void draw(ShapeColor color = Red) const {
		std::cout << "Rectangle.draw(" << color << ")" << std::endl;
	}
};

class Circle: public Shape {
public:
	virtual void draw(ShapeColor color) const {
		std::cout << "Circle.draw(" << color << ")" << std::endl;
	}
};

#endif
int main() {
	Shape* pc = new Circle;
	pc->draw(Shape::Green);

#ifdef NO1
	Shape* ps = 0;
	Shape* pc = new Circle;
	Shape* pr = new Rectangle;

	pc->draw();
	pr->draw();
	pc->draw(Shape::Blue);
#endif
}

