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

void puzyrok_down(int* A, int N)
{
	for (int i = 0; i < N; i++)
	{
		bool swap_count = false;
		for (int j = 0; j < N; j++)
		{
			if ((A[j] < A[j + 1]) and (j < N - 1))
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

void shell_down(int* A, int N)
{
	for (int s = N / 2; s > 0; s /= 2)
	{
		for (int i = s; i < N; ++i)
		{
			for (int j = i - s; j >= 0 and A[j] < A[j + s]; j -= s)
			{
				int buffer = A[j];
				A[j] = A[j + s];
				A[j + s] = buffer;
			}
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
	cout << "enter N: ";
	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* C_l = new int[2 * N];
	for (int i = 0; i < N; i++) C[i] = 0;
	for (int i = 0; i < 2 * N; i++) C_l[i] = 0;
	if (!A || !B || !C)
	{
		cout << "malloc error\n";
		exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % (2 * N + 1) - N;
		B[i] = rand() % (2 * N + 1) - N;
	}
	output(A, N);
	output(B, N);
	system("pause");
	int var = 15;
	while (var)
	{
		system("cls");
		cout << "variant: ";
		cin >> var;
		switch (var)
		{
			case 15:
			{
				quicksort(A, N);
				quicksort(B, N);
				for (int i = 0; i < N; i++)
				{
					if (A[i] < B[N - 1]) C[i] = A[i];
					else break;
				}
				cout << "enter 1 or 0: ";
				bool first = 0;
				cin >> first;
				first ? quicksort_down(C, N) : puzyrok_down(C, N);
				output(C, N);
				break;
			}
			case 14:
			{
				for (int i = 0; i < N; i += 2)	C[i] = A[i];
				for (int i = 1; i < N; i += 2)	C[i] = B[i];
				cout << "enter 1 or 0: ";
				bool first = 0;
				cin >> first;
				first ? shell_down(C, N) : puzyrok_down(C, N);
				output(C, N);
				break;
			}
			case 11:
			{
				int j = 0;
				for (int i = 0; i < N && j < 2 * N; i++)
				{
					if (A[i] % 2) C_l[j++] = A[i];
					if (!(B[i] % 2)) C_l[j++] = B[i];
				}
				cout << "enter 1 or 0: ";
				bool first = 0;
				cin >> first;
				first ? shell(C_l, N * 2) : quicksort(C_l, N * 2);
				output(C_l, N * 2);
				break;
			}
			case 8:
			{
				int j = 0;
				for (int i = 0; i < N && j < 2 * N; i++)
				{
					if (A[i] % 2) C_l[j++] = A[i];
					if (B[i] % 2) C_l[j++] = B[i];
				}
				cout << "enter 1 or 0: ";
				bool first = 0;
				cin >> first;
				first ? vybor(C_l, N * 2) : shell(C_l, N * 2);
				output(C_l, N * 2);
				break;
			}
		}
		system("pause");
	}
}