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
	cout << "Ключ " << d->key << " - " << d->mas << endl;
}


void main()
{
	setlocale(LC_ALL, "rus");
	int siz;
	AAA* a;
	char* str;
	cout << "Введите размер хэш-таблицы" << endl;
	cin >> siz;
	Object H = Create(siz, key);
	int choise;
	int k, start_time, end_time;
	AAA* ptr = new AAA;
	for (;;)
	{
		system("cls");
		cout << "Меню:" << endl;
		cout << "1 - вывод хэш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "5 - коэффициент заполнения таблицы" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choise;
		switch (choise)
		{
		case 0: exit(0);
		case 1: H.Scan(AAA_print); break;
		case 2:
			a = new AAA();
			cout << "Введите ключ" << endl;
			cin >> k;
			a->key = k;
			str = new char[20];
			cout << "Введите строку" << endl;
			cin >> str;
			a->mas = str;
			if (H.N == H.Size)
				cout << "Таблица заполнена" << endl;
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
			cout << "Введите ключ для удаления " << endl;
			cin >> k;
			H.Delete(k);
			break;
		case 4:
			cout << "Введите ключ для поиска " << endl;
			cin >> k;
			start_time = clock();
			ptr = H.Search(k);
			end_time = clock();
			if (ptr == NULL)
				cout << "Элемент не найден" << endl;
			else  AAA_print(ptr);
			cout << "time: " << end_time - start_time << endl;
			break;
		case 5:
			cout << "Таблица заполнена на " << H.koefzap() * 100 << "%" << endl;
			break;
		}
		system("pause");
	}
}
