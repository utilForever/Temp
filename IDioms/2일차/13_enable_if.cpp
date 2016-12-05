#include <iostream>
#include <type_traits>
using namespace std;

// C++ ǥ�� enable_if

// enable_if<bool ��, T>::type => bool ���� ���̸� type�� "T"�� �ȴ�.
//                                          �����̸� type�� ġȯ ����

template<bool, typename T = void> struct xenable_if { };

template<typename T> struct xenable_if<true, T>
{
	typedef T type;
};

// �������� ó���ϴ� �Լ��� ����� �ʹ�.
template<typename T> typename xenable_if<is_integral<T>::value, T>::type square(T a)
{
	return a * a;
}

// T�� ������ ���� ��������� �ϰ� �ʹ�.
// template<typename T> void foo(T a) { }
template<typename T> typename xenable_if<is_integral<T>::value>::type foo(T a) { }

// enable_if�� �Լ� ������ Ÿ������ ���?
// 1. ���� ���ڷ� ���� ���, 2. �Լ� ���ڷ� ����ҰŸ� �� ��° ���ڷ� ��� (�߷� ����...)
template<typename T> void goo(typename enable_if<is_integral<T>::value, T>::type a) { }

int main()
{
	// square(3.3);
	square(3);
}