#include <iostream>
using namespace std;

// 01_�������� ��ũ��

#ifdef _DEBUG
	#define TRACE1(msg, x)  printf(msg, x)
	#define TRACE(...)      printf(__VA_ARGS__)
#else
#define TRACE1(msg, x)  
#define TRACE(...)
#endif

int main()
{
	int x = 10, y = 20;

	TRACE("x = %d\n", x);
	TRACE("x = %d, y = %d\n", x, y);
}

