#include <iostream>

static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

void *operator new(std::size_t size) throw (std::bad_alloc) {
	using namespace std;
	size_t realSize = size + 2 * sizeof(int);
	void *p = malloc(realSize);
	if (!p) {
		throw bad_alloc();
	}

	*(static_cast<int*>(p)) = signature;
	*(reinterpret_cast<int *>(static_cast<Byte *>(p) + realSize - sizeof(int))) =
			signature;
	return static_cast<Byte*>(p) + sizeof(int);
}

int main() {

}
