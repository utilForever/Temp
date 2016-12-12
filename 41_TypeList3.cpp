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

//---------------------------------------------------------------
template<typename T> struct Holder {};

template<typename T1, typename T2> 
struct Holder<TypeList<T1, T2>> : Holder<T2>
{									// Holder<TypeList<int, TypeList<int, Null>>>
	T1 value;
};

template<typename T1>
struct Holder<TypeList<T1, Null>>
{
	T1 value;
};

int main()
{
	Holder<TLIST3(int, int, int)> h3; // TypeList<int, TypeList<int, TypeList<int, Null>>>
}

//int main()
//{
//	// TypeList 덕분에 인자가 한 개인 템플릿에..
//	// 여러 개의 타입을 보낼 수 있다.
//	Holder<int, int> h2;	// error
//	Holder<TLIST2(int, int)> h2;	// ok..
//
//	Holder<TLIST3(int, int, int)> h3; // TypeList<int, TypeList<int, TypeList<int, Null>>>
//}









