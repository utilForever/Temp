#include <iostream>
#include <memory>
using namespace std;

// 18_TwoPhauseConstructor (이단 생성자 호출 )

// 해결책 1. 스마트 포인터를 사용한 자원 관리
//        => Resource Acquision Is Initialize ( RAII )

struct Resource
{
	Resource() { cout << "Resource()" << endl; }
	~Resource() { cout << "~Resource()" << endl; }
};

class Test
{
	unique_ptr<Resource> p1;
	unique_ptr<Resource> p2;
public:
	Test() : p1 ( new Resource), p2( new Resource)
	{
		cout << "Test()" << endl;
		throw 1;
	}
	~Test()	{	cout << "~Test()" << endl;	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...) {}
}