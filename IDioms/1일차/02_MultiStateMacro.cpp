#include <Windows.h>
#include <stdio.h>


// 02_MultiStateMacro
// if, if-else �� ���� ���ɼ� �ִ� ��ũ��

// �ٽ� : ��ũ�� �Լ��� 2���̻����� �����Ҷ��� do { } while(0) ���� ���°��� 
//        ���� �����մϴ�.


void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// �Ʒ� ó�� ����� if () ������ ���� �� �ֽ��Ϥ���.
//#define xyprintf( x, y, ... )   gotoxy(x, y); printf( __VA_ARGS__)

// �Ʒ� ó�� �ϸ� if - else �������� ������ �ֽ��ϴ�.
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












