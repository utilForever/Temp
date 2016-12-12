#include <iostream>
using namespace std;

// 20_dynamic_creation - ���� ����

// �ذ�å : ��ü�� �����ϴ� ���� �޼ҵ�

class Shape {};

class Rect : public Shape 
{
public:
	static Shape* Create() { return new Rect; }
};

class Circle : public Shape 
{
public:
	static Shape* Create() { return new Circle; }
};

void foo( Shape*(*creator)() )
{
	Shape* p = creator();
}

int main()
{
	foo(&Rect::Create);
	foo(&Circle::Create);
}


