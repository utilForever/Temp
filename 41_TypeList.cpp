#include <iostream>
using namespace std;

// list의 끝을 나타내기 위해 Null Type을 만들자
struct Null { };

// TypeList : Type을 담은 List
//				값이 아닌 타입을 담음 list
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