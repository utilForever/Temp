#include <iostream>
using namespace std;

// ��Ÿ �Լ� : �����Ͻð��� ����Ǵ� �Լ�
// Ư¡ : ������ �ð� ��� ���
//		  ��͸� �����ϱ� ���� TEMPLATE ����ȭ ������ ����Ѵ�.

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