/*
 * item11.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */
#include <iostream>

class Bitmap {

};

class Widget {
public:
	Widget() :
			bitmap(new Bitmap) {

	}

	~Widget() {
		delete bitmap;
		bitmap = 0;
	}

	Widget& operator=(Widget rhs) {
		swap(rhs);
		return *this;
	}

#if 0
	Widget& operator=(const Widget& rhs) {
		Widget tmp(rhs);
		swap(tmp);
		return *this;
	}
#endif
private:
	void swap(Widget& rhs) {
		bitmap = rhs.bitmap;
	}

#if 0
	Widget& operator=(const Widget& rhs) {
		Bitmap *org = bitmap;
		bitmap = new Bitmap(*rhs.bitmap);
		delete org;

		return *this;
	}
#endif

#if 0
	Widget& operator=(const Widget& rhs) {
		if (this == &rhs)
		return *this;

		delete bitmap;
		bitmap = new Bitmap;
		return *this;
	}
#endif

private:
	Bitmap *bitmap;
};

int main() {
	Widget w;
	// w = w;
}

