/*
 * item04.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

class FileSystem {
};

FileSystem& tfs() {
	static FileSystem fs;
	return fs;
}

class Directory {
};

Directory& tempDir()
{
	static Directory td;
	return td;
}

class ABEntry {

public:
	ABEntry() :
			theName(), theAddress(), thePhones(), numTimesConsulted(0) {

	}

	ABEntry(const std::string& name, const std::string& address,
			const std::list<int>& phones) :
			theName(name), theAddress(address), thePhones(phones), numTimesConsulted(
					0) {
#if 0
		theName = name;
		theAddress = address;
		thePhones = phones;
		numTimesConsulted = 0;
#endif
	}

private:
	std::string theName;
	std::string theAddress;
	std::list<int> thePhones;
	int numTimesConsulted;
};

int main() {
	int x = 0;
	const char* text = "A C-style string";
	double d;

}

