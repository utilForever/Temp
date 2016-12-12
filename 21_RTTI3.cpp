#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// ��Ģ�� �ڵ������ϴ� ��ũ�θ� �����Ѵ�. - MFC, QT, Android, wxWidget ��� ���� �ִ� ���

class Animal;

struct MetaClass
{
	string name;			// classname
	Animal*(*Creator)();	// dynamic creation
};

#define DECLARE_META_CLASS( classname )					\
	static Animal* Create() { return new classname;}	\
	static  const MetaClass  classInfo;					\
	virtual const MetaClass* GetClassInfo() { return &classInfo; }

#define IMPLEMENT_META_CLASS(classname)		\
	const MetaClass classname::classInfo = { #classname, &classname::Create };


#define META_CLASS(classname)  &(classname::classInfo)


class Animal
{
public:
	virtual ~Animal() {}

	DECLARE_META_CLASS( Animal)
};
IMPLEMENT_META_CLASS( Animal)


class Dog : public Animal
{
public:
	DECLARE_META_CLASS(Dog)
};
IMPLEMENT_META_CLASS(Dog)


void foo(Animal* p)
{
	const MetaClass* mc1 = p->GetClassInfo();// p�� ����ؼ� Ÿ�� ���� ���

	//const MetaClass* mc2 = &Dog::classInfo;  // Dog�� ����ؼ� Ÿ������ ���

	const MetaClass* mc2 = META_CLASS(Dog);

	cout << mc1->name << endl;

	if (mc1 == mc2)
	{
		cout << "Dog" << endl;
	}
}


int main()
{
	Dog d;
	foo(&d);
}