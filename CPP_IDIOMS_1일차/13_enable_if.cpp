#include <iostream>
using namespace std;

// �������� ó���ϴ� �Լ��� ����� �ʹ�.
template<typename T> T square(T a)
{
	return a * a;
}

int main()
{
	square(3.3);
}