#include <Windows.h>
#include <stdio.h>


// 02_MultiStateMacro
// if, if-else 와 같이 사용될수 있는 매크로

// 핵심 : 매크로 함수를 2줄이상으로 구현할때는 do { } while(0) 으로 묶는것이 
//        가장 안전합니다.


void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 아래 처럼 만들면 if () 문에서 문제 가 있습니ㅏㄷ.
//#define xyprintf( x, y, ... )   gotoxy(x, y); printf( __VA_ARGS__)

// 아래 처럼 하면 if - else 구문사용시 에러가 있습니다.
//#define xyprintf( x, y, ... )  { gotoxy(x, y); printf( __VA_ARGS__); }

#define xyprintf( x, y, ... )  do { gotoxy(x, y); printf( __VA_ARGS__); }while(0)

int main()
{
	if (0)
		//xyprintf(10, 10, "hello");
		do 
		{ 
			gotoxy(x, y); 
			printf(__VA_ARGS__); 
		} while (0);
	else


	//------------------------------
	if (0)
		xyprintf(10, 10, "hello");
	else
	{
	}


	//---------------

	if (0)
		xyprintf(10, 10, "hello");


	//------------------------------
//	gotoxy(10, 10); 
//	printf("A");
//	xyprintf(10, 10, "hello %s", "world");
}












