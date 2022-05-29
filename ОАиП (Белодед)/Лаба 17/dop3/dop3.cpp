#include <iostream>
using namespace std;

void output(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl;
}

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

void quicksort_down(int* A, int N)
{
	int i = 0, j = N - 1;
	int point = A[N / 2];
	do
	{
		while (A[i] > point)
		{
			i++;
		}
		while (A[j] < point)
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
		quicksort_down(A, j + 1);
	}
	if (i < N)
	{
		quicksort_down(&A[i], N - i);
	}
}

void main()
{
	int N = 10;
	int* A = new int[N];
	int* first = new int[4];
	int* last  = new int[4];
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % (2 * N + 1) - N;
	}
	output(A, N);
	for (int i = 0; i < 4; i++)
	{
		first[i] = A[i];
		last[i] = A[i + 6];
	}
	quicksort(first, 4);
	quicksort_down(last, 4);
	for (int i = 0; i < 4; i++)
	{
		A[i] = first[i];
		A[i + 6] = last[i];
	}
	output(A, N);
}