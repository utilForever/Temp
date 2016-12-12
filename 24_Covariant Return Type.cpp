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
	// ���� �Լ��� ������ �� �� ���� Ÿ���� ������ �� �ִ�.
	// ��, ��� ������ Ÿ�����θ� �����ϴ�. int �����δ� �� �� ����.
	// ���� ��ȯ�� ��Ģ (Covariant return type)
	virtual Shape* Clone() { return new Rect; }
};

int main()
{

}
