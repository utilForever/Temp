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
};

int main()
{
	sp<Dog> p1 = new Dog;
	sp<Dog> p2 = p1;   // ok.. 복사 생성자

	sp<Animal> p3 = p1; // ?
}
