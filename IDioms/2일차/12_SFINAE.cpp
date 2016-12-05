// 12_SFINAE
// Substitution Failure Is Not An Error

// Template 함수를 인스턴스화 할 때 치환이 불가능하면 코드를 생성하지 않는다.
// 오류가 아니라 함수가 만들어지지 않는다는 것...

// 암시적 형변환을 통한 ㅏㄷ른 함수가 있으면 사용 가능해진다.

#include <iostream>
using namespace std;

// 함수 찾는 순서
// 1. 정확한 타입
// 2. template
// 3. 암시적 변환
// 4. 사용자 변환 함수에 의한 변환
// 5. 가변 인자 함수(...) 호출
template<typename T> typename T::type foo(T a) { cout << "T" << endl; return a; }

void foo(double d) { cout << "double" << endl; }

int main()
{
	foo(3);		// T
	foo(3.3);	// double
}