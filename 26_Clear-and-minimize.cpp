#include <iostream>
#include <vector>
using namespace std;

// Clear-and-minimize : vector���� �����̳��� capacity�� ���̴� ���
// "swap with temporary" ��� �Ҹ��� ���

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

	// v1�� capacity�� ���̴� ���
	vector<int>(v1).swap(v1);

	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	// C++11 : shrink_to_fit()
	v1.shrink_to_fit();

}


