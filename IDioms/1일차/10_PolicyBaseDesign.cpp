#include <iostream>
#include <vector>
using namespace std;

// Policy Base Design
/*
// 메모리 할당 정책을 가지는 클래스를 제공한다.
template<typename T> class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }
};
template<typename T, typename Ax = allocator<T> > class vector
{
	Ax ax; // 메모리 할당기.
public:
	void resize(int sz)
	{
		// 메모리 할당이 필요한경우 ?
		T* p = ax.allocate(sz);

		// 메모리 해지도 할당기 사용
		ax.deallocate(p);
	}
};
*/
int main()
{
	vector<int, allocator<int> > v;
	v.resize(10);
}


