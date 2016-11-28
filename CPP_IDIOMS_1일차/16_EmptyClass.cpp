#include <iostream>
#include <new>
using namespace std;

int main()
{
	int* p1 = new int;
	int* p2 = new(nothrow) int;
}

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { cout << "»ý¼ºÀÚ" << endl; }
};