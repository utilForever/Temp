#include <iostream>
#include <type_traits>  
using namespace std;

// C++ ǥ������ȸ�� int2type�� ������ �Ʒ� ���ø��� C++11 ǥ�ؿ� ����.
template<typename T, T N> struct integral_constant
{
static constexpr T value = N;
};

//integral_constant<int, 0> n0;
//integral_constant<int, 1> n1;
//integral_constant<short, 0> s0;
//integral_constant<short, 1> s1;

// true / false           : �������� ��Ÿ���� ��, ���� Ÿ��
// true_type / false_type : �������� ��Ÿ���� Ÿ��, �ٸ�Ÿ��
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> fasle_type;

// C++11 ǥ���� is_pointer
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};


//--------------------------------------------------
template<typename T> void foo_imp(const T& value, int2type<0>) { cout << "�����Ͱ� �ƴҶ� �˰���" << endl; }
template<typename T> void foo_imp(const T& value, int2type<1>) { cout << "�������϶� �˰���" << endl; }

template<typename T> void foo(const T& value)
{
	foo_imp(value, int2type<is_pointer<T>::value>());
}

int main()
{
	int n = 0;
	foo(&n);
}



