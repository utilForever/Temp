#include <iostream>
using namespace std;

// Making New Friends : To simplify creation of friend functions for a class template

template<typename T> class Point
{
public:
	T x, y;
	Point(T a = 0, T b = 0) : x(a), y(b) {}

	// friend �Լ��� ������ Ŭ�����ȿ� ������ �ִ�... ���� ����� �ƴ� �Ϲ� �Լ��̴�.
	// class template �� ��� friend �Լ��� Ŭ���� �ȿ� �ִ°� ���ϴ�.!!
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


