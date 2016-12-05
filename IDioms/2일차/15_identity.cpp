#include <iostream>
using namespace std;

// 함수 템플릿을 명시적 인스턴스화로만 사용하게 하는 기술.
// C++11 표준
//template<typename T> struct identity
//{
//	typedef T type;
//};

// template<typename T> void foo(T a)
template<typename T> void foo(typename identity<T>::type a)		// 암시적 인스턴스화를 막는다.
{

}

int main()
{
	foo<int>(3);	// 명시적 인스턴스화
	// foo(3);		// 암시적 인스턴스화

	// C++ perfect forwarding
	// forward(3);
	forward<int>(3);

	// list<int> s(10, 3);
}