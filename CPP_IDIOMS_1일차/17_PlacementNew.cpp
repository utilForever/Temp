#include <iostream>
#include <new>
using namespace std;

// C++ 표준의 3가지 new

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { cout << "생성자" << endl; }
};

int main()
{
	Point* p1 = new Point(10, 10);
}

