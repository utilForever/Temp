#include <iostream>
using namespace std;

// 1. #pragma message : 컴파일시에 메세지를 출력할수 있다.
// 2. __LINE__ 을 문자열로 변경하는 기술.

#define TOSTRIMP(x)   #x
#define TOSTR(x)    TOSTRIMP(x)
#define LOG(desc)   message ( __FILE__ "(" TOSTR(__LINE__) ") : " desc)


int main()
{
#pragma message("이 코드는 알고리즘을 변경해야 합니다.")
	//.....

#pragma LOG("AAAAAA")
}



// 매크로 상수를 다시 #을 사용해서 문자열로 변경할때는
// 2번의 매크로 과정을 거치게 해야 한다.
/*
#define MAX 100
#define TOSTRING( x ) #x
#define TOSTRING2( x ) TOSTRING( x )

int main()
{
	int x = 10;
	cout << x << endl;          // 10
	cout << TOSTRING(x) << endl; // "x"
	cout << TOSTRING(MAX) << endl; //   MAX
	cout << TOSTRING2(MAX) << endl;// 100
				// TOSTRING(100)

	cout << TOSTRING(__LINE__) << endl;
	cout << TOSTRING2(__LINE__) << endl;
}
*/














