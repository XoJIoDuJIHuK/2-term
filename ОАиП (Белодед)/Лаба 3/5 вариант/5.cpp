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
		for (int i = 3; i < 4; i++)
		{
			fout << all_strings[i];
		}
	}
	else
	{
		cout << "Invalid file" << endl;
		exit(3);
	}
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (words[i][j][0] != '\0')
			{
				for (int k = 0, number_of_characters = 0; k < 50; k++)
				{
					if (words[i][j][k] > 1)
					{
						number_of_characters++;
						if (words[i][j][k + 1] > 0)
						{
							continue;
						}
						else
						{
							cout << number_of_characters << endl;
							exit(12);
						}
					}
				}
			}
		}
	}
}

void func2()
{
	string stroka;
	getline(cin, stroka);
	for (int i = 0; i < stroka.length(); i++)
	{
		if (!((stroka[i] >= '+') && (stroka[i] <= 'z')))
		{
			cout << "Invalid characters\n";
			exit(34);
		}
	}
	for (int i = 0; i < stroka.length(); i++)
	{
		if ((stroka[i] >= '+') && (stroka[i] <= 'z'))
		{
			if ((stroka[i] >= '0') && (stroka[i] <= '9'))
			{
				cout << stroka[i];
			}
		}
	}
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