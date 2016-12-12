#include <iostream>
using namespace std;

// «ÿ∞·√• 1. two phase construction

class Base
{
public:
	Base() {}

	void Construct() { init(); }

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
	d.Construct();
}