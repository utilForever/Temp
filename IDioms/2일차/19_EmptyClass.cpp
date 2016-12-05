// 19_EmptyClass

#include <iostream>
#include <new>
using namespace std;

void* operator new(size_t sz)
{
	void* p = malloc(sz);

	if (p == 0)
		throw std::bad_alloc();

	return p;
}

int main()
{
	int* p1 = new int;
	int* p2 = new(nothrow) int;
}

