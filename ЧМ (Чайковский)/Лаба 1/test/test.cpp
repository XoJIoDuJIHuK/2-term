#include <iostream>
using namespace std;

void main()
{
	for (float i = 2; i <= 3; i += 0.1)
	{
		printf("%f	%f\n", i, pow(2.7182818284, 4 * i - 3) / i);
	}
}