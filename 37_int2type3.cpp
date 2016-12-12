// 36_int2type
#include <iostream>
#include <type_traits>
using namespace std;

template<int N> struct int2type
{
	enum { value = N };
};

template<typename T> void foo_imp(const T& value, int2type<0>) { cout << "�����Ͱ� �ƴҶ� �˰���" << endl; }
template<typename T> void foo_imp(const T& value, int2type<1>) { cout << "�������϶� �˰���" << endl; }

template<typename T> void foo(const T& value)
{
	// �����Ϳ� �ƴҶ��� ���� �б� �ϰ� ������.. 
	foo_imp(value, is_pointer<T>::value );
}

int main()
{
	int n = 0;
	foo(&n);
}