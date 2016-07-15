/*
 * item16.cpp
 *
 *  Created on: 2016. 7. 15.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <string>

typedef std::string AddressLines[4];

int main() {
	std::string* stringArray = new std::string[100];
	delete[] stringArray;

	std::string* stringPtr = new std::string;
	delete stringPtr;


	std::string* pal = new AddressLines;

	delete[] pal;
}

