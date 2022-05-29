#include <iostream>
using namespace std;

float func(float x)
{
	const float e = 2.7182818284;
	return (pow(e, 4 * x - 3) / x);
}


float pogr()
{
	float a = 1, b = 3, N = 10, h = (b - a) / N, x = a;
	float sum = 0; float* ptr_sum = &sum;
	for (int k = 0; k <= 10; x += ((b - a) / N), k++)
	{
		if ((k == 0) or (k == 10))
		{
			*ptr_sum += 0.5 * func(x);
		}
		else
		{
			*ptr_sum += func(x);
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
		if ((k == 0) or (k == 10))
		{
			*ptr_sum += func(x);
		}
		else if (k%2 == 0)
		{
			*ptr_sum += 2 * func(x);
		}
		else if (k % 2 != 0)
		{
			*ptr_sum += 4 * func(x);
		}
	}
	printf("Int sum step 1/10 = %f, R = ", h / 3.0 * sum);
}