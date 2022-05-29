#include <stdio.h>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void func1()
{
	string s_words[4][4];
	static char stroki[4][27]{};//[номера строк][номера букв строк]
	FILE* fin;
	fopen_s(&fin, "D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\12 вариант\\FILE1.txt", "r");
	ofstream f_write1("D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\12 вариант\\FILE2.txt");
	for (int num_of_lines = 0; !feof(fin); num_of_lines++)
	{
		char s[29];
		fgets(s, 29, fin);
		for (int j = 0; j < 27; j++)
		{
			stroki[num_of_lines][j] = s[j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		static char buffer[27];
		for (int n = 0; n < 27; n++)
		{
			buffer[n] = stroki[i][n];
		}
		int k = 0;
		int m = 0;
		for (int j = 0; j < 28; j++)
		{
			if ((buffer[j] >= 'A') and (buffer[j] <= 'z') or (buffer[j] >= '0') and (buffer[j] <= '9'))
			{
				s_words[i][k] += buffer[j];
				m++;
				if ((buffer[j + 1] == ' ') or (j == 27))
				{
					k++;
					m = 0;
				}
			}
		}
	}
	string s_stroki[4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			s_stroki[i] += stroki[i][j];
		}
		s_stroki[i] += '\n';
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			bool hgfd = (s_words[i][j] == s_words[i][0]);
			if (hgfd)
			{
				for (int k = 0; k < 26; k++)
					f_write1 << s_stroki[i][k];
				break;
			}
		}
	}
	fclose(fin);
	f_write1.close();
	exit(12);
}

void func2()
{
	FILE* f_write;
	fopen_s(&f_write, "D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\12 вариант\\FILE3.txt", "w");
	static char stroka[256], str2[256];
	static string str1;
	int i = 0;
	while ((stroka[i++] = getchar()) != '`')
	{
		if (i == 255)
			break;
	}
	for (int i = 0; i < 255; i++)
	{
		stroka[i] = stroka[i + 1];
	}
	fputs(stroka, f_write);
	fclose(f_write);
	ifstream f_read("D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\12 вариант\\FILE3.txt");
	if (!f_read.is_open())
		cout << "error\n";
	else
		f_read.getline(str2, 256);
	static char words[128][128];
	for (int i = 0, j = 0, k = 0; str2[i] != '\0'; i++)
	{
		if ((str2[i] >= 'A' and str2[i] <= 'z') or (str2[i] >= '0' and str2[i] <= '9'))
		{
			words[k][j] = str2[i];
			j++;
			if ((str2[i + 1] == ' ') or (str2[i + 1] == '\0') or (str2[i + 1] == '\n'))
			{
				k++;
				j++;
			}
			if ((str2[i + 1] == '\0') or (str2[i + 1] == '\n'))
			{
				break;
			}
		}
	}
	for (i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if ((words[i][j] >= '0') && (words[i][j] <= '9'))
			{
				if ((words[i][j] - '0') % 2 != 0)
				{
					cout << words[i][j];
				}
			}
		}
	}
	f_read.close();
	exit(12);
}

int main()
{
	cout << "Enter 1 or 2\n";
	int a;
	cin >> a;
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