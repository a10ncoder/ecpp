#include <iostream>
#include <string>

using namespace std;

#define ASPECT_RATIO 1.653

const double aspectRatio = 1.653;
const char* const authorName = "Scott Meyers";
const string authorName1("Soctt Meyers1");

class GamePlayer {
private:
	static const int numTurns = 5;
	int scores[numTurns];
};

class GamePlayer2 {
private:
	enum {
		NumTurns = 5
	};

	int scores[NumTurns];
};

const int GamePlayer::numTurns;

void f(int i) {
	cout << "void f(int i" << i << ")" << endl;

}

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a): (b))

template<typename T>
inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}

int main() {
	const string authorName2("Soctt Meyers2");
	cout << authorName1 << endl;
	cout << authorName2 << endl;

	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);
	CALL_WITH_MAX(++a, b = 10);
	callWithMax(a, b);
}
