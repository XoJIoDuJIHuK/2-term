#include <float.h>
#include <iostream>

namespace Varparm
{
	int ivarparm(int a, ...)
	{
		int mul = 1;
		for (int i = 1; i <= a; i++)
		{
			mul *= *(&a + i);
		}
		return mul;
	}

	short svarparm(short a, ...)
	{
		short max = -32768;
		for (short i = 1; i <= a; i++)
		{
			if (*(&a + i) > max)
			{
				max = *(&a + i);
			}
		}
		return max;
	}

	float fvarparm(float a, ...)
	{
		if (a == FLT_MAX)
		{
			std::cout << "Empty list of parameters\n";
			return 0;
		}
		double* ptr = (double*)(&a + 1);
		double sum = a;
		int k = 0;
		while (ptr[k] != (double)FLT_MAX)
			sum += ptr[k++];
		return sum;
	}

	double dvarparm(double a, ...)
	{
		if (a == DBL_MAX)
		{
			std::cout << "Empty list of parameters\n";
			return 0;
		}
		double* ptr = (double*)(&a + 1);
		double sum = a;
		int k = 0;
		while (ptr[k] != (double)DBL_MAX)
			sum += ptr[k++];
		return sum;
	}
}