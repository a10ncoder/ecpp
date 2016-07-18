/*
 * item26.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */

#include <iostream>

#include <string>
#include <stdexcept>

void test() {
	using namespace std;


	string str; // A -- ¼Óµµ = construct:1 + deconstructor:1 + assignment n
	for (int i = 0; i < 5; ++i) {
		string str2; // B = construct:n + deconstructor:n
	}
}

std::string encryptPassword(const std::string& p) {
	using namespace std;

	if (p.length() < 52) {
		throw std::logic_error("password is too short.");
	}
	string encrypted(p);
	return encrypted;
}

#if 0
std::string encryptPassword(const std::string& p) {
	using namespace std;

	if (p.length() < 52) {
		throw std::logic_error("password is too short.");
	}
	string encrypted;
	encrypted = p;
	return encrypted;
}

#endif

#if 0
std::string encryptPassword(const std::string& p) {
	using namespace std;

	string encrypted;

	if (p.length() < 52) {
		throw std::logic_error("password is too short.");
	}
	return encrypted;
}
#endif

int main() {
	std::string str("333");
	encryptPassword(str);
}
