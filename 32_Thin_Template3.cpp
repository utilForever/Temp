// 32_Thin_Template

// ��� 2. void* ��� �θ� �����̳� + ĳ������ ����ϴ� ���ø� ����

// �Լ� ���� : 

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

// void*�� �ٷ� ����ϸ� �׻� ĳ�����ؾ� �ϴ� ������ �ִ�.
// ĳ���ø� å������ ���ø��� �����Ѵ�.

// thin template�̶�� �Ҹ��� ���! code �޸� ��뷮�� ���̴� ���.
template<typename T> class Vector : public VectorBase
{
	T* buff;
public:
	// void*�� ĳ���ø� �ؼ� �θ� �����ش�.
	void push_back(const T& a) { VectorBase::push_back((void*)a); }
	T& back() { return reinterpret_cast<T>(VectorBase::back()); }
};

int main()
{
	Vector<int> v1;
	Vector<char> v23;
	Vector<short> v3;
}