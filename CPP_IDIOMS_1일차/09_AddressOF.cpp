#include <iostream>
using namespace std;



struct NoAddr
{
	// NoAddr* operator&() const { return 0; }
	// NoAddr* operator&() const;	// link error

	NoAddr* operator&() const = delete;	// Compile error
};


int main()
{
	const NoAddr obj;
	// cout << &obj << endl;	// obj.operator&()
	
	// void* p = &(reinterpret_cast<char&>(obj));	// ok.. 하지만 상수라면 error

	// const volatile void* p = &(reinterpret_cast<const volatile char&>(obj));

	// void* p = &const_cast<char&>((reinterpret_cast<const volatile char&>(obj)));

	// NoAddr* p = reinterpret_cast<NoAddr*>(&const_cast<char&>((reinterpret_cast<const volatile char&>(obj))));

	NoAddr na;
	NoAddr* p = addressof(na);

	cout << p << endl;
}