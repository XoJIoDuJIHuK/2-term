#include <iostream>
#include <ctime>	
using namespace std;

void output(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl;
}

void copy(int* A, int* B, int N)
{
	for (int i = 0; i < N; i++)
	{
		B[i] = A[i];
	}
}

void puzyrok(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		bool swap_count = false;
		for (int j = 0; j < N; j++)
		{
			if ((A[j] > A[j + 1]) and (j < N - 1))
			{
				int buffer = A[j];
				A[j] = A[j + 1];
				A[j + 1] = buffer;
				swap_count = true;
			}
		}
		if (!swap_count)
		{
			return;
		}
	}
}

void shell(int* A, int N)
{
	for (int s = N / 2; s > 0; s /= 2)
	{
		for (int i = s; i < N; ++i)
		{
			for (int j = i - s; j >= 0 and A[j] > A[j + s]; j -= s)
			{
				int buffer = A[j];
				A[j] = A[j + s];
				A[j + s] = buffer;
			}
		}
	}
}

void vybor(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		int min_value = 2147483647, i_pos = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < min_value)
			{
				min_value = A[j];
				i_pos = j;
			}
		}
		if (i_pos > i)
		{
			int buffer = A[i];
			A[i] = A[i_pos];
			A[i_pos] = buffer;
		}
	}
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
	cout << "Enter N: ";
	int N, start_time, end_time;
	cin >> N;
	int* A = (int*)malloc(4 * N);
	if (A == NULL)
	{
		exit(1);
	}
	/*int* B = (int*)malloc(4 * N);
	int* C = (int*)malloc(4 * N);
	int* D = (int*)malloc(4 * N);*/
	int* E = (int*)malloc(4 * N);
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % (2 * N + 1) - N;
	}
	/*cout << "A: ";
	output(A, N);*/

	/*copy(A, B, N);
	start_time = clock();
	puzyrok(B, N);
	end_time = clock();
	cout << "B: ";
	output(B, N);
	int puzyrok_time = end_time - start_time;
	cout << "time: " << puzyrok_time << endl;

	copy(A, C, N);
	start_time = clock();
	shell(C, N);
	end_time = clock();
	cout << "C: ";
	output(C, N);
	int shell_time = end_time - start_time;
	cout << "time: " << shell_time << endl;

	copy(A, D, N);
	start_time = clock();
	vybor(D, N);
	end_time = clock();
	cout << "D: ";
	output(D, N);
	int vybor_time = end_time - start_time;
	cout << "time: " << vybor_time << endl;*/

	copy(A, E, N);
	start_time = clock();
	quicksort(E, N);
	end_time = clock();
	/*cout << "E: ";
	output(E, N);*/
	int quicksort_time = end_time - start_time;
	cout << "time: " << quicksort_time << endl;

	/*cout << "1. " << puzyrok_time << endl;
	cout << "2. " << shell_time << endl;
	cout << "3. " << vybor_time << endl;*/
	cout << "4. " << quicksort_time << endl;;
}