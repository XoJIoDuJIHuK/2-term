#include <iostream>
#include <ctime>

void main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "������������!" << endl;
switch1: cout << "������� 1, ���� ������ ������, � 2, ���� ������ �����" << endl;
	int a;
	cin >> a; cout << endl;
	switch (a)
	{
		case 1:
		{
			cout << "�������! ";
  TryAgain: cout << "������� ������ ������� ��� ����������� ����� ";
			int b;
			cin >> b; printf("\n");
			cout << "������ ������� ������� ������� ";
			int c;
			cin >> c; printf("\n");
			if (c >= b)
			{
				srand(time(NULL));
				int random = b + rand() % (c - b + 1);
				cout << "����� ��������. �����!" << endl;
				int d;
				while (true)
				{
			  Diap: cout << "����������, ������� �����, �������, ��� �� �������, �������� ��������� "; cin >> d;
					if (d <= c and d >= b)
					{
						if (d == random)
						{
							cout << "����������! �� ������� �����! ";
				   switch2: cout << "������� 1, ���� ������ ����������� ��� ���, � 2, ���� ������ ����� " << endl;
							cin >> a; cout << endl;
							switch (a)
							{
								case 1:
								{
									goto TryAgain;
								}
								case 2:
								{
									goto GoodBye;
								}
								default:
								{
									cout << "������������ ����" << endl;
									goto switch2;
								}
							}
						}
						else
						{
							cout << "���, �� �� �����" << endl;
				   switch3: cout << "������� 1, ���� ������ ����������, � 2, ���� ������ ����� ";
							cin >> a; cout << endl;
							switch (a)
							{
								case 1:
								{
									continue;
								}
								case 2:
								{
									goto GoodBye;
								}
								default:
								{
									cout << "������������ ����";
									goto switch3;
								}
							}
						}
					}
					else
					{
						cout << "����������, ������� ����� � ��� ���������, ������� �� ���� ������" << endl;
						goto Diap;
					}
				}
			}
			else
			{
				cout << "� ��������� ��� ������� ����� ���������" << endl;
				goto TryAgain;
			}
		}
		case 2:
		{
   GoodBye: cout << "�� ��������!" << endl;
			break;
		}
		default:
		{
			cout << "������������ ����"; cout << endl;
			goto switch1;
		}
	}
}