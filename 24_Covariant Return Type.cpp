// 23. Covariant Return Types

#include <iostream>
using namespace std;

class Shape
{
public:
	virtual Shape* Clone() = 0;
};
class Rect : public Shape
{
public:
	// 가상 함수를 재정의 할 때 리턴 타입을 변경할 수 있다.
	// 단, 상속 계층의 타입으로만 가능하다. int 등으로는 할 수 없다.
	// 공변 변환의 법칙 (Covariant return type)
	virtual Shape* Clone() { return new Rect; }
};

int main()
{

}
