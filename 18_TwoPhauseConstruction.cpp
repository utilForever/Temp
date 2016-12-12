#include <iostream>
using namespace std;

// 18_TwoPhauseConstructor (이단 생성자 호출 )

// 문제점 : 생성자에서 예외가 발생하면 소멸자는 호출되지 않는다.

// 생성자 실패 시 외부에 알리는 유일한 방법은 예외 밖에 없다.
struct Resource 
{
	Resource()  { cout << "Resource()" << endl; }
	~Resource() { cout << "~Resource()" << endl; }
};

class Test
{
	Resource* p1;
	Resource* p2;
public:
	Test()
	{
		cout << "Test()" << endl;
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
	}
	catch (...){}
}