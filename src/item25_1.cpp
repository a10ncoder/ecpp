/*
 * item25.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */
#include <string>
#include <iostream>
#include <utility>

class WidgetImpl {
public:
	WidgetImpl() :
			name() {

	}

	WidgetImpl(const std::string& s) :
			name(s) {
	}

	WidgetImpl(const WidgetImpl& wi) :
			name(wi.name) {
	}

	const WidgetImpl operator=(const WidgetImpl& rhs) {
		name = rhs.name;
		return *this;
	}

	const std::string getName() const {
		return name;
	}

private:
	std::string name;
};

class Widget {
private:
	//std::string name;
	WidgetImpl *pImpl;
public:
#if 0
	Widget() :
	name() {

	}
	Widget(std::string n) :
	name(n) {

	}
	Widget(const Widget& w) :
	name(w.name) {

	}
#endif
	Widget() :
			pImpl(new WidgetImpl) {

	}

	Widget(std::string n) :
			pImpl(new WidgetImpl(n)) {

	}

	Widget(const Widget& w) :
			Widget() {
		*pImpl = (*w.pImpl);
	}

	~Widget() {
		delete pImpl;
		pImpl = 0;

	}

	void swap(Widget& rhs) {
		using std::swap;

		std::swap(pImpl, rhs.pImpl);
	}

	const Widget operator=(const Widget& rhs) {
		(*pImpl) = (*rhs.pImpl);
		return *this;
	}

	void toString() {
		std::cout << pImpl->getName() << std::endl;
	}
};

namespace std {
template<>
void swap<Widget>(Widget& a, Widget& b) {
	a.swap(b);
}

}

#if 0
template<typename T>
void swap(T& a, T& b) {
	T tmp(a);
	a = b;
	b = tmp;

}
#endif

#if 0
void swap(Widget& a, Widget& b) {
	Widget tmp(a);
	a = b;
	b = tmp;

}
#endif

int main() {
	Widget a("[widget a]");
	Widget b;
	a.toString();
	b.toString();
	std::cout << "------------" << std::endl;

	std::swap(a, b);
	a.toString();
	b.toString();
}

