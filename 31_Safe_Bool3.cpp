#include <iostream>
using namespace std;

// C++11 explicit
struct Testable
{
	// bool의 암시적 변환은 허용하지 않고 명시적 변환만 가능.
	// 단, if (t)로 사용될 때는 암시적으로 bool로 변환된다.
	explicit operator bool() const { return false; }
};
struct AnotherTestable
{
	explicit operator bool() const { return true; }
};

int main(void)
{
	Testable t;

	//bool b1 = t; // error. bool로의 암시적 변환 안됨.
	
	bool b2 = static_cast<bool>(t); //

	//if (t) {} // ok.. 의도한 코드..

	AnotherTestable at;
	//if (t == at) {} // ?
	//if (t < 0) {} // ?

	return 0;
}