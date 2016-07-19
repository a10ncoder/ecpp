/*
 * item30.cpp
 *
 *  Created on: 2016. 7. 19.
 *      Author: sanghyuck.na
 */

#include <iostream>

class Person {
private:
	int age;

public:
	/*
	 * class내부에 definition을 포함하면 implicit inline
	 */
	int getAge() const {
		return age;
	}
};
/*
 * explicit inline
 template<typename _Tp>
 inline const _Tp&
 max(const _Tp& __a, const _Tp& __b)
 {
 // concept requirements
 __glibcxx_function_requires(_LessThanComparableConcept<_Tp>)
 //return  __a < __b ? __b : __a;
 if (__a < __b)
 return __b;
 return __a;
 }
 */

int main() {

}

