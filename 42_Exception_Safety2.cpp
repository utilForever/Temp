// 42_Exception_Safety

class People {};

template<typename T> class Stack
{
	T buff[10];
	int idx = 0;
public:
	void push(const T& a) { buff[idx++] = a; }

	//T pop()
	//{
	//	if (idx < 1)
	//		throw 1;
	//	--idx;
	//	return buff[idx];
	//}

	// pop�� ���ſ� ������ ���ÿ� �ϸ� ���� ������ ������ �� ����.
	// ���ſ� ������ �и��Ǿ�� �Ѵ�.
	void pop() { --idx; } // ���Ÿ�...
	T& top() { return buff[idx]; } // ���ϸ�...
};

int main()
{
	Stack<People> s;

	People p;
	s.push(p);
	try
	{
		People p2 = s.top();
		s.pop();

		//People p2 = s.pop();	// 1. s.pop ȣ��... -> ����
		//						// 2. ���� �����ڸ� ����ؼ� p2�� ���� - ���⼭ ���ܰ� ������...
	}
	catch (...) {}
}


