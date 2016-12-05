#include <iostream>
#include <functional>
using namespace std;

// C++ �⺻ ���� : ������ �̵��� �ƴ� ���� �̵��̴�.
// reference_wrapper : ���� �ƴ� ������ �̵�

template <typename T> class xreference_wrapper
{
	T* obj;

public:
	xreference_wrapper(T& a) : obj(&a) { }

	// C++�� �⺻ ���� ������ ȣȯ�ǰ� ����
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;

	//int& r1 = n1;
	//int& r2 = n2;
	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	r1 = r2;

	cout << n1 << endl;	// 20	10
	cout << n2 << endl;	// 20	20
	cout << r1 << endl;	// 20	20
	cout << r2 << endl; // 20	20
}