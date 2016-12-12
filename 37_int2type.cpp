// 36_int2type
#include <iostream>
using namespace std;

// 개념 : 정수형 상수를 독립된 타입으로 만드는 기술
//       컴파일 시간 상수를 함수 오버로딩에 활용할수 있다.

void foo(int n) {} 

int main()
{
	foo(0);
	foo(1);
}