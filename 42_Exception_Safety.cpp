// 42_Exception_Safety

template<typename T> class Stack
{
	T buff[10];
	int idx = 0;
public:
	void push(const T& a) { buff[idx++] = a; }

	T pop()
	{
		--idx;
		if (idx < 0)
			throw 1;
		return buff[idx];
	}
};

int main()
{
	Stack<int> s;

	try
	{
		s.pop();
	}
	catch (...) {}

	// s를 계속 사용할수 있을까 ?
}


// 예외 안정성(Exception Safety)
// 완전 보장 : 예외가 없다. int a = 0
// 강력 보장 : 예외를 잡으면 객체는 예외 발생 이전상태를 보장한다. 객체 사용가능
// 기본 보장 : 예외를 잡으면 메모리등의 자원 누수는 없다. 하지만 객체의 상태는 알수 없다. 객체 사용불가

