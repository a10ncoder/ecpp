/*
 * item20.cpp
 *
 *  Created on: 2016. 7. 16.
 *      Author: mailo
 */
#include <iostream>
#include <string>

using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}

	virtual void display() const
	{
		cout << "Person.display()" << endl;
	}

	Person(const Person& rhs)
	{
		cout << "Person(const Person& rhs)" << endl;
	}

	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}

private:
	std::string name;
	std::string address;
};

class Student: public Person
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}
	Student(const Student& rhs) :
			Person(rhs)
	{
		cout << "Student(const Student& rhs)" << endl;
	}

	virtual void display() const
	{
		cout << "Student.display()" << endl;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

#if 1
bool validStudent(const Person& s)
{
	cout << "validStudent(Student s)" << endl;
	s.display();
	return false;
}
#else
bool validStudent(Person s)
{
	cout << "validStudent(Student s)" << endl;
	s.display();
	return false;
}
#endif
#if 0
class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}

	Person(const Person& rhs)
	{
		cout << "Person(const Person& rhs)" << endl;
	}

	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}

private:
	std::string name;
	std::string address;
};

class Student: public Person
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}
	Student(const Student& rhs) :
	Person(rhs)
	{
		cout << "Student(const Student& rhs)" << endl;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

bool validStudent(Student s)
{
	cout << "validStudent(Student s)" << endl;

	return false;
}
#endif

int main()
{
	cout << "main()" << endl;
	Student plato;
	bool platoIsOk = validStudent(plato);
}
