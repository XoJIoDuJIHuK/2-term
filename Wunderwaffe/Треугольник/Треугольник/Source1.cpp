#include <iostream>
#include <Windows.h>
#include <cmath>
#define OX 100
#define OY 40
using namespace std;

float function(int x, float a, float b)
{
	float y = x * a + b;
	return y;
}

void draw(float a, float b, float c, float d, float e, float f)
{
	float x1, x2, x3, y1, y2, y3;
	x1 = (d - b) / (a - c);
	x2 = (f - d) / (c - e);
	x3 = (b - f) / (e - a);
	y1 = function(x1, a, b);
	y2 = function(x2, c, d);
	y3 = function(x3, e, f);

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
				if (int(round(function(i, a, b))) < OY)
				{
					if (int(round(function(i, a, b))) == j)
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
				if (0 < int(round(function(i, c, d))) < OY)
				{
					if (int(round(function(i, c, d))) == j)
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
				if (0 < int(round(function(i, e, f))) < OY)
				{
					if (int(round(function(i, e, f))) == j)
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
	draw(a, b, c, d, e, f);
	COORD position = { 0,0 };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	Sleep(1000);
	draw(a, b - 5, c, d + 5, e, f);
	a = tan(atan(a) + 3.1415 / 6);
	c = tan(atan(c) + 3.1415 / 6);
	e = tan(atan(e) + 3.1415 / 6);
	//a = 0.0;
	//c = sqrt(3.0) / 2.0;
	//e = -sqrt(3.0) / 2.0;
	b = 5.0;
	d = 30.0;
	f = 0.0;
	SetConsoleCursorPosition(hConsole, position);
	Sleep(1000);
	draw(a, b, c, d, e, f);
}