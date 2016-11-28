#include <iostream>
using namespace std;

// offset_of

struct People
{
	char name[16];
	int  age;	
};

#define offset_of(TYPE, MEMBER) (size_t)&(((TYPE*)0)->MEMBER)

int main()
{
	People p;

	printf("%p\n", &p);			// 1000
	printf("%p\n", &(p.age));	// 1016

	// ((People*)0)->age = 10;		// ?

	// printf("%p\n", &((People*)0)->age);
	printf("%d\n", offset_of(People, age));	// 구조체 안에서 age의 offset 값
}