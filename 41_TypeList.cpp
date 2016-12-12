#include <iostream>
using namespace std;

// list�� ���� ��Ÿ���� ���� Null Type�� ������
struct Null { };

// TypeList : Type�� ���� List
//				���� �ƴ� Ÿ���� ���� list
template<typename T, typename U> struct TypeList
{
	typedef T type1;
	typedef U type2;
};


int main()
{
	TypeList<int, Null> t1;
	TypeList<int, TypeList<int, Null>> t2;
}