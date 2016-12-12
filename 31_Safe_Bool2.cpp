#include <iostream>
using namespace std;

// �ذ�å : ��� �Լ� �����ͷ� ��ȯ�� �ϸ� �ȴ�.

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

	if (a) {} // ok.. �ǵ��� �ڵ�..

	AnotherTestable b;
	if (a == b) {} // ?
	if (a < 0) {} // ?

	return 0;
}