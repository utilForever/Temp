// 23_trivial
#include <iostream>
#include <type_traits>
using namespace std;

class A {};

class B : public A {};

int main()
{
	cout << boolalpha;
	cout << is_trivial<Test>::value << endl;
}