#include <iostream>
#include <memory>
using namespace std;

class Test;	// 클래스 전방선언..
			// 불완전한 개체 (Incomplete object) : 클래스 전방 선언만 있는 개체
			// delete하면 소멸자가 호출되지 않는다.

void foo(Test* p)
{
	// sizeof(Test);	// 완전한 객체만 size를 구할 수 있다.

	static_assert(sizeof(Test) > 0, "Can't delete incomplete object");
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
	
	//default_delete<int> d;
	//unique_ptr<int> p1(new int);
}