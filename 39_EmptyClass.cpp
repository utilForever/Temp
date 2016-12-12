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
// nothrow ����.
struct nothrow_t {};	// empty class : �ƹ� ����� ���� Ŭ����
						// �ƹ� �͵� ������ Ÿ���̴�.
						// 1. �Լ� �����ε�
						// 2. ���ø� ���ڷ�
						// Ȱ��ȴ�.

nothrow_t nothrow;

void* operator new(size_t sz, nothrow_t )
{
	void* p = malloc(sz);

	return p;
}

// #define nothrow 0

int main()
{
	int* p1 = new int;			// �Ҵ� ���н� ���� ����(std::bad_alloc)
	int* p2 = new(nothrow) int; // �Ҵ� ���н� 0����.
}

// C++�� new�� 3��
// 1. �Ϲ� new : new Point
// 2. nothrow new : new(nothrow)
// 3. placement new : �����ڸ� ȣ���ϱ� ���� ��