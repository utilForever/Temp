#include <iostream>
#include <memory>
using namespace std;

class Test;	// Ŭ���� ���漱��..
			// �ҿ����� ��ü (Incomplete object) : Ŭ���� ���� ���� �ִ� ��ü
			// delete�ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.

void foo(Test* p)
{
	// sizeof(Test);	// ������ ��ü�� size�� ���� �� �ִ�.

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