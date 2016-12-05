#include <iostream>
#include <type_traits>
using namespace std;

// C++ 표준 enable_if

// enable_if<bool 값, T>::type => bool 값이 참이면 type은 "T"가 된다.
//                                          거짓이면 type은 치환 실패

template<bool, typename T = void> struct xenable_if { };

template<typename T> struct xenable_if<true, T>
{
	typedef T type;
};

// 정수형을 처리하는 함수를 만들고 싶다.
template<typename T> typename xenable_if<is_integral<T>::value, T>::type square(T a)
{
	return a * a;
}

// T가 정수일 때만 만들어지게 하고 싶다.
// template<typename T> void foo(T a) { }
template<typename T> typename xenable_if<is_integral<T>::value>::type foo(T a) { }

// enable_if를 함수 인자의 타입으로 사용?
// 1. 리턴 인자로 많이 사용, 2. 함수 인자로 사용할거면 두 번째 인자로 사용 (추론 실패...)
template<typename T> void goo(typename enable_if<is_integral<T>::value, T>::type a) { }

int main()
{
	// square(3.3);
	square(3);
}