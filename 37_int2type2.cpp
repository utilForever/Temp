// 36_int2type
#include <iostream>
using namespace std;


template<int N> struct int2type
{
	enum { value = N };
};

void foo(int n) {}

void foo(int2type<0>) { cout << "0" << endl; }
void foo(int2type<1>) { cout << "1" << endl; }
int main()
{
	foo(0);
	foo(1);

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1);
}