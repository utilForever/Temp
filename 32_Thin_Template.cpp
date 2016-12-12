// 32_Thin_Template

// 멤버 함수의 갯수는 ? 3개 타입 * 4개 함수 = 12개

template<typename T> class Vector
{
	T* buff;
	int sz;
public:
	
	int  size() const { return sz; }
	bool empty() const { return sz == 0; }

	void push_back( const T& a) { }
	T& back() { return buff[sz - 1]; }
};

int main()
{
	Vector<int> v1;
	Vector<char> v23;
	Vector<short> v3;
}