#include "Hash.h"
#include <iostream>
using namespace std;

int key(AAA* d)
{
	AAA* f = d;
	return f->key;
}

void AAA_print(AAA* d)
{
	cout << "���� " << d->key << " - " << d->mas << endl;
}


void main()
{
	setlocale(LC_ALL, "rus");
	int siz;
	AAA* a;
	char* str;
	cout << "������� ������ ���-�������" << endl;
	cin >> siz;
	Object H = Create(siz, key);
	int choise;
	int k, start_time, end_time;
	AAA* ptr = new AAA;
	for (;;)
	{
		system("cls");
		cout << "����:" << endl;
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "5 - ����������� ���������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choise;
		switch (choise)
		{
		case 0: exit(0);
		case 1: H.Scan(AAA_print); break;
		case 2:
			a = new AAA();
			cout << "������� ����" << endl;
			cin >> k;
			a->key = k;
			str = new char[20];
			cout << "������� ������" << endl;
			cin >> str;
			a->mas = str;
			if (H.N == H.Size)
				cout << "������� ���������" << endl;
			else
			{
				H.Insert(a);
				int a = 2;
				switch (a)
				{
					case 1:
					{
						if (H.koefzap() >= 0.5)
						{
							(&H)->Size *= 2;
							AAA** newData = new AAA * [(&H)->Size * 2];
							AAA** oldData = (&H)->Data;
							(&H)->Data = newData;
							(&H)->N = 0;
							for (int i = 0; i < (&H)->Size; ++i)
								(&H)->Data[i] = NULL;
							for (int i = 0; i < (&H)->Size / 2; i++)
							{
								if (oldData[i])
								{
									H.Insert(oldData[i]);
								}
							}
						}
						break;
					}
					case 2:
					{
						if (H.koefzap() >= 0.7)
						{
							(&H)->Size *= 3;
							AAA** newData = new AAA * [(&H)->Size * 3];
							AAA** oldData = (&H)->Data;
							(&H)->Data = newData;
							for (int i = 0; i < (&H)->Size; ++i)
								(&H)->Data[i] = NULL;
							for (int i = 0; i < (&H)->Size / 3; i++)
							{
								if (oldData[i])
								{
									H.Insert(oldData[i]);
								}
							}
						}
						break;
					}
					default:
						break;
				}
			}
			break;
		case 3:
			cout << "������� ���� ��� �������� " << endl;
			cin >> k;
			H.Delete(k);
			break;
		case 4:
			cout << "������� ���� ��� ������ " << endl;
			cin >> k;
			start_time = clock();
			ptr = H.Search(k);
			end_time = clock();
			if (ptr == NULL)
				cout << "������� �� ������" << endl;
			else  AAA_print(ptr);
			cout << "time: " << end_time - start_time << endl;
			break;
		case 5:
			cout << "������� ��������� �� " << H.koefzap() * 100 << "%" << endl;
			break;
		}
		system("pause");
	}
}
