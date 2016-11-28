#include <iostream>
using namespace std;

// flexible array

struct People
{
	// char name[16];	// 16자로 길이 제한
	// char* name;	// 동적 메모리 할당 사용
					// People 생성 후 다시 자원 할당.
	int  age;
	char name[0];	// 구조체 마지막 멤버로 크기가 0인 배열 가능.
};

int main()
{
	cout << sizeof(People) << endl;

	// People 생성 시 : 구조체 + 필요한 이름 갯수 만큼 메모리 할당
	People* p = (People*)malloc(sizeof(People) + sizeof(char) * 32);
	strcpy(p->name, "Hello");
}