#include <iostream>
using namespace std;

// NRVO ���� : 


class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) { cout << "ctor" << endl; }
	~Point() { cout << "dtor" << endl; }
	Point(const Point&) { cout << "copy ctor" << endl; }
};

// ���Ϲ��� 2�� �̻� ������ NRVO�� �������� �ʴ´�.
// �����Ǵ� �����Ϸ��� �ٸ� ��ü�� �ȵȴ�.
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