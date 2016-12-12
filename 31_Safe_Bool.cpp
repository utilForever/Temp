#include <iostream>
using namespace std;

struct Testable
{
	operator bool() const {	return false;	}
};
struct AnotherTestable
{
	operator bool() const { return true;	}
};

int main(void)
{
	// File f("a.txt");
	// if (f) { } // 객체를 if()문에 넣어서 test 해보자 - scalar test


	Testable a;

	if (a) {} // ok.. 의도한 코드..

	AnotherTestable b;
	if (a == b) { } // ?
	if (a < 0)  { } // ?

	return 0;
}