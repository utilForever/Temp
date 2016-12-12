#include <iostream>
#include <new>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	Point* p1 = new Point(0,0); // 메모리 할당 + 생성자 호출

	// 메모리 할당과 생성자 호출을 분리하는 기술.
	void* p2 = operator new(sizeof(Point)); // 메모리 할당
	new(p2) Point(0, 0);                    // 생성자 호출.. Placement new

}