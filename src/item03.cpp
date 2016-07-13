/*
 * item03.cpp
 *
 *  Created on: 2016. 7. 13.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Rational
{

};

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational();
}

class TextBlock
{
public:
	TextBlock(string str) :
			text(str)
	{
	}

	const char& operator[](size_t p) const
	{
		return text[p];
	}

	char& operator[](size_t p)
	{
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[p]);
	}

private:
	std::string text;

};

void print(const TextBlock& ctb)
{
	std::cout << ctb[0];
}

class CTextBlock
{
public:
	CTextBlock(string str) :
			pText(str.c_str()), lengthIsValid(false)
	{
	}

	char& operator[](std::size_t p) const
	{
		return pText[p];
	}

	virtual ~CTextBlock()
	{
	}

	size_t length() const
	{
		if (!lengthIsValid)
		{
			lengthpText = strlen(pText);
			lengthIsValid = true;
		}

		return lengthpText;
	}

private:
	const char* pText;
	mutable size_t lengthpText;
	mutable bool lengthIsValid;
};

int main()
{

	char greeting[] = "hello";
	char *p = greeting;
	const char *p2 = greeting;
	char const *p22 = greeting; // same as p2
	char* const p3 = greeting;
	const char* const p4 = greeting;

	std::vector<int> vec;
	vec.push_back(10);
	const std::vector<int>::iterator iter = vec.begin();
	*iter = 10;
	// ++iter; // error

	std::vector<int>::const_iterator cIter = vec.begin();
	// *cIter = 10; //error
	++cIter;

	// (a * b) = c;

	TextBlock tb("Hello");
	std::cout << tb[0] << endl;
	tb[0] = 'x';
	const TextBlock ctb("World");
	std::cout << ctb[0] << endl;
	// ctb[0] = 'x'; // error

	const CTextBlock cctb("Hello");
	char *pc = &cctb[0];
	*pc = 'J';
}

