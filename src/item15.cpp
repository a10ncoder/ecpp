/*
 * item15.cpp
 *
 *  Created on: 2016. 7. 15.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <memory>
#include <tr1/memory>

using namespace std;

class FontHandle {

};

void release(FontHandle fh) {

}

class Font {
public:
	explicit Font(FontHandle fh) :
			f(fh) {

	}

	FontHandle get() const {
		return f;
	}

	~Font() {
		release(f);
	}

	/**
	 * TODO
	 */
	operator FontHandle() const {
		return f;
	}

private:
	FontHandle f;
};

class Investment {
public:
	Investment() {
		cout << "Investment()" << endl;
	}

	bool isTaxFree() const {
		return false;
	}

	~Investment() {
		cout << "~Investment()" << endl;
	}
};

Investment* createInvestment() {
	return new Investment;
}

int daysHeld(const Investment* pi) {
	return 0;
}

void changeFontSize(FontHandle f, int newSize) {

}

int main() {
	std::tr1::shared_ptr<Investment> pInv(createInvestment());
	int days = daysHeld(pInv.get());

	std::cout << days << std::endl;

	bool taxable1 = !(pInv->isTaxFree());

	std::auto_ptr<Investment> pi2(createInvestment());
	bool taxable2 = !((*pi2).isTaxFree());

	FontHandle fh;
	Font f(fh);

	changeFontSize(f.get(), 2);
	changeFontSize(f, 2);

	FontHandle f2 = f;
	// Font ¡æ FontHandle ,
	// FontHandle (copy-constructor)¡æ FontHandle
}

