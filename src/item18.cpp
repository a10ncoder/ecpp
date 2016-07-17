/*
 * item18.cpp

 *
 *  Created on: 2016. 7. 15.
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

void getRidOfInvestment(Investment* p)
{
	delete p;
}

std::tr1::shared_ptr<Investment> /*Investment* */createInvestment()
{
	std::tr1::shared_ptr<Investment> retVal(static_cast<Investment*>(0),
			getRidOfInvestment);
	// Investment
//	auto sp = std::make_shared<int>(12);

// retVal = 실제 객체를 가리키도록
	return retVal;
}

int main()
{
	std::tr1::shared_ptr<Investment> sp(createInvestment());
	return 0;
}

#if 0
struct Day
{
	explicit Day(int d) :
	val(d)
	{
	}
	int val;
};

class Month
{
public:
	static Month Jan()
	{	return Month(1);}
	static Month Feb()
	{	return Month(2);}
	explicit Month(int m) :
	val(m)
	{
	}
	int val;
};

struct Year
{
	explicit Year(int y) :
	val(y)
	{
	}

	int val;

};
class Date
{
public:
	Date(const Month&m, const Day& d, const Year& y)
	{

	}
};

int main()
{
	Date d(Month::Jan(), Day(30), Year(1995));
}

#endif

#if 0
struct Day
{
	explicit Day(int d) :
	val(d)
	{
	}
	int val;
};

struct Month
{
	explicit Month(int m) :
	val(m)
	{
	}
	int val;
};

struct Year
{
	explicit Year(int y) :
	val(y)
	{
	}

	int val;

};
class Date
{
public:
	Date(const Month&m, const Day& d, const Year& y)
	{

	}
};

int main()
{
	// Date d(30, 3 1995);
	Date d(Month(3), Day(30), Year(1995));
}

#endif
#if 0
class Date
{
public:
	Date(int month, int day, int year)
	{

	}
};

int main()
{

	Date d(30, 3, 1995);
	Date d2(3, 40, 1995);

}

#endif

