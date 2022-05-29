#include <iostream>
using namespace std;

void main()
{
	int n;
	cout << "enter number: ";
	cin >> n;
	auto func = [n] { return n > 0; };
	cout << func();
}