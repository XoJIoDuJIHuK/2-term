#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Item
{
	int number;
	Item* previous;
};

void main()
{
	Item* plist = nullptr;   //указатель на начало списка
	Item* p;
	int number;
	for (;;)                 // создание списка
	{
		cout << "Input number ";
		cin >> number;	   //ввод чисел, пока не введен 0
		if (!number)
		{
			break;
		}
		p = new Item;
		p->number = number;
		p->previous = plist;
		plist = p;
	}
	p = plist;
	int sum = 0;
	while (p)
	{
		if (p->number > 0)
		{
			int ost = p->number % 10;
			if (ost == 7)
			{
				sum += p->number;
			}
		}
		p = p->previous;
	}
	if (sum)
	{
		cout << sum << endl;
	}
	else
	{
		cout << "Таких элементов нет\n";
	}
	while (plist)              // перебор списка и удаление элементов
	{
		p = plist;
		plist = p->previous;
		delete p;
	}
}