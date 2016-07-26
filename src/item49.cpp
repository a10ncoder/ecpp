/*
 * item49.cpp
 *
 *  Created on: 2016. 7. 25.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <new>
#include <cstdlib>
#include <string>

template<typename T>
class NewHandlerSupport {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw ();
	static void* operator new(std::size_t size) throw (std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = 0;

template<typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(
		std::new_handler p) throw () {
	std::new_handler old = currentHandler;
	currentHandler = p;
	return old;
}

class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh) :
			handler(nh) {
	}

	~NewHandlerHolder() {
		std::set_new_handler(handler);
	}

private:
	std::new_handler handler;
	NewHandlerHolder(const NewHandlerHolder&) = delete;
	NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;

};

template<typename T>
void* NewHandlerSupport<T>::operator new(std::size_t size)
		throw (std::bad_alloc) {
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

class Widget: public NewHandlerSupport<Widget> {

};

void outOfMem() {
	std::cout << "void outOfMem()" << std::endl;
}

class Widget2 {

};

#ifdef v3
class Widget {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw ();
	static void* operator new(std::size_t size) throw (std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

std::new_handler Widget::currentHandler = 0;

std::new_handler Widget::set_new_handler(std::new_handler p) throw () {
	std::new_handler old = currentHandler;
	currentHandler = p;
	return old;
}

class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh) :
	handler(nh) {
	}

	~NewHandlerHolder() {
		std::set_new_handler(handler);
	}

private:
	std::new_handler handler;
	NewHandlerHolder(const NewHandlerHolder&) = delete;
	NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;

};

void* Widget::operator new(std::size_t size) throw (std::bad_alloc) {
	NewHandlerHolder h(std::set_new_handler(currentHandler));
	return ::operator new(size);
}

void outOfMem() {
	std::cout << "void outOfMem()" << std::endl;
}
#endif

#ifdef v2
class X {
public:
	static void outOfMemory();
};

class Y {
public:
	static void outOfMemory();
};

#endif

#ifdef v1
void outOfMem() {
	std::cerr << "Unable to satisfy request for memory" << std::endl;
	std::abort();
}
#endif
int main() {

	Widget::set_new_handler(outOfMem);
	Widget *pw1 = new Widget;
	std::string*ps = new std::string;

	Widget::set_new_handler(0);
	Widget *pw2 = new Widget;

	Widget2 *pw3 = new (std::nothrow) Widget2;

#ifdef v1
	std::set_new_handler(outOfMem);
	int *pBigDataArray = new int[100000000L];
#endif
}

