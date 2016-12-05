#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* src, int sz)
{
	memcpy(dst, src, sizeof(T)*sz);
}

int main()
{
	char s1[10] = "hello";
	char s2[10];

	strcpy(s2, s1);
}