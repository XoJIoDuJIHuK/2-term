#include <iostream>
#include <ctime>
using namespace std;

unsigned long int Fib(int i)
{
	unsigned long int f1 = 0;
	unsigned long int f2 = 1;
	unsigned long int fn;
	if (i < 1) { return 0; }
	if (i == 1) { cout << "0 1\n"; }
	if (i > 1)
	{
		for (int j = 1; j < i; j++)
		{
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
	}
	cout << "\n\n";
	return fn;
}

void main()
{
	int i, n, end_time, start_time;
	cout << "Enter: ";
	cin >> i;
	start_time = clock();
	n = Fib(i);
	end_time = clock();
	cout << "\n" << "Time " << end_time << "-" << start_time << " ms\n";
	std::cout << "Chislo F = " << n << "\t";
}