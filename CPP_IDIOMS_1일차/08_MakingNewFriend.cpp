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

	// Point<T>는 operator<<(Point<모든 타입>)와 친구다.
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
//// 인자가 double일 때는 이 함수 실행.
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