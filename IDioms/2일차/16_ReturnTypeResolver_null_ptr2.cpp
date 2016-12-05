#include <iostream>
using namespace std;


struct xnullptr_t
{
	template<typename T> operator T*() { return (T*)0; }

	// C++11 표준의 nullptr은 bool로의 변환도 허용된다.
	explicit operator bool() { return false; }
};

xnullptr_t xnullptr;

void foo(int n) { cout << "int" << endl; }
void foo(int*) { cout << "*" << endl; }

int main()
{
	int* p1 = xnullptr;
	char* p2 = xnullptr;

	foo(xnullptr);

	int n = xnullptr;	// error
}