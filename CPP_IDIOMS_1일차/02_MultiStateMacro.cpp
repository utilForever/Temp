#include <Windows.h>
#include <stdio.h>


// 02_MultiStateMacro
// if, if-else 와 같이 사용될수 있는 매크로

// 핵심 : 매크로 함수를 2줄 이상으로 구현할 때는 do { } while(0) 으로 묶는 것이 가장 안전

void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 아래처럼 만들면 if () 문에서 문제가 있다.
// #define xyprintf(x, y, ...) gotoxy(x, y); printf(__VA_ARGS__)

// 아래처럼 만들면 if - else 구문 사용 시 문제가 있다.
// #define xyprintf(x, y, ...) { gotoxy(x, y); printf(__VA_ARGS__); }

#define xyprintf(x, y, ...) do { gotoxy(x, y); printf(__VA_ARGS__); } while (0)

int main()
{
//	gotoxy(10, 10); 
//	printf("A");

//	xyprintf(10, 10, "Hello %s", "World");
	
//	if (0)
//		xyprintf(10, 10, "Hello");

	if (0)
		xyprintf(10, 10, "Hello");
	else
	{

	}
}