#include <iostream>
#include <ctime>
using namespace std;

struct nums
{
	bool used = 0;
	int key = 0;
};

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
	cout << "enter N: ";
	int N;
	cin >> N;
	int* A = new int[N];
	nums* mas = new nums[N];
	for (int i = 0; i < N; i++) mas[i].key = i;
	for (int i = 0; i < N; i++)
	{
		int num = rand() % N;
		if (!mas[num].used)
		{
			A[i] = num;
			mas[num].used = 1;
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				if (!mas[j].used)
				{
					A[i] = j;
					mas[j].used = 1;
					break;
				}
			}
		}
	}
	output(A, N);
	int i_max = 0, i_min = 0, max = 0, min = 7654321;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			i_max = i;
		}
		if (A[i] < min)
		{
			min = A[i];
			i_min = i;
		}
	}
	cout << "max element: " << A[i_max] << " i_max: " << i_max << endl;
	cout << "min element: " << A[i_min] << " i_min: " << i_min << endl;
}