#include <iostream>
using namespace std;

// Traits : ���ø� ���� T�� �پ��� �Ӽ��� �����ϴ� ���

#include <type_traits>

template<typename T> void foo(T a)
{
	// 1. T �� ������ ���� �����ϴ� ���
	if (is_pointer<T>::value)
		cout << "������" << endl;

	// 2. T�� ����(����)�� Ÿ�Ծ��
	typename remove_pointer<T>::type n;

	cout << typeid(n).name() << endl;
}

int main()
{
	int n = 0;
	foo(&n);
}