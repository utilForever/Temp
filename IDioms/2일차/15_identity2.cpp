#include <iostream>
using namespace std;

// Ŭ���� ���ø��� �����ϴ� �Լ� ���ø�.

template<typename T> void foo(T p) {}


//template<typename T, typename U> pair<T, U> make_pair(T a, U b)
//{
//	return pair<T, U>(a, b);
//}

int main()
{
	// foo(pair<int, double>(10, 3.3));

	// foo(pair(10, 3.3));	// pair�� class template�̹Ƿ� �Ͻ��� �߷��� �ȵȴ�.

	foo(make_pair(10, 3.3));	// function template�� �Ͻ��� �߷��� �ȴ�.
}