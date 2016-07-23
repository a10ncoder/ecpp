/*
 * item41.cpp
 *
 *  Created on: 2016. 7. 22.
 *      Author: sanghyuck.na
 */

#include <iostream>

class Widget {
public:
	Widget() {

	}
	virtual ~Widget() {

	}
	virtual std::size_t size() const {
		return 0;
	}
	virtual void normalize() {

	}
	void swap(Widget& rhs) {

	}

	bool operator!=(Widget& w) {
		return false;
	}
};

template<typename T>
void doProcessing(T& lhs, T& rhs) {
	if ((lhs.size() > 10) && (lhs != rhs)) {
		T tmp(lhs);
		tmp.normalize();
		tmp.swap(lhs);
	}
}

#ifdef NO1
void doProcessing(Widget& w) {
	Widget someNastyWidget;
	if (w.size() > 10 && w != someNastyWidget) {
		Widget tmp(w);
		tmp.normalize();
		tmp.swap(w);
	}
}
#endif

int main() {
	Widget w1;
	Widget w2;

	doProcessing(w1, w2);
}

