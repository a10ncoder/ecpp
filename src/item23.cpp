/*
 * item23.cpp
 *
 *  Created on: 2016. 7. 18.
 *      Author: sanghyuck.na
 */

#include <iostream>
namespace WebBrowserStuff {
class WebBrowser {
public:
	WebBrowser() {

	}
	void clearCache() {

	}

	void clearHistory() {

	}

	void removeCookies() {

	}

	void clearEveryThing() {
		clearCache();
		clearHistory();
		removeCookies();
	}
};

void clearBrowser( WebBrowser& wb) {
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}
}

int main() {

}

