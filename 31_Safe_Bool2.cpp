#include <iostream>
using namespace std;

// 해결책 : 멤버 함수 포인터로 변환을 하면 된다.

struct Testable
{
	void true_function() {};

	typedef void(Testable::*PF)();

	operator PF() const { return &Testable::true_function; }
};

struct AnotherTestable
{
	void true_function() {};
	typedef void(AnotherTestable::*PF)();

	operator PF() const { return &AnotherTestable::true_function; }
};

int main(void)
{
	Testable a;

	if (a) {} // ok.. 의도한 코드..

	AnotherTestable b;
	if (a == b) {} // ?
	if (a < 0) {} // ?

	return 0;
}