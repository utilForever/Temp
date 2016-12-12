#include <iostream>
using namespace std;

// RVO : Return Value Optimization
class Point
{	
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) { cout << "ctor" << endl; }
	~Point()                    { cout << "dtor" << endl; }
	Point(const Point&)         { cout << "copy ctor" << endl; }
};

Point foo(int n)
{
	// NRVO (Named RVO)
	Point p;
	return p;	// ���Ͽ� �ӽ� ��ü�� �����ȴ�, return Point(p);

	// ����� �������� ����, ����鼭 ��������.
	// RVO (Return Value Optimization)
	//return Point(0, 0);
}

int main()
{
	Point p1;
	p1 = foo(2);
}