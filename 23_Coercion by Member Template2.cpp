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

	// template ���� ������
	// U*�� T*�� ���� �����ϴٸ� sp<U>�� sp<T>�� ���� �����ؾ� �ȴ�.
	// => generic ���� �����ڰ� �ʿ��ϴ�.
	template <typename U>
	sp(const sp<U>& other) : obj(other.obj) {}

	// �Ϲ�ȭ�� ���� �����ڰ� �����Ϸ��� friend ������ �ʿ��ϴ�.
	template <typename> friend class sp;
};

int main()
{
	sp<Dog> p1 = new Dog;
	sp<Dog> p2 = p1;   // ok.. ���� ������

	sp<Animal> p3 = p1; // ?
}
