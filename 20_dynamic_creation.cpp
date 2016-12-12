#include <iostream>
using namespace std;

// 20_dynamic_creation - 동적 생성

// 문제점 : 클래스 정보를 함수인자로 전달하려면 ?

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


