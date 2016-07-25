/*
 * item47.cpp
 *
 *  Created on: 2016. 7. 25.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <vector>

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::random_access_iterator_tag) {
	iter += d;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::bidirectional_iterator_tag) {
	if (d >= 0) {
		while (d--)
			++iter;
	} else {
		while (d++)
			--iter;
	}
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, std::input_iterator_tag) {
	if (d < 0) {
		throw std::output_iterator_tag("Negative distance");
	}
	while (d--)
		++iter;
}

#ifdef V3
template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
	doAdvance(iter, d,
			typename std::iterator_traits<IterT>::iterator_category());

}
#endif

#ifdef V2
template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {

	if (typeid(typename std::iterator_traits<IterT>::iterator_category)
			== typeid(std::random_access_iterator_tag)) {

	}

#ifdef V1
	if () {
		iter += d;
	} else {
		if (d >= 0) {
			while (d--)
			++iter;
		} else {
			while (d++)
			--iter;
		}
	}
#endif
}
#endif

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	auto i = vec.begin();
	advance(i, 2);

}

