#include <iostream>
using namespace std;

// �ٽ� : [] ������ ���� ��ȣ�� ���ʰ� �����ʿ� �ö� �ٸ� ������ �ϱ� ���� Proxy ��ü

class String
{
	char* buff;
	int sz;
public:
	String(const char* s)
	{
		sz = strlen(s);
		buff = new char[sz + 1];
		strcpy(buff, s);
	}

	char& operator[](int idx)
	{
		cout << "[]" << endl;
		return buff[idx];
	}
};
int main()
{
	String s = "hello";

	char c = s[0]; // []�� �����ʿ� ������
	s[0] = 'x';
}