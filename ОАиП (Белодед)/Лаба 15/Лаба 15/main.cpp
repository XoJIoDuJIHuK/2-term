#include "funcs.h"

void main()
{
	int rand8[256];
	for (int i = 0; i < 256; i++)
	{
		rand8[i] = 0 + rand() % 255;
	}
	cout << "enter size: ";
	int size;
	cin >> size;
	arr *tab = new arr[size];
	int choise;
	do
	{
		system("cls");
		cout << "1 - output\n2 - input\n3 - search\n0 - exit\n";
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
				string str, num;
				cout << "enter num: ";
				cin >> num;
				cout << "enter str: ";
				cin >> str;
				input(tab, size, num, str, rand8);
				break;
			}
			case 3:
			{
				cout << "enter num: ";
				string num;
				cin >> num;
				search(tab, size, num, rand8);
				break;
			}
		default:
			break;
		}
		system("pause");
	} while (choise);
}