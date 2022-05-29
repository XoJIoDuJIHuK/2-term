#include <iostream>
using namespace std;

float func(float x)
{
	const float e = 2.7182818284;
	return (pow(e, 4 * x - 3) / x);
}

float func2(float x)
{
	return (func(x) * (16 * x * x - 8 * x + 2) / (x * x));
}

float pogr()
{
	float a = 1, b = 3, N = 10, h = (b - a) / N, x = a;
	float sum = 0; float* ptr_sum = &sum;
	for (int k = 0; k <= 10; x += ((b - a) / N), k++)
	{
		if ((k == 0) or (k == 10))
		{
			*ptr_sum += 0.5 * func2(x);
		}
		else
		{
			*ptr_sum += func2(x);
		}
	}
	return sum;
}

void main()
{
	float a = 1, b = 3, N = 10, h = (b - a) / N, x = a;
	float sum = 0; float* ptr_sum = &sum;
	for (int k = 0; k <= 10; x += ((b - a) / N), k++)
	{
		*ptr_sum += func((2 * x - h) / 2);
	}
	printf("Int sum step 1/10 = %f, R = ", h * sum);
}