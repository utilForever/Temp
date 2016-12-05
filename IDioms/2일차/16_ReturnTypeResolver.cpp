#include <iostream>
#include <vector>
#include <list>
using namespace std;


template<typename T> void show(T& c)
{
	for (auto& n : c)
	{
		cout << n << endl;
	}
	return;
}

//int main()
//{
//	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
//
//	show<list<int>>(s);
//	// 1. �Լ� ���ø��� ���ڴ� �Ͻ��� �߷е� �� �ִ�.
//	show(s);
//}

//template<typename Container> Container getRandomN(int n)
//{
//	Container c;
//
//	for (size_t i = 0; i < n; ++i)
//		c.insert(c.end(), rand());
//
//	return c;
//}

class getRandomN
{
	int n;
public:
	getRandomN(int _n) : n(_n) { }

	// ��ȯ ������ �Լ�
	operator int() { return 0; } // getRandomN�� int�� ��ȯ�� �ʿ��� �� ȣ��ȴ�.

	template<typename T> operator T()
	{
		T c;
		
		for (size_t i = 0; i < n; ++i)
			c.insert(c.end(), rand());
		
		return c;
	}
};

int main()
{
	// 2. �Լ� ���ø��� ���� Ÿ���� �Ͻ��� �߷е� �� ����.
	// list<int> s = getRandomN(10);	// error
	// list<int> s = getRandomN<list<int>>(10);	// error

	//getRandomN g(10);
	//list<int> s = g;

	// 3. T Ÿ�������� �Ͻ��� ��ȯ�� ���� ��ȯ �������� ���ø��� �º��� ���ؼ� �Ͻ��� �߷е� �� �ִ�.
	list<int> s = getRandomN(10);

	show(s);
}