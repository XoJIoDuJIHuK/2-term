#include <stdio.h>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void func1()
{
	string s_words[4][4];
	static char stroki[4][28];//[номера строк][номера букв строк]
	FILE* fin;
	fopen_s(&fin, "D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.5\\FILE1.txt", "r+");
	ofstream fout1("D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.5\\FILE2.txt");
	for (int num_of_lines = 0; !feof(fin); num_of_lines++)
	{
		char s[29];
		fgets(s, 29, fin);
		for (int j = 0; j < 27; j++)
		{
			stroki[num_of_lines][j] = s[j];
		}
	}
	static char words[4][14][27];//[номера строк][номера слов][номера букв слов]
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
		for (int j = 0; j < 28; j++)
		{
			s_stroki[i] += stroki[i][j];
		}
		s_stroki[i] += '\n';
	}
	static int mas[6];
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < (sizeof(s_words[i]) / sizeof(string)); n++)
		{
			for (int k = i + 1; k < 4; k++)
			{
				for (int j = 0; j < (sizeof(s_words[i]) / sizeof(string)); j++)
				{
					if (s_words[i][n] == s_words[k][j])
					{
						if (i == 0 and k == 1)
						{
							mas[0]++;
							if (mas[0] == 2)
							{
								fout1 << s_stroki[0];
								fout1 << s_stroki[1];
							}
						}
						if (i == 0 and k == 2)
						{
							mas[1]++;
							if (mas[1] == 2)
							{
								fout1 << s_stroki[0];
								fout1 << s_stroki[2];
							}
						}
						if (i == 0 and k == 3)
						{
							mas[2]++;
							if (mas[2] == 2)
							{
								fout1 << s_stroki[0];
								fout1 << s_stroki[3];
							}
						}
						if (i == 1 and k == 2)
						{
							mas[3]++;
							if (mas[3] == 2)
							{
								fout1 << s_stroki[1];
								fout1 << s_stroki[2];
							}
						}
						if (i == 1 and k == 3)
						{
							mas[4]++;
							if (mas[4] == 2)
							{
								fout1 << s_stroki[1];
								fout1 << s_stroki[3];
							}
						}
						if (i == 2 and k == 3)
						{
							mas[5]++;
							if (mas[5] == 2)
							{
								fout1 << s_stroki[2];
								fout1 << s_stroki[3];
							}
						}
					}
				}
			}
		}
	}
	int nomer_max = -1, nomer = 0;
	int kolvo = 0, max_kolvo = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			nomer++;
			kolvo = 0;
			for (int k = 0; k < (sizeof(s_words[i][j]) / sizeof(string)); k++)
			{
				if ((s_words[i][j][k] >= '0') and (s_words[i][j][k] <= '9'))
				{
					kolvo += 1;
				}
			}
			if (kolvo > max_kolvo)
			{
				nomer_max = nomer;
				max_kolvo = kolvo;
			}
		}
	}
	printf("Word number %d has %d digits", nomer_max, kolvo);
	fclose(fin);
	fout1.close();
	exit(12);
}

void func2()
{
	FILE* fout;
	fopen_s(&fout, "D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.5\\FILE3.txt", "w");
	static char stroka[256], str2[256];
	static string str1;
	int i = 0;
	while ((stroka[i++] = getchar()) != '0')
	{
		if (i == 255)
			break;
	}
	for (int i = 0; i < 255; i++)
	{
		stroka[i] = stroka[i+1];
	}
	fputs(stroka, fout);
	fclose(fout);
	ifstream fin("D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.5\\FILE3.txt");
	if (!fin.is_open())
		cout << "error\n";
	else
		fin.getline(str2, 256);
	static char words[128][128];
	for (int i = 0, j = 0, k = 0; str2[i] != '\0'; i++)
	{
		if (str2[i] >= 'A' and str2[i] <= 'z')
		{
			words[k][j] = str2[i];
			j++;
			if ((str2[i+1] == ' ') or (str2[i + 1] == '\0') or (str2[i + 1] == '\n'))
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
			if (words[i][j] == 'x')
			{
				for (int k = 0; k < 128; k++)
				{
					cout << words[i][k];
				}
				cout << ' ';
				continue;
			}
		}
	}
	fin.close();
	exit(13);
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