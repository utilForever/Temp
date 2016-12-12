#include <iostream>
using namespace std;

// 18_TwoPhauseConstructor (�̴� ������ ȣ�� )

// ������ : �����ڿ��� ���ܰ� �߻��ϸ� �Ҹ��ڴ� ȣ����� �ʴ´�.

// ������ ���� �� �ܺο� �˸��� ������ ����� ���� �ۿ� ����.
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