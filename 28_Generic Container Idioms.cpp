#include <iostream>
using namespace std;

// Generic Container Idioms
// �Ϲ�ȭ �����̳ʸ� �����Ҷ� ������ ����.

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

template<typename T> class Vector
{
	T* buff;
	int sz;
public:
	//Vector(int n) : sz(n)s
	//{
	//	buff = new T[sz];	// ������ : T�� �ݵ�� ����Ʈ �����ڰ� �־�� �Ѵ�.
	//} 

	Vector(int n, T value = T()) : sz(n)
	{
		// buff = new T[sz];	// ������ : T�� �ݵ�� ����Ʈ �����ڰ� �־�� �Ѵ�.

		// �޸� �Ҵ�� ������ ȣ���� �и��϶�!
		buff = (T*)operator new(sizeof(T) * sz);

		for (int i = 0; i < sz; ++i)
			new(&buff[i]) T(value);		// ���� �����ڷ� �ʱ�ȭ!
	} 
};

int main()
{
	// Vector<Point> v(10);
	Vector<Point> v(10, Point(1, 1));
}