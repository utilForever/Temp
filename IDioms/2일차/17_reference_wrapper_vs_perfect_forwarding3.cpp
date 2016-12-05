#include <iostream>
#include <thread>	// C++11 ������
using namespace std;

void foo(int& a)
{
	a = 10;
}

int main()
{
	int n = 0;
	thread t(&foo, ref(n));	// �� ���� �����尡 �����ȴ�.
	// �� ������� ��������⿡ ������ �Լ� ���ڰ� ������� ref()�� ��� ������ �Ѵ�.

	t.join();
	cout << n << endl;	// 0? 10?
}