#include <iostream>
using namespace std;

// 20_dynamic_creation - 동적 생성

// 해결책 : 객체를 생성하는 정적 메소드

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


