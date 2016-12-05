#include <iostream>
using namespace std;

// nullptr ¸¸µé±â.

void foo(int n) { cout << "int" << endl; }
// void foo(void*) { cout << "*" << endl; }
void foo(char*) { cout << "*" << endl; }

int main()
{
	foo(0);	// int

	foo((void*)0);	// *

#define NULL (void*)0
	foo(NULL)
}