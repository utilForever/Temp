#include <iostream>
using namespace std;

struct Null {};

template<typename T, typename U> struct TypeList
{
	typedef T type1;
	typedef U type2;
};

#define TLIST1(T1)          TypeList<T1, Null>
#define TLIST2(T1, T2)      TypeList<T1, TypeList<T2, Null>>
#define TLIST3(T1, T2, T3)  TypeList<T1, TypeList<T2, TypeList<T3, Null>>>

int main()
{
	TypeList<int, Null> t1;
	TypeList<int, TypeList<int, Null>> t2;

	TLIST2(int, double);	// 2개를 갖는 list
}
