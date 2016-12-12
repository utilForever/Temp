#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// 21_RTTI 를 직접 구현하는 기술
//    type의 정보를 담은 static 멤버 data와 static 멤버 data를 리턴하는 가상함수

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
	const MetaClass* mc1 = p->GetClassInfo();// p를 사용해서 타입 정보 얻기
	const MetaClass* mc2 = &Dog::classInfo;  // Dog를 사용해서 타입정보 얻기

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