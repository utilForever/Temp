#include <iostream>
using namespace std;

// NRVO มฆวั : 


class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) { cout << "ctor" << endl; }
	~Point() { cout << "dtor" << endl; }
	Point(const Point&) { cout << "copy ctor" << endl; }
};

Point foo(int n)
{
	Point p;

	return p;
}

int main()
{
	Point p1;
	p1 = foo(2);
}