// 12_SFINAE
// Substitution Failure Is Not An Error

// Template �Լ��� �ν��Ͻ�ȭ �� �� ġȯ�� �Ұ����ϸ� �ڵ带 �������� �ʴ´�.
// ������ �ƴ϶� �Լ��� ��������� �ʴ´ٴ� ��...

// �Ͻ��� ����ȯ�� ���� ������ �Լ��� ������ ��� ����������.

#include <iostream>
using namespace std;

// �Լ� ã�� ����
// 1. ��Ȯ�� Ÿ��
// 2. template
// 3. �Ͻ��� ��ȯ
// 4. ����� ��ȯ �Լ��� ���� ��ȯ
// 5. ���� ���� �Լ�(...) ȣ��
template<typename T> typename T::type foo(T a) { cout << "T" << endl; return a; }

void foo(double d) { cout << "double" << endl; }

int main()
{
	foo(3);		// T
	foo(3.3);	// double
}