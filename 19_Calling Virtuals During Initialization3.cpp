#include <iostream>
using namespace std;

// �ذ�å 2. static ��� �Լ��� ���� ����� ��ü ����

class Base
{
public:
	Base() {  }
	virtual void init() { cout << "Base init" << endl; }

	static Base* Create() 
	{
		Base* p = new Base;
		p->init();
		return p;
	}
};

class Derived : public Base
{
public:
	Derived() { }
	virtual void init() { cout << "Derived init" << endl; }

	static Derived* Create()
	{
		Derived* p = new Derived;
		p->init();
		return p;
	}
};

int main()
{
	// Derived* p = new Derived;
	Derived* p = Derived::Create();
}