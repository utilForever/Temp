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
	// if (f) { } // ��ü�� if()���� �־ test �غ��� - scalar test


	Testable a;

	if (a) {} // ok.. �ǵ��� �ڵ�..

	AnotherTestable b;
	if (a == b) { } // ?
	if (a < 0)  { } // ?

	return 0;
}