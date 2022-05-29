#include <iostream>
using namespace std;

int S(int x)
{
	if (x > 100)
	{
		return x + 10;
	}
	else
	{
		return S(S(x+4));
	}
}

void main()
{
	cout << "enter x: ";
	int x;
	cin >> x;
	cout << S(x) << endl;
}