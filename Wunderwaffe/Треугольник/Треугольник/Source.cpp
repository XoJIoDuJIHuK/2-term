#include <iostream>
#include <Windows.h>
using namespace std;
#define OX 80
#define OY 150

float f1(int x)
{
	float a = sqrt(3.0)/2.0, b = 0.0;
	return(a * double(x) + b);
}
float f2(int x)
{
	float c = -sqrt(3.0)/2.0, d = 30.0;
	return(c * double(x) + d);
}
float f3(int x)
{
	float e = 0.0, f = 5.0;
	return(e * double(x) + f);
}

void fill_1(float a, float b, float c, float d, float e, float f, float x1, float y1, float x2, float y2, float x3, float y3)
{
	char field[OX][OY];
	for (int i = 0; i < OX; i++)
	{
		for (int j = 0; j < OY; j++)
		{
			field[i][j] = ' ';
		}
	}

	for (int i = 0; i < OX; i++) //чертим f1
	{
		if ((i >= int(round(x3))) and (i <= int(round(x1))))
		{
			for (int j = 0; j < OY; j++)
			{
				if (int(round(f1(i))) < OY)
				{
					if (int(round(f1(i))) == j)
					{
						field[i][j] = '*';
					}
				}
			}
		}
	}

	for (int i = 0; i < OX; i++) //чертим f2
	{
		if ((i >= int(round(x1))) and (i <= int(round(x2))))
		{
			for (int j = 0; j < OY; j++)
			{
				if (0 < int(round(f2(i))) < OY)
				{
					if (int(round(f2(i))) == j)
					{
						field[i][j] = '*';
					}
				}
			}
		}
	}

	for (int i = 0; i < OX; i++) //чертим f3
	{
		if ((i >= int(round(x3))) and (i <= int(round(x2))))
		{
			for (int j = 0; j < OY; j++)
			{
				if (0 < int(round(f3(i))) < OY)
				{
					if (int(round(f3(i))) == j)
					{
						field[i][j] = '*';
					}
				}
			}
		}
	}

	for (int j = 0; j < OY; j++)
	{
		for (int i = 0; i < OX; i++)
		{
			cout << field[i][j];
		}
		cout << '\n';
	}
}

void main()
{
	float a = sqrt(3.0) / 2.0, b = 0.0, c = -sqrt(3.0) / 2.0, d = 30.0, e = 0.0, f = 5.0;
	float x1, y1, x2, y2, x3, y3;
	//f1 = xa, a = √3/2, + b, b = 0
	//f2 = xc, c = -√3/2, + d, d = 5
	//f3 = ex, e = 0, + f, f = 1
	x1 = (d - b) / (a - c);
	x2 = (f - d) / (c - e);
	x3 = (b - f) / (e - a);
	y1 = f1(x1);
	y2 = f2(x2);
	y3 = f3(x3);
	fill_1(a, b, c, d, e, f, x1, y1, x2, y2, x3, y3);
	Sleep(5000);
	SetCursorPos(0, 0);
	fill_1(a, b, c, d, e, f, x1 + 20, y1, x2 + 20, y2, x3 + 20, y3);
}