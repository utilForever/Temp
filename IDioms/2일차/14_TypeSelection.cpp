// enable_if<조건문, 타입>::type => 참이면 "타입" 거짓이면 실패
// IF<조건문, 타입1, 타입2>::type => 참이면 "타입1" 거짓이면 "타입2"

// bool test를 통한 TypeSelection 기술

// IF, IfThenElse, Select 라는 이름으로 알려져 있는 기술

// bool 기반으로 타입을 결정하는 메타 함수
template<bool, typename T, typename U> struct IF
{
	typedef T type;
};

template<typename T, typename U> struct IF<false, T, U>
{
	typedef U type;
};

//IF<true, char, int>::type => char 타입...
//IF<false, char, int>::type => int 타입...

template <class T, unsigned int N>
class Queue
{
	T array[N];

	// 크기에 따라 size_type을 결정 (최적화)
	// typedef unsigned int size_type;
	// typedef if (N < 256) char size_type;

	// typedef typename IF<(N < 255), char, int>::type size_type;
	typedef typename IF<(N < 255), char, IF<(N < 65535), short, int>>::type size_type;

	size_type size() const { return N; }
};

int main()
{
	Queue<int, 32> q;
}