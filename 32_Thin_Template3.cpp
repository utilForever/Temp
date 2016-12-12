// 32_Thin_Template

// 방법 2. void* 기반 부모 컨테이너 + 캐스팅을 담당하는 템플릿 제공

// 함수 갯수 : 

class VectorBase
{
	int sz;
	void* buff;
public:
	int  size() const { return sz; }
	bool empty() const { return sz == 0; }
	void push_back(void* a) { }
	void* back() { return buff[sz - 1]; }
};

// void*를 바로 사용하면 항상 캐스팅해야 하는 문제가 있다.
// 캐스팅만 책임지는 템플릿을 제공한다.

// thin template이라고 불리는 기술! code 메모리 사용량을 줄이는 기술.
template<typename T> class Vector : public VectorBase
{
	T* buff;
public:
	// void*로 캐스팅만 해서 부모에 보내준다.
	void push_back(const T& a) { VectorBase::push_back((void*)a); }
	T& back() { return reinterpret_cast<T>(VectorBase::back()); }
};

int main()
{
	Vector<int> v1;
	Vector<char> v23;
	Vector<short> v3;
}