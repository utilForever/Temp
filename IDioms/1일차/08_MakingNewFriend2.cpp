#include <iostream>
using namespace std;

// Making New Friends : To simplify creation of friend functions for a class template

template<typename T> class Point
{
public:
	T x, y;
	Point(T a = 0, T b = 0) : x(a), y(b) {}

	// friend 함수의 구현을 클래스안에 넣을수 있다... 물론 멤버가 아니 일반 함수이다.
	// class template 의 경우 friend 함수는 클래스 안에 있는게 편하다.!!
	friend ostream& operator<<(ostream& os, const Point<T>& p)
	{
		return os << p.x << " , " << p.y;
	}
};

int main()
{
	Point<int> p(1, 2);
	cout << p << endl;
}


