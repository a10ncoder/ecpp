/*
 * item55.cpp
 *
 *  Created on: 2016. 7. 27.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <vector>
#include <boost/lambda/bind.hpp>
#include <boost/scoped_array.hpp>
#include <boost/mpl/list.hpp>
using namespace boost::lambda;

int main() {
	std::vector<int> v;
	// std::for_each(v.begin(), v.end(), std::cout << _1 * 2 + 10 << std::endl);
	typedef boost::mpl::list<float, double, long double> floats;
	typedef boost::mpl::list<floats, int>::type types;

	boost::scoped_array<int> a(new int[4]);
}
