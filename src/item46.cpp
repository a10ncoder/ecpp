/*
 * item46.cpp
 *
 *  Created on: 2016. 7. 25.
 *      Author: sanghyuck.na
 */

#include<iostream>

template<typename T>
class Rational {
private:
	T numerator;
	T denominator;

public:
	Rational(const T n = 0, const T d = 1) :
			numerator(n), denominator(d) {
	}

	const T getDenominator() const {
		return denominator;
	}

	const T getNumerator() const {
		return numerator;
	}

	friend const Rational<T> operator*(const Rational<T>& lhs,
			const Rational<T>& rhs) {
		return doMultiply(lhs, rhs);
	}

	void toString() {
		std::cout << "numerator=" << numerator << ", denominator="
				<< denominator << std::endl;
	}
};

template<typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {
	return doMultiply(lhs, rhs);
}

template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs) {
	return Rational<T>(lhs.getNumerator() * rhs.getNumerator(),
			lhs.getDenominator() * rhs.getDenominator());
}

int main() {
	Rational<int> oneHalf(1, 2);

	Rational<int> r = oneHalf * 2;
	r.toString();
}

