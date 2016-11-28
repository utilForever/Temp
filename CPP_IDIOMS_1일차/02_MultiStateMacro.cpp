#include <Windows.h>
#include <stdio.h>


// 02_MultiStateMacro
// if, if-else �� ���� ���ɼ� �ִ� ��ũ��

// �ٽ� : ��ũ�� �Լ��� 2�� �̻����� ������ ���� do { } while(0) ���� ���� ���� ���� ����

void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// �Ʒ�ó�� ����� if () ������ ������ �ִ�.
// #define xyprintf(x, y, ...) gotoxy(x, y); printf(__VA_ARGS__)

// �Ʒ�ó�� ����� if - else ���� ��� �� ������ �ִ�.
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