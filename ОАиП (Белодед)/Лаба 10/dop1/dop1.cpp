#include <iostream>
#include <fstream>
using namespace std;

void Print(int* a, int n)
{
	ofstream file;
	file.open("h.txt", ios::app);
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	file.width(3);
	file << num << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		file << a[i] << " ";
	}
	cout << endl;
	file << endl;
}

bool NextDigit(int* a, int n, int m)
{
	int j = m - 1;
	while (a[j] == n && j >= 0)
	{
		j--;
	}
	if (j < 0) return false;
	if (a[j] >= n) j--;
	a[j]++;
	if (j == m - 1)
	{
		Print(a, n);
		NextDigit(a, n, n);
	}
	for (int k = j + 1; k < m; k++)
	{
		a[k] = a[j];
	}
	Print(a, n);
	NextDigit(a, n, n);
}

void main()
{
	int n;
	cout << "A = ";
	cin >> n;
	int *a = new int[n];
	a[0] = 1;
	for (int i = 1; i < n; i++)
	{
		a[i] = 0;
	}
	Print(a, n);
	while (NextDigit(a, n, n))
	{
		Print(a, n);
	}
}