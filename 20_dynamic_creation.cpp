#include <iostream>
using namespace std;

// 20_dynamic_creation - ���� ����

// ������ : Ŭ���� ������ �Լ����ڷ� �����Ϸ��� ?

class Shape {};

class Rect   : public Shape {};
class Circle : public Shape {};

void foo(string type)
{
	Shape* p = new type;
}

int main()
{
	foo("Rect");
}


