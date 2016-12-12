// template template 

// template<typename T> class list {};

template<typename T, template<typename> class C> class stack 
{
	// C c; // error.
	C<T> c;	// OK.
};

//int main()
//{
//	// list      s1;	// Error. list는 템플릿
//	list<int> s2;	// ok.. list<int>는 타입
//
//	stack<int, list > st;
//}

// template template 을 사용한 allocator의 변경
template<typename T> class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }
};

// template<typename T, typename Ax = allocator<T> > class list
template<typename T, template<typename T> class Ax = allocator> class list
{
};

int main()
{
	list<int, allocator> v;
	//v.resize(10);
}

