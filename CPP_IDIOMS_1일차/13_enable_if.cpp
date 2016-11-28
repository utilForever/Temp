#include <iostream>
using namespace std;

// 정수형을 처리하는 함수를 만들고 싶다.
template<typename T> T square(T a)
{
	return a * a;
}

int main()
{
	square(3.3);
}