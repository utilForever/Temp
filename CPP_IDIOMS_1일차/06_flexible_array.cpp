#include <iostream>
using namespace std;

// flexible array

struct People
{
	// char name[16];	// 16�ڷ� ���� ����
	// char* name;	// ���� �޸� �Ҵ� ���
					// People ���� �� �ٽ� �ڿ� �Ҵ�.
	int  age;
	char name[0];	// ����ü ������ ����� ũ�Ⱑ 0�� �迭 ����.
};

int main()
{
	cout << sizeof(People) << endl;

	// People ���� �� : ����ü + �ʿ��� �̸� ���� ��ŭ �޸� �Ҵ�
	People* p = (People*)malloc(sizeof(People) + sizeof(char) * 32);
	strcpy(p->name, "Hello");
}