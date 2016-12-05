#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

void foo(int a, int& b) { cout << "foo" << endl; b = 100; }

// �Ϻ��� �����ڿ� reference wrapper 
class Test
{
public:
	Test(int a, int& b) { cout << "Test()" << endl; b = 100; }
};

int main()
{
	int n1 = 10;
	vector<Test> v;
	
	//Test t(10, n1);
	//v.push_back(t);

	// C++11�� Ư¡ : �ܺο��� ��ü�� ������ �ʰ� vector�� ���������� ����� ����.
	// ���, �����ڿ��� ����� ���ڸ� �����ؾ� �Ѵ�.
	v.emplace_back(10, n1);	// �� �Լ��� ���������� Test�� �����Ѵ�.
	
	cout << n1 << endl;
}

