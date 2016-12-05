#include <iostream>
#include <memory>
using namespace std;

class Test;

void foo(Test* p)
{
	static_assert(sizeof(Test) > 0, "error T is imcomplete");
	delete p;
}


class Test
{
public:
	Test()  { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main()
{
	Test* p = new Test;
	foo(p);
	
	default_delete<int> d;
	unique_ptr<int> p1(new int);
}