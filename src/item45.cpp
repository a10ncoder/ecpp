/*
 * item45.cpp
 *
 *  Created on: 2016. 7. 25.
 *      Author: sanghyuck.na
 */

#include <iostream>

class Top {
};

class Middle: public Top {
};

class Bottom: public Middle {
};

template<typename T>
class SmartPtr {
public:
	explicit SmartPtr(T* r) {
		heldPtr = r;
	}

	// copy assignemnt
	SmartPtr& operator=(SmartPtr const& r) {
		return *this;
	}

	// generalized copy assignemnt
	template<class Y>
	SmartPtr& operator=(SmartPtr<Y> const & r) {
		return *this;
	}

	//copy constructor
	SmartPtr(const SmartPtr & r) :
			heldPtr(r.get()) {
	}

	//generalized copy constructor
	template<typename U>
	SmartPtr(const SmartPtr<U>& rhs) :
			heldPtr(rhs.get()) {
	}

	T*get() const {
		return heldPtr;
	}

private:
	T* heldPtr;
};

int main() {
	Top *pt1 = new Middle;
	Top *pt2 = new Bottom;
	const Top *pct2 = pt1;

	SmartPtr<Top> ppt1 = SmartPtr<Middle>(new Middle);
	SmartPtr<Top> ppt2 = SmartPtr<Middle>(new Bottom);
	SmartPtr<const Top> pptc2 = pt1;

}

