#include <iostream>
using namespace std;

// Template ���ڷ� ���Ǵ� Null

template<typename T, typename U> struct TypeList
{
	typedef T type1;
	typedef U type2;
};

template<typename T> struct Count
{
};


int main()
{
	TypeList<int, int> t2;
	TypeList<int, TypeList<int, int>> t3;
}