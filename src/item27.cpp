/*
 * item27.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */
#include <iostream>
#include <vector>
#include <tr1/memory>
using namespace std;

class Window {

public:
	explicit Window() {
	}

	virtual ~Window() {
	}
	virtual void onResize() {
	}

	virtual void blink() {
			cout << "Window.blink()" << endl;
		}
};

class SpecialWindow: public Window {
public:
	explicit SpecialWindow() {
	}

	virtual void onResize() {
		Window::onResize();
	}

	virtual void blink() {
		cout << "SpecialWindow.blink()" << endl;
	}
};

typedef std::vector<std::tr1::shared_ptr<Window>> VPW;

VPW winPtrs;

int main() {
	winPtrs.push_back(std::tr1::shared_ptr<Window>(new SpecialWindow));

	for (VPW::iterator i = winPtrs.begin(); i != winPtrs.end(); ++i) {
		if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(i->get())) {
			psw->blink();
		}
	}
	return 0;
}

#if 0

class Window {

public:
	explicit Window() {
	}

	virtual ~Window() {
	}
	virtual void onResize() {
	}
};

class SpecialWindow: public Window {
public:
	explicit SpecialWindow() {
	}

	virtual void onResize() {
		Window::onResize();
	}

	void blink() {
		cout<<"SpecialWindow.blink()"<<endl;
	}
};

typedef std::vector<std::tr1::shared_ptr<SpecialWindow>> VPW;

VPW winPtrs;

int main() {
	winPtrs.push_back(std::tr1::shared_ptr<SpecialWindow>(new SpecialWindow));

	for (VPW::iterator i = winPtrs.begin(); i != winPtrs.end(); ++i) {
		if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(i->get())) {
			psw->blink();
		}
	}
	return 0;
}
#endif

#if 0
typedef std::vector<std::tr1::shared_ptr<Window>> VPW;

VPW winPtrs;

int main() {
	winPtrs.push_back(std::tr1::shared_ptr<Window>(new SpecialWindow));

	for (VPW::iterator i = winPtrs.begin(); i != winPtrs.end(); ++i) {
		if (SpecialWindow* psw = dynamic_cast<SpecialWindow*>(i->get())) {
			psw->blink();
		}
	}
	return 0;
}

#endif

#if 0
using namespace std;
class Window {
private:
	int field;

public:
	explicit Window(int f) :
	field(f) {
	}

	Window(const Window& w) {
// field를 초기화 하지 않는다
	}

	virtual ~Window() {
	}
	virtual void onResize() {
		//Window.onResize()=4227705
		cout << "Window.onResize()=" << field << endl;
	}
};

class SpecialWindow: public Window {
public:
	explicit SpecialWindow(int d = 5) :
	Window(d) {
	}

	virtual void onResize() {
		// static_cast<Window>(*this).onResize();
		Window::onResize();
	}
};

int main() {
	SpecialWindow w(1);
	w.onResize();
	return 0;
}

#endif

#if 0
class Base {

};

class Derived: public Base {
};

int main() {
	Derived d;
	Base*pb = &d;
	using namespace std;
	cout << pb << endl; // pb랑 &d가 값이 다를 수 있다
	cout << &d << endl;
}

#endif

#if 0
int main() {
	int x = 4;
	int y = 2;
	double d = static_cast<double>(x) / y;
	using namespace std;

	cout << d << endl;

}
#endif

#if 0
class Widget
{
public:
	explicit Widget(int size)
	{
	}
};

void doSomeWork(const Widget& w)
{

}

int main()
{
	doSomeWork(Widget(15));
	doSomeWork(static_cast<Widget>(15));
	return 0;
}
#endif
