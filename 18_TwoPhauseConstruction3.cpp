#include <iostream>
using namespace std;

// 18_TwoPhauseConstructor (이단 생성자 호출 )

// 해결책 2. 생성자에서는 예외가 발생할수 있는 작업을 하지 않는다.

struct Resource
{
	Resource() { cout << "Resource()" << endl; }
	~Resource() { cout << "~Resource()" << endl; }
};

class Test
{
	Resource* p1;
	Resource* p2;
public:
	Test() : p1(0), p2(0) {}

	void Construct()
	{
		p1 = new Resource;
		p2 = new Resource;
		throw 1;
	}
	~Test()	
	{
		cout << "~Test()" << endl;	
		delete p1;
		delete p2;
	}
};

int main()
{
	try
	{
		Test t;
		t.Construct();
	}
	catch (...) {}
}