#include <iostream>
#include <typeinfo>
using namespace std;

// 21_RTTI
// 실행시간에 타입의 정보를 확인하는 기술

class Animal
{
public:
	virtual ~Animal() {}
};

class Dog : public Animal {};
class Cat : public Animal {};

void foo(Animal* p)
{
	const type_info& t1 = typeid(*p);  // 객체를 사용해서 type_info 꺼내기
	const type_info& t2 = typeid(Dog); // 클래스이름을 사용해서 type_info 꺼내기

	cout << t1.name() << endl;

	if (t1 == t2)  
	{
	}
}


int main()
{
	Dog d;
	foo(&d);
}