/*
 * item42.cpp
 *
 *  Created on: 2016. 7. 24.
 *      Author: mailo
 */

#include <iostream>

template<typename IterT>
void workWIthIterator(IterT iter) {
	//typename std::iterator_traits<IterT>::value_type tmp(*iter);

	typedef typename std::iterator_traits<IterT>::value_type value_type;
	value_type tmp(*iter);
}

template<typename T>
class Base {
public:
	class Nested {
	public:
		Nested(int x) {

		}
	};
};

template<typename T>
class Derived: public Base<T>::Nested {
public:
	explicit Derived(int x) :
			Base<T>::Nested(x) {
		typename Base<T>::Nested tmp;
	}
};

template<typename C>
void f(const C& c, typename C::iterator iter) {

}

template<typename C>
void print2nd(const C& c) {
	if (c.size() >= 2) {
		typename C::const_iterator iter(c.begin());

		++iter;
		int value = *iter;
		std::cout << value;
	}
}

int main() {

}
