#include <iostream>
using namespace std;

// C++11 explicit
struct Testable
{
	// bool�� �Ͻ��� ��ȯ�� ������� �ʰ� ����� ��ȯ�� ����.
	// ��, if (t)�� ���� ���� �Ͻ������� bool�� ��ȯ�ȴ�.
	explicit operator bool() const { return false; }
};
struct AnotherTestable
{
	explicit operator bool() const { return true; }
};

int main(void)
{
	Testable t;

	//bool b1 = t; // error. bool���� �Ͻ��� ��ȯ �ȵ�.
	
	bool b2 = static_cast<bool>(t); //

	//if (t) {} // ok.. �ǵ��� �ڵ�..

	AnotherTestable at;
	//if (t == at) {} // ?
	//if (t < 0) {} // ?

	return 0;
}