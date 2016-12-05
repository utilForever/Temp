// ��ü�� ���� ����� ���� �ϰų�, �ݵ�� ���� ����� �ϴ� ���

class OnlyHeap
{
public:
	void Delete() { delete this; }
protected:
	// protected �Ҹ��� : stack�� ��ü�� ���� �� ���� �Ѵ�.
	~OnlyHeap() { }
};

class NoHeap
{
public:
	// new �Լ��� �����Ѵ�. (C++11 delete function)
	static void* operator new(size_t sz)
	{
		// static_assert(0, "NoHeap caanot make object in heap.");
		return 0;
	}
	static void operator delete(void*) = delete;
};
int main()
{
	// OnlyHeap oh; // error
	OnlyHeap* p = new OnlyHeap;

	p->Delete();
	// delete p;

	// NoHeap* p = new NoHeap; // error
}