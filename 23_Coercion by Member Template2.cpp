#include <iostream>
using namespace std;

// 22. Coercion by Member Template 

struct Animal {};

class Dog : public Animal {};


template<typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0) : obj(p) {}
	// ......

	// template 복사 생성자
	// U*가 T*로 복사 가능하다면 sp<U>는 sp<T>로 복사 가능해야 된다.
	// => generic 복사 생성자가 필요하다.
	template <typename U>
	sp(const sp<U>& other) : obj(other.obj) {}

	// 일반화된 복사 생성자가 동작하려면 friend 연결이 필요하다.
	template <typename> friend class sp;
};

int main()
{
	sp<Dog> p1 = new Dog;
	sp<Dog> p2 = p1;   // ok.. 복사 생성자

	sp<Animal> p3 = p1; // ?
}
