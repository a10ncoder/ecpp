/*
 * item09.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */

#include <iostream>
using namespace std;

class Transaction {
public:
	Transaction(const string& loginfo) {
		log(loginfo);
		cout << "Transaction.Transaction()" << endl;
	}
	virtual void log(const string& loginfo) const {
		cout << "Transaction.log(" << loginfo << ")" << endl;
	}

};

class BuyTransaction: public Transaction {
public:
	BuyTransaction() :
			Transaction(createLogString("BuyTransaction")) {

	}

private:
	static string createLogString(const string& str) {
		return string(">>") + str + string("<<");
	}
};

class SellTransaction: public Transaction {
public:
	SellTransaction() :
			Transaction("SellTransaction") {

	}
};

#if 0
class Transaction {
public:
	Transaction() {
		log();
		cout << "Transaction.Transaction()" << endl;
	}
	virtual void log() const = 0;
};

class BuyTransaction : public Transaction {
public:
	virtual void log() const {
		cout << "BuyTransaction.log()" << endl;
	}

};

class SellTransaction : public Transaction {
public:
	virtual void log() const {
		cout << "SellTransaction.log()" << endl;
	}
};
#endif
int main() {
	SellTransaction st;
	BuyTransaction bt;

}

