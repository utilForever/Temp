#include <iostream>
using namespace std;

class Test
{
	int* p1;
	int* p2;
public:
	Test()
	{
		p1 = new int;
		p2 = new int;
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
	Test t;
}