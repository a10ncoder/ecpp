/*
 * item22.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */
#include <iostream>

using namespace std;

class SpeedDataCollection {
public:
	void addValue(int speed) {

	}

	double averageSoFar() const {
		return 2.3f;
	}
};

class AccessLevels {
private:
	int readOnly;
	int readWrite;
	int writeOnly;

public:
	int getReadOnly() const {
		return readOnly;
	}

	void setReadWrite(int value) {
		readWrite = value;
	}

	int getReadWrite() const {
		return readWrite;
	}

	void setWriteOnly(int value) {
		writeOnly = value;
	}
};

int main() {

}

