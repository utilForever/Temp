// 32_Thin_Template

// 방법 1. Template인자 T 에 의존적이지 않은 멤버 함수는 부모 클래스로 제공한다.

// 함수 갯수 : 2개 함수 * 3개 타입 + 부모 2개 => 8개

class VectorBase
{
	int sz;
public:
	int  size() const { return sz; }
	bool empty() const { return sz == 0; }
};

template<typename T> class Vector : public VectorBase
{
	T* buff;
public:
	void push_back(const T& a) { }
	T& back() { return buff[sz - 1]; }
};

int main()
{
	Vector<int> v1;
	Vector<char> v23;
	Vector<short> v3;
}