#include <iostream>
using namespace std;

//int sum(int n, ...)
//{
//	int result = 0;
//	for (int* ptr = &n; n > 0; n--)
//	{
//		result += *(++ptr);
//	}
//	return result;
//}

int mat_sum_count(int* mas, int a)
{
	int sum = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (j < i)
			{
				sum += *(mas + a * i + j);
			}
		}
	}
	return sum;
}

void fill_mas(int* mas, int a)
{
	int k = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			*(mas + a * i + j) = k;
			k++;
		}
		k++;
	}
}

void main()
{
	int mas1[4];
	int mas2[9];
	int mas3[16];
	fill_mas(mas1, 2);
	fill_mas(mas2, 3);
	fill_mas(mas3, 4);
	int summa = sum(2, 1, 2);
	printf("mas1: %d\n", mat_sum_count(mas1, 2));
	printf("mas2: %d\n", mat_sum_count(mas2, 3));
	printf("mas3: %d\n", mat_sum_count(mas3, 4));
}