#include <iostream>
using namespace std;

// �Լ� ���ø��� ����� �ν��Ͻ�ȭ�θ� ����ϰ� �ϴ� ���.
// C++11 ǥ��
//template<typename T> struct identity
//{
//	typedef T type;
//};

// template<typename T> void foo(T a)
template<typename T> void foo(typename identity<T>::type a)		// �Ͻ��� �ν��Ͻ�ȭ�� ���´�.
{

}

int main()
{
	foo<int>(3);	// ����� �ν��Ͻ�ȭ
	// foo(3);		// �Ͻ��� �ν��Ͻ�ȭ

	// C++ perfect forwarding
	// forward(3);
	forward<int>(3);

	// list<int> s(10, 3);
}