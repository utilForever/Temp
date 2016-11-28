#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = v.begin();

	advance(p, 5);

	cout << *p << endl; // 6
}