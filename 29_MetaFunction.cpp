#include <iostream>
using namespace std;

// 메타 함수 : 컴파일시간에 수행되는 함수
// 특징 : 컴파일 시간 재귀 사용
//		  재귀를 종료하기 위해 TEMPLATE 전문화 문법을 사용한다.

template<int N> struct Factorial
{
	enum { value = N * Factorial<N-1>::value };
};

template<> struct Factorial<1>
{
	enum { value = 1 };
};


int main()
{
	int n = Factorial<5>::value;

	cout << n << endl;
}

// C++11 style
constexpr int factorial(int n)
{
	return n == 1 ? 1 : n* factorial(n - 1);
}