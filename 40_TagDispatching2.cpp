#include <iostream>
#include <vector>
#include <list>
using namespace std;


// 반복자의 종류를 나타내는 empty class 설계
//struct input_iterator_tag {};
//struct out_iterator_tag {};
//struct forward_iterator_tag : input_iterator_tag {};
//struct bidirectional_iterator_tag : forward_iterator_tag {};
//struct random_access_iterator_tag : bidirectional_iterator_tag {};
//
//// 반복자를 만들때 자신이 어떤 타입인지를 알려준다.
//template<typename T> class vector_iterator
//{
//public:
//	typedef random_access_iterator_tag iterator_category;
//	//......
//};
//
//template<typename T> class list_iterator
//{
//public:
//	typedef bidirectional_iterator_tag iterator_category;
//	//......
//};

template<typename T> void xadvance_imp(T& p, int n, input_iterator_tag)
{
	while (n--) ++p;
}

template<typename T> void xadvance_imp(T& p, int n, random_access_iterator_tag)
{
	p = p + n;
}


template<typename T> void xadvance(T& p, int n)
{
	xadvance_imp(p, n, typename T::iterator_category);
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = v.begin();
	xadvance(p, 5);
	cout << *p << endl; // 6


	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p2 = s.begin();

	xadvance(p2, 5); // ?
}