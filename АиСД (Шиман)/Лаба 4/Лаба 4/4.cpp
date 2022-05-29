#include <iostream>
using namespace std;

void quicksort(int* A, int N)
{
	int i = 0, j = N - 1;
	int point = A[N / 2];
	do
	{
		while (A[i] < point)
		{
			i++;
		}
		while (A[j] > point)
		{
			j--;
		}
		if (i <= j)
		{
			int buffer = A[i];
			A[i] = A[j];
			A[j] = buffer;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		quicksort(A, j + 1);
	}
	if (i < N)
	{
		quicksort(&A[i], N - i);
	}
}

int sum_arr(int* arr, int n)
{
	int i = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

void func1()
{
	cout << "Enter N: ";
	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 10 + 1;
		/*cout << A[i] << ' ';*/
	}
	cout << endl;
	quicksort(A, N);
	int* low = new int[N / 2];
	int* high = new int[N - (N / 2)];
	for (int i = 0; i < N / 2; i++)
	{
		low[i] = A[i];
		/*cout << low[i] << ' ';*/
	}
	cout << endl;
	for (int i = 0; i < N - (N / 2); i++)
	{
		high[i] = A[i + (N / 2)];
		/*cout << high[i] << ' ';*/
	}
	cout << endl;
	for (int i = 0, j = 0, k = 0; i < (int)((float)N / 2); i++)
	{
		if (high[i])
		{
			cout << high[i] << ' ';
		}
		if (low[i])
		{
			cout << low[i] << ' ';
		}
	}
	cout << endl << sum_arr(high, N - (N / 2)) << " - max sum" << endl;
}

void func2()
{
	cout << "Enter N: ";
	int N, first = 95, second = 85, third = 70;
	int sum[3] = { 0, 0, 0 };
	int amount = 0;
	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 100 + 1;
	}
	cout << endl;
	quicksort(A, N);
	/*{for (int i = 0; i < N; i++)
	{
		if (first <= A[i])
		{
			sum[0]++;
			continue;
		}
		if (second <= A[i] < first)
		{
			sum[1]++;
			continue;
		}
		if (third <= A[i] < second)
		{
			sum[2]++;
			continue;
		}
	}
	
	amount = sum[0] + sum[1] + sum[2];
	}*/
	for (int i = 0; i < N; i++)
	{
		if (A[i] >= 70) amount++;
		cout << A[i] << ' ';
	}
	cout << endl << amount << endl;
}

void main()
{
	/*func1();*/
	cout << "------------------------------------------" << endl;
	func2();
}