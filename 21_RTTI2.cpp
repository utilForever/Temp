#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// 21_RTTI �� ���� �����ϴ� ���
//    type�� ������ ���� static ��� data�� static ��� data�� �����ϴ� �����Լ�

struct MetaClass
{
	string name;
};

class Animal
{
public:
	virtual ~Animal() {}

	static  const MetaClass  classInfo;
	virtual const MetaClass* GetClassInfo() { return &classInfo; }
};
const MetaClass Animal::classInfo = { "Animal" };


class Dog : public Animal 
{
public:
	static  const MetaClass  classInfo;
	virtual const MetaClass* GetClassInfo() { return &classInfo; }
};
const MetaClass Dog::classInfo = { "Dog" };


void foo(Animal* p)
{
	const MetaClass* mc1 = p->GetClassInfo();// p�� ����ؼ� Ÿ�� ���� ���
	const MetaClass* mc2 = &Dog::classInfo;  // Dog�� ����ؼ� Ÿ������ ���

	cout << mc1->name << endl;

	if (mc1 == mc2)
	{

	}
}


int main()
{
	Dog d;
	foo(&d);
}