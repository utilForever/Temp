#include <iostream>
using namespace std;

// 1. #pragma message : �����Ͻÿ� �޼����� ����Ҽ� �ִ�.
// 2. __LINE__ �� ���ڿ��� �����ϴ� ���.
#define TOSTRIMP(x)   #x
#define TOSTR(x)    TOSTRIMP(x)
#define LOG(desc)   message ( __FILE__ "(" TOSTR(__LINE__) ") : " desc)

int main()
{
#pragma message("�� �ڵ�� �˰����� �����ؾ� �մϴ�.");
#pragma LOG("AAAAA");
}

// ��ũ�� ����� �ٽ� #�� ����ؼ� ���ڿ��� ������ ���� 2���� ��ũ�� ������ ��ġ�� �ؾ��Ѵ�.
/*
#define MAX 100
#define TOSTRING(x) #x
#define TOSTRING2(x) TOSTRING(x)

int main()
{
	int x = 10;
	cout << x << endl;				// x
	cout << TOSTRING(x) << endl;	// "x"
	cout << TOSTRING(MAX) << endl;	// MAX
	cout << TOSTRING2(MAX) << endl;	// 100

	cout << TOSTRING(__LINE__) << endl;		// __LINE__
	cout << TOSTRING2(__LINE__) << endl;	// 23
}
*/








