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
// nothrow 버전.
struct nothrow_t {};	// empty class : 아무 멤버도 없는 클래스
						// 아무 것도 없지만 타입이다.
						// 1. 함수 오버로딩
						// 2. 템플릿 인자로
						// 활용된다.

nothrow_t nothrow;

void* operator new(size_t sz, nothrow_t )
{
	void* p = malloc(sz);

	return p;
}

// #define nothrow 0

int main()
{
	int* p1 = new int;			// 할당 실패시 예외 전달(std::bad_alloc)
	int* p2 = new(nothrow) int; // 할당 실패시 0리턴.
}

// C++의 new는 3개
// 1. 일반 new : new Point
// 2. nothrow new : new(nothrow)
// 3. placement new : 생성자를 호출하기 위한 것