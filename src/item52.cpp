/*
 * item52.cpp
 *
 *  Created on: 2016. 7. 26.
 *      Author: sanghyuck.na
 */

#include <iostream>

class StandardNewDeleteForms {
public:
	static void* operator new(std::size_t size) throw (std::bad_alloc) {
		return ::operator new(size);
	}
	static void operator delete(void *p) throw () {
		::operator delete(p);
	}

	static void* operator new(std::size_t size, void *p) throw (std::bad_alloc) {
		return ::operator new(size, p);
	}
	static void operator delete(void *p, void* pp) throw () {
		::operator delete(p, pp);
	}

	static void* operator new(std::size_t size,
			const std::nothrow_t& nt) throw () {
		return ::operator new(size, nt);
	}
	static void operator delete(void *p, const std::nothrow_t& nt) throw () {
		::operator delete(p);
	}
};

class Widget: public StandardNewDeleteForms {
public:
	using StandardNewDeleteForms::operator new;
	using StandardNewDeleteForms::operator delete;

	static void* operator new(std::size_t size, std::ostream& l)
			throw (std::bad_alloc) {
		return StandardNewDeleteForms::operator new(size);
	}

	static void operator delete(void *p, const std::ostream& l) throw () {
		StandardNewDeleteForms::operator delete(p);
	}

};

#ifdef v2
class Base {
public:
	static void* operator new(std::size_t size, std::ostream& logs)
	throw (std::bad_alloc) {
		return ::operator new(size);
	}
};

class Derived: public Base {
public:
	static void* operator new(std::size_t size) throw (std::bad_alloc) {
		return ::operator new(size);
	}
};

class Widget {
public:
	static void* operator new(std::size_t size, std::ostream& logs)
	throw (std::bad_alloc) {
		return ::operator new(size);
	}

	static void operator delete(void* p, std::ostream& logs) throw () {
		::operator delete(p);
	}
#ifdef v1
	static void operator delete(void* p, std::size_t size) throw () {
		::delete (p);
	}
#endif
};
#endif
int main() {
#ifdef v1
	Widget* pw = new (std::cerr) Widget;
#endif

#ifdef v2
	// Base *pb = new Base; // error
	Base *pb = new (std::cerr) Base;// ok
	//Derived *pd = new (std::clog) Derived; // error
	Derived *pd = new Derived;// ok
#endif
}

