#include <iostream>
using namespace std;

// Making New Friends : To simplify creation of friend functions for a class template

template <typename T>
class Point
{
public:
	T x, y;

	Point(T a = 0, T b = 0) : x(a), y(b) {}

	// friend ostream& operator<<(ostream& os, const Point<T>& p);

	// Point<T>�� operator<<(Point<��� Ÿ��>)�� ģ����.
	template <typename U>
	ostream& operator<<(ostream& os, const Point<U>& p)
};

template <typename T>
ostream& operator<<(ostream& os, const Point<T>& p)
{
	return os << p.x << " , " << p.y;
}
int main()
{
	Point<int> p(1, 2);
	cout << p << endl;
}

//template <typename T>
//void foo(T a)
//{
//
//}
//
//// ���ڰ� double�� ���� �� �Լ� ����.
////void foo(double d)
////{
////
////}
//
//void foo(double d);
//
//int main()
//{
//	foo(3);
//	foo(3.3);
//}