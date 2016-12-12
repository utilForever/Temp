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

// 1. primary template을 만든다.
template <typename T, typename TL> struct AddFront
{
	typedef TL type;
};

// 2. list가 비어있을 때...
template <typename T> struct AddFront<T, Null>
{
	typedef TypeList<T, Null> type;
};

// 3. list의 갯수가 한 개일 때...
template <typename T1, typename T2> struct AddFront<T1, TypeList<T2, Null>>
{
	typedef TypeList<T1, TypeList<T2, Null>> type;
};

// 4. list의 갯수가 한 개 이상일 때...
template <typename T1, typename T2, typename T3> struct AddFront<T1, TypeList<T2, T3>>
{
	typedef TypeList<T1, TypeList<T2, T3>> type;
};

template <typename T> void foo(const T& A)
{
	typename AddFront<double, T>::type t;

	cout << typeid(t).name() << endl;
	// TypeList<double, TypeList<int, TypeList<int, Null>>>
}

int main()
{
	TypeList<int, Null> t1;
	TypeList<int, TypeList<int, Null>> t2;

	foo(t2);
}