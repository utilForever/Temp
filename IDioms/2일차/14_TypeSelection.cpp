// enable_if<���ǹ�, Ÿ��>::type => ���̸� "Ÿ��" �����̸� ����
// IF<���ǹ�, Ÿ��1, Ÿ��2>::type => ���̸� "Ÿ��1" �����̸� "Ÿ��2"

// bool test�� ���� TypeSelection ���

// IF, IfThenElse, Select ��� �̸����� �˷��� �ִ� ���

// bool ������� Ÿ���� �����ϴ� ��Ÿ �Լ�
template<bool, typename T, typename U> struct IF
{
	typedef T type;
};

template<typename T, typename U> struct IF<false, T, U>
{
	typedef U type;
};

//IF<true, char, int>::type => char Ÿ��...
//IF<false, char, int>::type => int Ÿ��...

template <class T, unsigned int N>
class Queue
{
	T array[N];

	// ũ�⿡ ���� size_type�� ���� (����ȭ)
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