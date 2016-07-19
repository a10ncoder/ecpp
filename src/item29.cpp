/*
 * item29.cpp
 *
 *  Created on: 2016. 7. 19.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <tr1/memory>
#include  <istream>

class mutex {

};

void unlock(mutex* m) {

}

class Lock {
public:
	explicit Lock(mutex *pm) :
			m(pm, unlock) {
		lock(m.get());
	}

private:
	std::tr1::shared_ptr<mutex> m;

	void lock(mutex *pm) {

	}

	//void (Lock::*)(mutex)

};

struct PMImpl {
	std::tr1::shared_ptr<int> bgImg;
	int imageChnages;
};

class PrettyMenu {
private:
	mutex m;
	std::tr1::shared_ptr<PMImpl> pImpl;

public:
	PrettyMenu() :
			pImpl(new PMImpl) {
	}

	void changeBackground() {
		Lock ml(&m);

		std::tr1::shared_ptr<PMImpl> pNew(new PMImpl(*pImpl));

		pNew->bgImg.reset(new int(2));
		++(pNew->imageChnages);

		std::swap(pImpl, pNew);
	}
private:

};

#if 0
class PrettyMenu {
private:
	mutex m;
	std::tr1::shared_ptr<int> bgImg;

	int imageChnages;
public:
	void changeBackground() {
		Lock ml(&m);
		bgImg.reset(new int(2));
		++imageChnages;
	}
private:

};
#endif
#if 0
class PrettyMenu {
private:
	mutex m;
	int* bgImg;
	int imageChnages;
public:
	void changeBackground() {
		lock(&m);
		delete bgImg;
		++imageChnages;
		bgImg = new int(2);
		unlock(&m);
	}
private:

	void lock(mutex *pm) {

	}

	void unlock(mutex *pm) {

	}

};
#endif

int main() {
	PrettyMenu pm;

	pm.changeBackground();
	return 0;
}

