#include "funcs.h"
using namespace std;
char Let[] = { "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm" };
char MTO[10];
int d = 0;
struct AAA
{
	int key;
	int mas;
	AAA(int k, int z)
	{
		key = k;
		mas = z;
	}
	AAA() {}
};

int key(void* d)
{
	AAA* f = (AAA*)d; 
	return f->key;
}

void AAA_print(void* d)
{
	cout << "Ключ " << (char)((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}


void main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	int siz;
	AAA* a;
	char* str;
	int m = 0;
	cout << "Введите размер хэш-таблицы" << endl;
	cin >> siz;
	Object H = Create(siz, key);
	int choise; 			
	int k, z = 0;
	char str2[16];
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
		{
			cout << "Введите слово: " << endl;
			cin >> str2;
			for (int i = 0; i < 16; i++)
			{
				char lel = str2[i];
				for (int j = 0; j < strlen(Let); j++) {
					if (str2[i] == Let[j])
						for (int r = 0; r < strlen(str2); r++)
							if (str2[r] == lel)
								m++;
				}
				if (m > 0)
				{
					a = new AAA();
					a->key = (int)str2[i];
					a->mas = m;
					H.Insert(a);
					m = 0;
				}
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
			char l;
			cin >> l;
			k = (int)l;
			if (H.Search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else  AAA_print(H.Search((int)k));
			break;
		case 5:
			cout << "Таблица заполнена на " << H.koefzap() * 100 << "%" << endl;
			break;
		}
		system("pause");
	}
}
