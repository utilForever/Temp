#include <iostream>
using namespace std;

// NRVO 제한 : 


class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) { cout << "ctor" << endl; }
	~Point() { cout << "dtor" << endl; }
	Point(const Point&) { cout << "copy ctor" << endl; }
};

// 리턴문이 2개 이상 있으면 NRVO는 지원되지 않는다.
// 지원되는 컴파일러도 다른 객체면 안된다.
Point foo(int n)
{
	Point p;

	if (n == 2)
		return p;

	return p;
}

int main()
{
	Point p1;
	p1 = foo(2);
}