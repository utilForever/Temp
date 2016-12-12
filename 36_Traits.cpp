#include <iostream>
using namespace std;

// Traits : 템플릿 인자 T의 다양한 속성을 조사하는 기술

#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. T 가 포인터 인지 조사하는 기술
	if (is_pointer<T>::value)
		cout << "포인터" << endl;

	// 2. T의 연관(변형)된 타입얻기
	typename remove_pointer<T>::type n;

	cout << typeid(n).name() << endl;
}

int main()
{
	int n = 0;
	foo(&n);
}