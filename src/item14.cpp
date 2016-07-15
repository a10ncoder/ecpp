/*
 * item14.cpp
 *
 *  Created on: 2016. 7. 15.
 *      Author: sanghyuck.na
 */

#include <iostream>
/*
 * https://www.eclipse.org/forums/index.php/t/490066/
 * #include <mutex>
 */

using namespace std;

class mutex {

};


// or auto_ptr
// or deep copy

class Lock {
public:
	explicit Lock(mutex *pm) :
			mutexPtr(pm, unlock) {
		lock(mutexPtr.get());
	}

private:
	std::tr1::shared_ptr<mutex> mutexPtr;

	void lock(mutex *pm) {

	}

	void unlock(mutex *pm) {

	}

};
#if 0

class Uncopyable {
protected:
	Uncopyable() {
	}
	~Uncopyable() {
	}

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class Lock: private Uncopyable {

public:
	explicit Lock(mutex *pm) :

	mutexPtr(pm) {
		lock(mutexPtr);
	}

	~Lock() {
		unlock(mutexPtr);
	}

private:
	mutex *mutexPtr;

	void lock(mutex *pm) {

	}

	void unlock(mutex *pm) {

	}

};
#endif

#if 0
class Lock {
public:
	explicit Lock(mutex *pm) :
	mutexPtr(pm) {
		lock(mutexPtr);
	}

	~Lock() {
		unlock(mutexPtr);
	}

private:
	mutex *mutexPtr;

	void lock(mutex *pm) {

	}

	void unlock(mutex *pm) {

	}

};
#endif

int main() {
	mutex m;
	Lock m1(&m);
	Lock m2(m1);
}

