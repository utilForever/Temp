#include <iostream>
#include <type_traits>  
using namespace std;

// C++ 표준위원회는 int2type을 개선한 아래 템플릿을 C++11 표준에 도입.
template<typename T, T N> struct integral_constant
{
static constexpr T value = N;
};

//integral_constant<int, 0> n0;
//integral_constant<int, 1> n1;
//integral_constant<short, 0> s0;
//integral_constant<short, 1> s1;

// true / false           : 참거짓을 나타내는 값, 같은 타입
// true_type / false_type : 참거짓을 나타내는 타입, 다른타입
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> fasle_type;

// C++11 표준의 is_pointer
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};


//--------------------------------------------------
template<typename T> void foo_imp(const T& value, int2type<0>) { cout << "포인터가 아닐때 알고리즘" << endl; }
template<typename T> void foo_imp(const T& value, int2type<1>) { cout << "포인터일때 알고리즘" << endl; }

template<typename T> void foo(const T& value)
{
	foo_imp(value, int2type<is_pointer<T>::value>());
}

int main()
{
	int n = 0;
	foo(&n);
}



