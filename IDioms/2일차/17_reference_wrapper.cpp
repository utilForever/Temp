#include <iostream>
#include <functional>
using namespace std;

// C++ 기본 참조 : 참조의 이동이 아닌 값의 이동이다.
// reference_wrapper : 값이 아닌 참조의 이동

template <typename T> class xreference_wrapper
{
	T* obj;

public:
	xreference_wrapper(T& a) : obj(&a) { }

	// C++의 기본 참조 문법과 호환되게 하자
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