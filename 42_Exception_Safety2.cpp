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

	// pop이 제거와 리턴을 동시에 하면 강력 보장을 지원할 수 없다.
	// 제거와 리턴은 분리되어야 한다.
	void pop() { --idx; } // 제거만...
	T& top() { return buff[idx]; } // 리턴만...
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

		//People p2 = s.pop();	// 1. s.pop 호출... -> 성공
		//						// 2. 복사 생성자를 사용해서 p2에 복사 - 여기서 예외가 나오면...
	}
	catch (...) {}
}


