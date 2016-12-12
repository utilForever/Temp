#include <iostream>
#include <typeinfo>
using namespace std;

// 21_RTTI
// ����ð��� Ÿ���� ������ Ȯ���ϴ� ���

class Animal
{
public:
	virtual ~Animal() {}
};

class Dog : public Animal {};
class Cat : public Animal {};

void foo(Animal* p)
{
	const type_info& t1 = typeid(*p);  // ��ü�� ����ؼ� type_info ������
	const type_info& t2 = typeid(Dog); // Ŭ�����̸��� ����ؼ� type_info ������

	cout << t1.name() << endl;

	if (t1 == t2)  
	{
	}
}


int main()
{
	Dog d;
	foo(&d);
}