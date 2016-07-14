#include <iostream>

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

class HomeForSale2 : private Uncopyable {

};

class HomeForSale {
public:
	HomeForSale() {
	}

	HomeForSale(const HomeForSale &) = delete;
	HomeForSale& operator=(const HomeForSale &) = delete;

#if 0
private:
	HomeForSale(const HomeForSale &);
	HomeForSale& operator=(const HomeForSale &);
#endif
};

int main() {
	HomeForSale h1;
	HomeForSale h2;
	// HomeForSale h3(h1); //error
	// h1 = h2; // error

}
