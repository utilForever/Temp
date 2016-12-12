#include <iostream>
using namespace std;

// 문제점 :  생성자에서는 가상함수가 동작하지 않는다.

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