#include <iostream>
#include <string>
using namespace std;

// 객체가 특정 인터페이스를 지원하는지 조사하는 기술.
struct Shape
{
	virtual void Draw() const = 0;
};
struct Rollable
{
	virtual void roll() const = 0;
};

class Rect : public Shape
{
public:
	virtual void Draw() const {}
};

class Circle : public Shape, public Rollable
{
public:
	virtual void Draw() const {}
	virtual void roll() const {}
};

int main()
{
	// Shape* p = new Rect;
	Shape* p = new Circle;

	if (Rollable* p2 = dynamic_cast<Rollable*>(p))
	{
		cout << "support" << endl;
		p2->roll();
	}
	
}