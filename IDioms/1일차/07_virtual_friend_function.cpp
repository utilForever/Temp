#include <iostream>
using namespace std;
// Virtual Friend Function IDioms : �Ϲ� �Լ��� �����Լ�ó�� �����ϰ� �ϴ� ���.

class Animal
{
public:
	virtual const char* toString() const { return "Animal"; }
};
ostream& operator <<(ostream& os, const Animal& a)
{
	return os << a.toString(); // �Ϲ��Լ� ������ �����Լ��� �ٽ� ȣ��
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