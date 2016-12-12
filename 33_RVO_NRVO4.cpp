#include <iostream>
using namespace std;

int ctorcall = 0;
int copycall = 0;

class Point
{
public:
	Point()             { ++ctorcall; }
	Point(const Point&) { ++copycall; }
};

Point foo()
{
	Point p;
	return p;
}
int main()
{
	Point p;
	p = foo();

	cout << "ctor : " << ctorcall << endl;
	cout << "copy : " << copycall << endl;
}