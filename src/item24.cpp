/*
 * item24.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */

class Rational {
private:
	int numerator;
	int denominator;

public:
	Rational(int n = 0, int d = 1) :
			numerator(n), denominator(d) {
	}

	int getDenominator() const {
		return denominator;
	}

	int getNumerator() const {
		return numerator;
	}

	const Rational operator*(Rational rhs) {
		return Rational(numerator * rhs.numerator,
				denominator * rhs.denominator);
	}
#if 0
	friend const Rational operator*(const Rational& lhs, const Rational& rhs) {
		return Rational(lhs.getNumerator() * rhs.getNumerator(),
				lhs.getDenominator() * rhs.getDenominator());
	}
#endif

};


#if 1
const Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.getNumerator() * rhs.getNumerator(),
			lhs.getDenominator() * rhs.getDenominator());
}
#endif

int main() {

	Rational one(1, 8);
	Rational oneHalf(1, 2);

	Rational r = one * oneHalf;
	r = r * one;

	//r = one * 2; // = one.operator *(2);
	r = 2 * one; // = 2.operator *(2);

}

