#include <iostream>
using namespace std;

struct Null {};

// Template 인자로 사용되는 Null

template<typename T, typename U> struct TypeList
{
	typedef T type1;
	typedef U type2;
};
#define TLIST1(T1)          TypeList<T1, Null>
#define TLIST2(T1, T2)      TypeList<T1, TypeList<T2, Null>>
#define TLIST3(T1, T2, T3)  TypeList<T1, TypeList<T2, TypeList<T3, Null>>>




template<typename T> struct Count
{
};

template<> struct Count<Null>
{
	enum { value = 0 };
};

template<typename T> struct Count<TypeList<T, Null>>
{
	enum { value = 1 };
};

// 3개 이상의 타입을 가질 때
template<typename T1, typename T2> struct Count<TypeList<T1, TypeList<T2, Null>>>
{
	enum { value = Count<TypeList<T2, Null>>::value + 1 };
};

template<typename T1, typename T2, typename T3> struct Count<TypeList<T1, TypeList<T2, T3>>>
{
	enum { value = Count<TypeList<T2, T3>>::value + 1 };
};

template<typename T> void print_count(T a)
{
	cout << Count<T>::value << endl;
}

int main()
{
	TLIST1(int) t1;
	TLIST2(int, double) t2;
}