/*
 * item21.cpp
 *
 *  Created on: 2016. 7. 16.
 *      Author: mailo
 */

class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1) :
			n(numerator), d(denominator)
	{
	}

private:
	int n;
	int d;

	friend inline const Rational& operator *(const Rational& lhs,
			const Rational& rhs)
	{
		return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	}

#if 0
	friend const Rational& operator *(const Rational& lhs, const Rational& rhs)
	{

		static Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
		return result;

	}
#endif
	bool operator==(const Rational& rhs)
	{
		return n == rhs.n && d == rhs.d;
	}

#if 0
	friend const Rational& operator *(const Rational& lhs, const Rational& rhs)
	{

		Rational* result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
		return *result;

	}
#endif

#if 0
	friend const Rational& operator *(const Rational& lhs, const Rational& rhs)
	{

		Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
		return result;

	}
#endif

};

int main()
{
#if 0
	// case 3
	if ((a * b) == (c * d))
	{
		// always true
	}
#endif

#if 0
	//case 2
	Rational w, x, y, z;
	w = x * y * z;
#endif

#if 0
	// case 1
	Rational a(1, 2);
	Rational b(3, 5);
	Rational c = a * b;
#endif

}
