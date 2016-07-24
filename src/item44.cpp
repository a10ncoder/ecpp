/*
 * item44.cpp
 *
 *  Created on: 2016. 7. 24.
 *      Author: mailo
 */

#include <iostream>
template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T* ptr) :
			size(n), pp(ptr) {

	}

	void setDataPtr(T* ptr) {
		pp = ptr;
	}

	void invert(std::size_t size) {
		using namespace std;
		cout << "SquareMatrix.invert(" << size << ")" << endl;
	}
private:
	std::size_t size;
	T* pp;
};

template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
public:
	using SquareMatrixBase<T>::setDataPtr;

	SquareMatrix() :
			SquareMatrixBase<T>(n, 0), pData(new T[n * n]) {
		this->setDataPtr(pData.get());
	}

	using SquareMatrixBase<T>::invert;
	void invert() {
		this->invert(n);
		//SquareMatrixBase<T>::invert(n);
	}
private:
	// http://www.boost.org/users/download/
	// https://theseekersquill.wordpress.com/2010/08/24/howto-boost-mingw/
	boost::scoped_array<T> pData;
};

#ifdef NO3
template<typename T>
class SquareMatrixBase {
protected:
	SquareMatrixBase(std::size_t n, T* ptr) :
	size(n), pp(ptr) {

	}

	void setDataPtr(T* ptr) {
		pp = ptr;
	}

	void invert(std::size_t size) {
		using namespace std;
		cout << "SquareMatrix.invert(" << size << ")" << endl;
	}
private:
	std::size_t size;
	T* pp;
};

template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
public:
	SquareMatrix() :
	SquareMatrixBase<T>(n, data) {

	}

	using SquareMatrixBase<T>::invert;
	void invert() {
		this->invert(n);
		//SquareMatrixBase<T>::invert(n);
	}
private:
	T data[n * n];
};
#endif

#ifdef NO2
template<typename T>
class SquareMatrixBase {
protected:
	void invert(std::size_t size) {
		using namespace std;
		cout << "SquareMatrix.invert(" << size << ")" << endl;
	}

};

template<typename T, std::size_t n>
class SquareMatrix: private SquareMatrixBase<T> {
public:
	using SquareMatrixBase<T>::invert;
	void invert() {
		this->invert(n);
		//SquareMatrixBase<T>::invert(n);
	}

};
#endif

#ifdef NO1
template<typename T, std::size_t n>
class SquareMatrix {
public:
	void invert() {
		using namespace std;
		cout << "SquareMatrix.invert()" << endl;
	}

};
#endif

int main() {

	SquareMatrix<double, 5> sm1;
	sm1.invert();
	SquareMatrix<double, 10> sm2;
	sm2.invert();

#ifdef NO1
	SquareMatrix<double, 5> sm1;
	sm1.invert();
	SquareMatrix<double, 10> sm2;
	sm2.invert();
#endif

}

