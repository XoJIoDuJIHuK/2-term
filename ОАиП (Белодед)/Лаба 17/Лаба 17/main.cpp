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

void mergeSort(int* a, int l, int r)
{
	if (l == r) return; // границы сомкнулись
	int mid = (l + r) / 2; // определяем середину последовательности
	// и рекурсивно вызываем функцию сортировки для каждой половины
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	int i = l;  // начало первого пути
	int j = mid + 1; // начало второго пути
	int* tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
	for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
	{
		// записываем в формируемую последовательность меньший из элементов двух путей
		// или остаток первого пути если j > r
		if ((j > r) || ((i <= mid) && (a[i] < a[j])))
		{
			tmp[step] = a[i];
			i++;
		}
		else
		{
			tmp[step] = a[j];
			j++;
		}
	}
	// переписываем сформированную последовательность в исходный массив
	for (int step = 0; step < r - l + 1; step++)
		a[l + step] = tmp[step];
}

int* podschet(int* A, int N)
{
	int* out = new int[N];
	int i, j, count;
	for (i = 0; i < N; ++i)
	{
		for (count = 0, j = 0; j < N; ++j)
			if (A[j] < A[i] || (A[j] == A[i] && i < j))
				count++;
		out[count] = A[i];
	}
	return out;
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
	int* B = new int[N];
	int* C = new int[N];
	for (int i = 0; i < N; i++)
	{
		B[i] = C[i] = A[i] = rand() % (2 * N + 1) - N;
	}
	int start = clock();
	int* AA = podschet(A, N);
	int end = clock();
	int time[3];
	time[0] = end - start;
	start = clock();
	vybor(B, N);
	end = clock();
	time[1] = end - start;
	start = clock();
	mergeSort(C, 0, N - 1);
	end = clock();
	time[2] = end - start;
	output(AA, N);
	cout << time[0] << endl;//podschet
	output(B, N);
	cout << time[1] << endl;//vybor
	output(C, N);
	cout << time[2];//merge
}