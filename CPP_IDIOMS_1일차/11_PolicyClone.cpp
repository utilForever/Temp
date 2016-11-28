// rebind 문제
#include <iostream>
#include <vector>
using namespace std;

// Policy Base Design
// 메모리 할당 정책을 갖는 클래스를 제공한다.

template <typename T> class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }
};

template<typename T, typename Ax = allocator<T>> class list
{
	struct Node
	{
		T data;
		Node* next;
	};

	Ax ax;	// 메모리 할당기. int 할당기...

	? ax2;	// Node의 할당기?

public:
	void resize(int sz)
	{
		// 메모리 할당이 필요한경우 ?
		T* p = ax.allocate(sz);

		// 메모리 해제도 할당기 사용
		ax.deallocate(p);
	}
};

int main()
{
	list<int, allocator<int>> v;
	v.resize(10);
}