/*
 * item28.cpp
 *
 *  Created on: 2016. 7. 19.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <tr1/memory>
class Point {
private:
	int x;
	int y;

public:
	Point(int _x, int _y) :
			x(_x), y(_y) {

	}

	Point(const Point& rhs) :
			x(rhs.x), y(rhs.y) {

	}

	void setX(int nx) {
		x = nx;
	}
	void setY(int ny) {
		y = ny;
	}

	void toString() const {
		std::cout << "[x=" << x << "][y=" << y << "]" << std::endl;
	}
};

struct RectData {
	Point ulhc;
	Point lrhc;

	RectData(int lx, int ly, int rx, int ry) :
			ulhc(lx, ly), lrhc(rx, ry) {
	}

	RectData(const Point& lhs, const Point& rhs) :
			ulhc(lhs), lrhc(rhs) {
	}
};

class Rectangle {
private:
	std::tr1::shared_ptr<RectData> pData;
public:
	Rectangle(int lx, int ly, int rx, int ry) :
			pData(new RectData(lx, ly, rx, ry)) {
	}

	Rectangle(const Point& lhs, const Point& rhs) :
			pData(new RectData(lhs, rhs)) {
	}

	const Point& upperLeft() const {
		return pData->ulhc;
	}

	const Point& upperRight() const {
		return pData->lrhc;
	}

};

const Rectangle boundingBox(const int rx, const int ry) {
	return Rectangle(0, 0, rx, ry);
}

int main() {
	Point coord1(0, 0);
	Point coord2(100, 100);
	const Rectangle rec(coord1, coord2);
	const Point* pleft = &(boundingBox(100, 100).upperLeft());
	pleft->toString();
}

#if 0
Point& upperLeft() const {
	return pData->ulhc;
}

Point& upperRight() const {
	return pData->lrhc;
}

};

int main() {
Point coord1(0, 0);
Point coord2(100, 100);
const Rectangle rec(coord1, coord2);
rec.upperLeft().setX(50);
}

#endif
