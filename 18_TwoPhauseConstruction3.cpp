#include <iostream>
using namespace std;

// 18_TwoPhauseConstructor (�̴� ������ ȣ�� )

// �ذ�å 2. �����ڿ����� ���ܰ� �߻��Ҽ� �ִ� �۾��� ���� �ʴ´�.

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