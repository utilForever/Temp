#include <iostream>
using namespace std;

// 클래스 템플릿을 생성하는 함수 템플릿.

template<typename T> void foo(T p) {}


//template<typename T, typename U> pair<T, U> make_pair(T a, U b)
//{
//	return pair<T, U>(a, b);
//}

int main()
{
	// foo(pair<int, double>(10, 3.3));

	// foo(pair(10, 3.3));	// pair는 class template이므로 암시적 추론이 안된다.

	foo(make_pair(10, 3.3));	// function template은 암시적 추론이 된다.
}