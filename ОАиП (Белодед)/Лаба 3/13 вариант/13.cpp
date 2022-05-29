#include <stdio.h>  
#include <cstdio>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void func1()
{
	string buffer_line;
	string all_strings[4];
	string words[4][4];
	ifstream fin("FILE1.txt");
	if (!fin.is_open())
	{
		cout << "Invalid file\n";
		exit(3);
	}
	else
	{
		int i = 0;
		while (getline(fin, buffer_line))
		{
			all_strings[i] = buffer_line;
			i++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0, j = 0; k < 50; k++)
		{
			if ((all_strings[i][k] > 0) && (all_strings[i][k] != ' '))
			{
				words[i][j] += all_strings[i][k];
				if (all_strings[i][k + 1] == ' ')
				{
					j++;
				}
			}
			if (all_strings[i][k + 1] == '\0')
			{
				break;
			}
		}
	}
	ofstream fout("FILE2.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			if (words[i][2][0] != '\0')
			{
				fout << all_strings[i];
			}
		}
	}
	else
	{
		cout << "Invalid file" << endl;
		exit(3);
	}
	const char GLASNYE[12] = { 'E', 'e', 'Y', 'y', 'U', 'u', 'I', 'i', 'O', 'o', 'A', 'a' };
	int num_of_glas[4][4];
	for (int i = 0; i < 16; i++)
	{
		*(&num_of_glas[0][0] + i) = 0;
	}
	int i_max = -1, j_max = -1, num_of_glas_max = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 50; k++)
			{
				if ('z' >= words[i][j][k] >= 'A')
				{
					for (int m = 0; m < 12; m++)
					{
						if (words[i][j][k] == GLASNYE[m])
						{
							num_of_glas[i][j]++;
							break;
						}
					}
				}
				if (!('z' >= words[i][j][k] >= '0'))
				{
					break;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (num_of_glas[i][j] > num_of_glas_max)
			{
				i_max = i;
				j_max = j;
			}
		}
	}
	cout << "max number of glasnyh in word " << num_of_glas[i_max][j_max] << " num_of_glas_max: " << num_of_glas_max << endl;
}

void func2()
{
	
}

int main()
{
	cout << "Enter 1 or 2\n";
	int a = 0;
	cin >> a;
	cin.ignore(cin.rdbuf()->in_avail());
	cout << endl;
	switch (a)
	{
	case 1:
		func1();
	case 2:
		func2();
	}
	return 0;
}