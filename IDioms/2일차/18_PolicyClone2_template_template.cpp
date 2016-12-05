// template template 

template<typename T> class list {};

template<typename T, template<typename> class C> class stack 
{
};

int main()
{
	list      s1;
	list<int> s2;

	stack<int, ? > st;
}

// template template 을 사용한 allocator의 변경
template<typename T> class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }
};

template<typename T, typename Ax = allocator<T> > class list
{
}

int main()
{
	list<int, allocator<int> > v;
	v.resize(10);
}

