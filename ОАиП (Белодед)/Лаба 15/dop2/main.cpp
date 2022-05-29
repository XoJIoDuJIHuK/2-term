#include "funcs.h"
#include <fstream>

void main()
{
	ifstream f("txt.txt");
	string mas[4];
	int rand8[256];
	for (int i = 0; i < 256; i++)
	{
		rand8[i] = 0 + rand() % 255;
	}
	cout << "enter size: ";
	int size;
	cin >> size;
	arr* tab = new arr[size];
	for (int i = 0; i < 4; i++)
	{
		getline(f, mas[i]);
		input(tab, size, mas[i], rand8);
	}
	int choise;
	do
	{
		system("cls");
		cout << "1 - output\n2 - input\n3 - search\n4 - delete by char\n0 - exit\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			output(tab, size);
			break;
		}
		case 2:
		{
			string str;
			cout << "enter str: ";
			cin >> str;
			input(tab, size, str, rand8);
			break;
		}
		case 3:
		{
			cout << "enter str: ";
			string str;
			cin >> str;
			search(tab, size, str, rand8);
			break;
		}
		case 4:
		{
			cout << "enter char: ";
			cin.ignore();
			char ch = getchar();
			for (int i = 0; i < 4; i++)
			{
				if (mas[i][0] == ch) delete_by_char(tab, size, mas[i], rand8);
			}		
		}
		default:
			break;
		}
		system("pause");
	} while (choise);
}