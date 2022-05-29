#include "stdafx.h"
using namespace std;

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

void main()
{
	printf("1 + 3 = %d\n", sum(1, 3));
	printf("1 - 3 = %d\n", sub(1, 3));
	printf("1 * 3 = %d\n", mul(1, 3));
}