#include <iostream>
#include <vector>
using namespace std;

// Clear-and-minimize : vector등의 컨테이너의 capacity를 줄이는 기술
// "swap with temporary" 라고도 불리는 기술

int main()
{
	vector<int> v1(10);

	v1.resize(7);

	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	//------------------------
	vector<int> v2 = v1;

	//cout << v2.size() << endl;
	//cout << v2.capacity() << endl;

	// v1의 capacity를 줄이는 기술
	vector<int>(v1).swap(v1);

	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	// C++11 : shrink_to_fit()
	v1.shrink_to_fit();

}


