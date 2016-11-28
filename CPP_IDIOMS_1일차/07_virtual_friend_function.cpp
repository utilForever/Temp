#include <iostream>
using namespace std;

// Virtual Friend Function : 일반 함수를 가상함수처럼 동작하게 하는 방법.
class Animal
{
public:
	virtual const char* toString() const { return "Animal"; }
};

//ostream& operator <<(ostream& os, const Animal& a)
//{
//	return os << "Animal";
//}

ostream& operator <<(ostream& os, const Animal& a)
{
	return os << a.toString();
}

class Dog : public Animal
{
	virtual const char* toString() const { return "Dog"; }
};

//ostream& operator <<(ostream& os, const Dog& d)
//{
//	return os << "Dog";
//}

int main()
{
	Animal a; 
	cout << a << endl;

	Dog d;
	cout << d << endl;

	Animal* p = new Dog;
	cout << *p << endl;	// ???
}