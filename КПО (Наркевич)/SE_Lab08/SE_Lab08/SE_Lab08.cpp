#include <iostream>
#include "Call.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	int s;
	while (true)
	{
		cout << "����� ������� �������?\n";
		cout << "1 - cdevl\n";
		cout << "2 - cstd\n";
		cout << "3 - cfst\n";
		cout << "0 - �����\n";
		cin >> s;
		switch (s)
		{
			case 1:
			{
				cout << "������� ��� �����\n";
				int a, b, c;
				cin >> a;
				cin >> b;
				cin >> c;
				cout << cdevl(a, b, c) << endl;
				break;
			}
			case 2:
			{
				cout << "������� ��� �����\n";
				int a, b, c;
				cin >> a;
				cin >> b;
				cin >> c;
				int& ref = a;
				cout << cstd(ref, b, c) << endl;
				break;
			}
			case 3:
			{
				cout << "������� ������ �����\n";
				int a, b, c, d;
				cin >> a;
				cin >> b;
				cin >> c;
				cin >> d;
				cout << cfst(a, b, c, d) << endl;
				break;
			}
			case 0: exit(1);
			default:
			{
				cout << "�������� ����\n";
				exit(1);
			};
		}
	}
}