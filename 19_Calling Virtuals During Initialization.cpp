#include <iostream>
using namespace std;

// ������ :  �����ڿ����� �����Լ��� �������� �ʴ´�.

class Base
{
public:
	Base() { init(); }

	virtual void init() { cout << "Base init" << endl; }
};

class Derived : public Base
{
public:
	Derived() { }

	virtual void init() { cout << "Derived init" << endl; }
};

int main()
{
	Derived d;
}