#include <iostream>
using namespace std;

// 1 ~ 4 바이트 사이의 타입 => 4바이트로
// 5 ~ 8 바이트            => 8바이트로 계산해주는 기술.
//#define _INTSIZEOF(n)  (( sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1 ))
/*
int main()
{
	printf("%d\n", _INTSIZEOF(char));
	printf("%d\n", _INTSIZEOF(short));
	printf("%d\n", _INTSIZEOF(int));
	printf("%d\n", _INTSIZEOF(double));
}
*/



typedef char *va_list;

#define va_start(ap, v)   (ap = (va_list)&v + _INTSIZEOF(v) )
#define va_arg( ap, t)   (  *(t*)( ( ap += _INTSIZEOF(t)) - _INTSIZEOF(t) ) )
#define va_end(ap)       (ap = (va_list)0 )

int sum(int count, ...)
{
	va_list	ap;
	va_start(ap, count);

	int sum = 0;
	int i = 0;
	for (i = 0; i < count; i++)
		sum += va_arg(ap, short);

	va_end(ap);
	return sum;
}
int main()
{
	int n = sum(5, 1, 2, 3, 4, 5);

	printf("sum = %d\n", n); // 15
}

