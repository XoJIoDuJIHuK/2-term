#include "funcs.h"

void main()
{
	int rand8[256] = {0};
	for (int i = 0; i < 256; i++)
	{
		rand8[i] = 0 + rand() % 255;
	}
	cout << "enter size: ";
	int size;
	cin >> size;
	arr* tab = new arr[size];
	int choise = 0;
	do
	{
		system("cls");
		cout << "1 - output\n2 - input\n3 - search\n4 - delete\n0 - exit\n";
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
			int num;
			cout << "enter str: ";
			cin.ignore();
			getline(cin, str);
			cout << "enter num: ";
			cin >> num;
			if (0 < num < INT_MAX)
			{
				input(tab, size, str, num, rand8);
			}
			else cout << "Invalid number\n";
			break;
		}
		case 3:
		{
			cout << "enter num: ";
			int num;
			cin >> num;
			cin.ignore();
			int start = clock();
			search(tab, size, num, rand8);
			int end = clock();
			cout << "search time: " << end - start << endl;
			break;
		}
		case 4:
		{
			cout << "enter num: ";
			int num;
			cin >> num;
			dlt(tab, size, num, rand8);
		}
		default:
			break;
		}
		system("pause");
	} while (choise);
}