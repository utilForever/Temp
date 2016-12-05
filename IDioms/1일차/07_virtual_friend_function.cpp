#include <iostream>
using namespace std;
// Virtual Friend Function IDioms : 일반 함수를 가상함수처럼 동작하게 하는 방법.

class Animal
{
public:
	virtual const char* toString() const { return "Animal"; }
};
ostream& operator <<(ostream& os, const Animal& a)
{
	return os << a.toString(); // 일반함수 구현시 가상함수를 다시 호출
}
class Dog : public Animal
{
public:
	virtual  const char* toString() const { return "Dog"; }

};
//ostream& operator <<(ostream& os, const Dog& a) { return os << "Dog"; }

int main()
{
	Animal* p = new Dog;
	cout << *p << endl; // ????



	Animal a; cout << a << endl;
	Dog d;	cout << d << endl;

}