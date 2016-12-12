#include <iostream>
using namespace std;

// 핵심 : [] 연산자 사용시 등호의 왼쪽과 오른쪽에 올때 다른 동작을 하기 위한 Proxy 객체


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

		// [] 연산자가 좌변에 올때
		Proxy& operator=(char c)
		{
			cout << "lock" << endl;
			cout << "[]" << endl;
			str.buff[index] = 'a';
			cout << "unlock" << endl;
			return *this;
		}
		// [] 연산자가 우변에 올때
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

	char c = s[0]; // []가 오른쪽에 있을때
	s[0] = 'x';
}