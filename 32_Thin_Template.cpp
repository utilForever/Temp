// 32_Thin_Template

// ��� �Լ��� ������ ? 3�� Ÿ�� * 4�� �Լ� = 12��

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