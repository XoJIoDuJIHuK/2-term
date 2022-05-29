#include <iostream>
using namespace std;

int P(int m, int n)
{
	if (m == 1 or n == 1)
	{
		return 1;
	}
	else if (n > m)
	{
		return P(m, m);
	}
	else if (m == n)
	{
		return P(m, m - 1) + 1;
	}
	else if (n < m)
	{
		return P(m, n - 1) + P(m - n, n);
	}
}

void main()
{
	cout << "enter m: ";
	int m, n;
	cin >> m;
	n = m;
	cout << P(m, n) << endl;
}