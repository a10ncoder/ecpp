/*
 * item25.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */
#include <string>
#include <iostream>
#include <utility>

namespace WidgetStuff {
template<typename T>
class Widget {
private:
	T name;
public:

	Widget() :
			name() {

	}
	Widget(T n) :
			name(n) {

	}
	Widget(const Widget& w) :
			name(w.name) {

	}

	void toString() {
		std::cout << name << std::endl;
	}

	void swap(Widget& rhs) {
		using std::swap;

		std::swap(name, rhs.name);
	}

};

template<typename T>
void swap(Widget<T>& l, Widget<T>& r) {
	std::cout << "speicializer called" << std::endl;
	l.swap(r);
}
}

template<typename T>
void doSomething(T& lhs, T& rhs) {
	using namespace std;
	swap(lhs, rhs);
}

int main() {
	using namespace WidgetStuff;
	Widget<std::string> a("[widget a]");
	Widget<std::string> b;
	a.toString();
	b.toString();
	std::cout << "------------" << std::endl;

	doSomething(a, b);
	a.toString();
	b.toString();
}

