#include <iostream>
#include <new>
using namespace std;

// C++ ǥ���� 3���� new

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { cout << "������" << endl; }
};

int main()
{
	Point* p1 = new Point(10, 10);
}

