#include <iostream>
using namespace std;
//Variant 13
float f1(float x)
{
	return (x * x * x + 5 * x - 1);
}

float f2(float x)
{
	return (x * x + 1 / x);
}

void calc(float (*f)(float))
{
	float a, b, x = 0, e = 0.001;
	for (int i = 0; i < 2; i++)
	{
		cout << "a = "; cin >> a; cout << endl;
		cout << "b = "; cin >> b; cout << endl;
		do
		{
			x = (a + b) / 2;
			if (f(a) * f(x) <= 0)
				b = x;
			else
				a = x;
		} while (abs(a - b) > (2 * e));
		cout << "x = " << x << endl;
	}
	cout << "Finished\n";
}

void main()
{
	calc(f1);
	calc(f2);
}