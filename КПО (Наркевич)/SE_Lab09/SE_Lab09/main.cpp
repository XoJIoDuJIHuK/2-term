#include <iostream>
using namespace std;

float defaultparm(int f = 6, int g = 7, int a, int b, int c, int d, int e)
{
	return (float)(a + b + c + d + e + f + g) / 7;
}

void main()
{
	defaultparm(1, 2, 3, 4, 5);
	defaultparm(1, 2, 3, 4, 5, 9, 10);
}