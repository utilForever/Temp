// 32_Thin_Template

// ��� 1. Template���� T �� ���������� ���� ��� �Լ��� �θ� Ŭ������ �����Ѵ�.

// �Լ� ���� : 2�� �Լ� * 3�� Ÿ�� + �θ� 2�� => 8��

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