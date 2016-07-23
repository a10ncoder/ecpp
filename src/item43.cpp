/*
 * item43.cpp
 *
 *  Created on: 2016. 7. 24.
 *      Author: mailo
 */

#include <iostream>
#include <string>

class CompanyA {
public:
	void sendCleartext(const std::string& msg) {

	}
	void sendEncrypted(const std::string& msg) {

	}
};

class CompanyB {
public:
	void sendCleartext(const std::string& msg) {

	}
	void sendEncrypted(const std::string& msg) {

	}
};

class CompanyZ {
public:
	void sendEncrypted(const std::string& msg) {

	}
};

class MsgInfo {

};

template<typename C>
class MsgSender {
public:
	void sendClear(const MsgInfo& info) {
		std::string msg;

		C c;
		c.sendCleartext(msg);
	}
};

template<>
class MsgSender<CompanyZ> {
	void sendSecret(const MsgInfo& info) {

	}
};

template<typename C>
class LoggingMsgSender: public MsgSender<C> {
public:

	void sendClearMsg(const MsgInfo& info) {
		std::string msg;
		C c;

		MsgSender<C>::sendClear(info);
	}

#ifdef NO3
	using MsgSender<C>::sendClear;
	void sendClearMsg(const MsgInfo& info) {
		std::string msg;
		C c;

		sendClear(info);
	}
#endif

#ifdef NO2
	void sendClearMsg(const MsgInfo& info) {
		std::string msg;
		C c;

		this->sendClear(info);
	}
#endif
};

#ifdef NO1

template<typename C>
class LoggingMsgSender : public MsgSender<C> {
public:
	void sendClearMsg(const MsgInfo& info) {
		std::string msg;

		C c;
		sendClear(info);
	}
};
#endif
int main() {
	MsgInfo mi;
	LoggingMsgSender<CompanyB> s;
	//LoggingMsgSender<CompanyZ> s;
	s.sendClear(mi);

}

