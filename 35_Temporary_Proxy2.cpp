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

	class Proxy
	{
		String& str;
		int     index;
	public:
		Proxy(String& s, int idx) : str(s), index(idx) {}

		// [] �����ڰ� �º��� �ö�
		Proxy& operator=(char c)
		{
			cout << "lock" << endl;
			cout << "[]" << endl;
			str.buff[index] = 'a';
			cout << "unlock" << endl;
			return *this;
		}
		// [] �����ڰ� �캯�� �ö�
		operator char()
		{
			cout << "[]" << endl;
			return str.buff[index];
		}
	};

	char& operator[](int idx)
	{
		return buff[idx];
	}
};
int main()
{
	String s = "hello";

	char c = s[0]; // []�� �����ʿ� ������
	s[0] = 'x';
}