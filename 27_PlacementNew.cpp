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
	Point* p1 = new Point(0,0); // �޸� �Ҵ� + ������ ȣ��

	// �޸� �Ҵ�� ������ ȣ���� �и��ϴ� ���.
	void* p2 = operator new(sizeof(Point)); // �޸� �Ҵ�
	new(p2) Point(0, 0);                    // ������ ȣ��.. Placement new

}