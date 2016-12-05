#include <iostream>
#include <thread>	// C++11 스레드
using namespace std;

void foo(int& a)
{
	a = 10;
}

int main()
{
	int n = 0;
	thread t(&foo, ref(n));	// 이 순간 스레드가 생성된다.
	// 값 방식으로 만들어졌기에 스레드 함수 인자가 참조라면 ref()로 묶어서 보내야 한다.

	t.join();
	cout << n << endl;	// 0? 10?
}