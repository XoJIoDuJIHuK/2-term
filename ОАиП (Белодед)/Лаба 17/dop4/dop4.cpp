#include <iostream>
#include <vector>
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

void main()
{
	int A[11];
	for (int i = 0; i < 11; i++)
	{
		A[i] = rand() % 11 - 5;
	}
	output(A, 11);
	vector <int> list;
	for (int i = 0; i < 11; i++)
	{
		bool dbl = 0;
		for (int j = 0; j < i; j++)
		{
			int a = A[i];
			int b = A[j];
			if (A[j] == A[i])
			{
				dbl = 1;
				break;
			}
		}
		if (!dbl)
		{
			list.push_back(A[i]);
		}
	}
	int* mas = new int[list.size()];
	for (int i = 0; i < list.size(); i++)
	{
		mas[i] = list[i];
	}
	quicksort(mas, list.size());
	output(mas, list.size());
	/*for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << ' ';
	}*/
}