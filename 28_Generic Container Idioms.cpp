#include <iostream>
using namespace std;

// Generic Container Idioms
// 일반화 컨테이너를 설계할때 참고할 사항.

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
	//	buff = new T[sz];	// 문제점 : T는 반드시 디폴트 생성자가 있어야 한다.
	//} 

	Vector(int n, T value = T()) : sz(n)
	{
		// buff = new T[sz];	// 문제점 : T는 반드시 디폴트 생성자가 있어야 한다.

		// 메모리 할당과 생성자 호출을 분리하라!
		buff = (T*)operator new(sizeof(T) * sz);

		for (int i = 0; i < sz; ++i)
			new(&buff[i]) T(value);		// 복사 생성자로 초기화!
	} 
};

int main()
{
	// Vector<Point> v(10);
	Vector<Point> v(10, Point(1, 1));
}