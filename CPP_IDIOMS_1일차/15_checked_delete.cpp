#include <iostream>
#include <memory>
using namespace std;

class Test;

void foo(Test* p)
{
	delete p;
}

class Test
{
public:
	Test()  {cout << "Test()" << endl;}
	~Test() { cout << "~Test()" << endl; }
};

int main()
{
	default_delete<int> a;

	Test* p = new Test;
	foo(p);
}