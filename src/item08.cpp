/*
 * item08.cpp
 *
 *  Created on: 2016. 7. 14.
 *      Author: sanghyuck.na
 */
#include<iostream>
#include<cstdlib>
using namespace std;

class DBConnection {
public:
	static DBConnection create();

	void close() {
		cout << "DBConnection::close()" << endl;
	}
};

DBConnection DBConnection::create() {
	cout << "DBConnection::create()" << endl;
	return DBConnection();
}

class DBConn {
public:
	DBConn(DBConnection _dbc) :
			dbc(_dbc), closed(false) {
	}

	void close() {
		dbc.close();
		closed = true;
	}
	~DBConn() {
		if (!closed) {

			try {
				dbc.close();
			} catch (...) {
				// printf log
			}
			closed = true;
		}
	}

private:
	DBConnection& dbc;
	bool closed;
};

#if 0
class DBConn {
public:
	DBConn(DBConnection _dbc) :
	dbc(_dbc) {

	}
	~DBConn() {
		try {
			dbc.close();
		} catch (...) {

		}
	}

private:
	DBConnection& dbc;

};

#endif

#if 0
class DBConn {
public:
	DBConn(DBConnection _dbc) :
	dbc(_dbc) {

	}
	~DBConn() {
		try {
			dbc.close();
		} catch (...) {
			std::abort();
		}
	}

private:
	DBConnection& dbc;

};
#endif

#if 0
class DBConn {
public:
	DBConn(DBConnection _dbc) :
	dbc(_dbc) {

	}
	~DBConn() {
		dbc.close();
	}

private:
	DBConnection& dbc;

};
#endif

int main() {
	DBConn dbc(DBConnection::create());
}

