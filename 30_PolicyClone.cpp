#include <iostream>
#include <vector>
using namespace std;

// Policy Base Design
// �޸� �Ҵ� ��å�� ������ Ŭ������ �����Ѵ�.
template<typename T> class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }

	template <typename U> struct rebind
	{
		typedef allocator<U> type;
	};
};

template<typename T, typename Ax = allocator<T> > class list
{
	struct Node
	{
		T data;
		Node* next;
	};

	Ax ax; // �޸� �Ҵ��. int  �Ҵ��.. => allocator<int>

	// ? ax2; // Node�� �Ҵ�Ⱑ �־�� �մϴ�...
	typename Ax::rebind<Node>::type Ax2;	// allocator<Node>
public:
	void resize(int sz)
	{
		// �޸� �Ҵ��� �ʿ��Ѱ�� ?
		T* p = ax.allocate(sz);

		// �޸� ������ �Ҵ�� ���
		ax.deallocate(p);
	}
};

int main()
{
	list<int, allocator<int> > v;
	v.resize(10);
}


