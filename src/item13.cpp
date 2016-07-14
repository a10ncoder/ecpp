/*
 * item13.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */
#include <iostream>
#include <memory>
#include <tr1/memory>

using namespace std;

class Investment
{
public:
	Investment()
	{
		cout << "Investment()" << endl;
	}
	~Investment()
	{
		cout << "~Investment()" << endl;
	}
};

Investment* createInvestment()
{
	return new Investment;
}

void ferror()
{
	auto_ptr<string> aps(new string[10]);
	std::tr1::shared_ptr<int> spi(new int[1024]);
}

#if 0
void f()
{
	cout << "start void f()" << endl;
	auto_ptr<Investment> pInv1(createInvestment());
	auto_ptr<Investment> pInv2(pInv1); // pInv1 == null;
	pInv1 = pInv2;// pInv2 == null
	cout << "end void f()" << endl;
}
#else
void f()
{
	cout << "start void f()" << endl;

	std::tr1::shared_ptr<Investment> pInv1(createInvestment());
	std::tr1::shared_ptr<Investment> pInv2(pInv1);
	pInv1 = pInv2;

	cout << "end void f()" << endl;
}

#endif

#if 0
void f()
{
	cout << "start void f()" << endl;
	Investment* pInv = createInvestment();

	delete pInv;

	cout << "end void f()" << endl;
}
#endif

int main()
{
	//f();
	ferror();
}

