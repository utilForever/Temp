#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using namespace std::placeholders;

void foo(int a, int& b) { cout << "foo" << endl; b = 100; }

// 완벽한 전달자와 reference wrapper 
class Test
{
public:
	Test(int a, int& b) { cout << "Test()" << endl; b = 100; }
};

int main()
{
	int n1 = 10;
	vector<Test> v;
	
	//Test t(10, n1);
	//v.push_back(t);

	// C++11의 특징 : 외부에서 개체를 만들지 않고 vector가 내부적으로 만들게 하자.
	// 대신, 생성자에서 사용할 인자를 전달해야 한다.
	v.emplace_back(10, n1);	// 이 함수가 내부적으로 Test를 생성한다.
	
	cout << n1 << endl;
}

