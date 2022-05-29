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
	Item* plist = nullptr;   //��������� �� ������ ������
	Item* p;
	int number;
	for (;;)                 // �������� ������
	{
		cout << "Input number ";
		cin >> number;	   //���� �����, ���� �� ������ 0
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
		cout << "����� ��������� ���\n";
	}
	while (plist)              // ������� ������ � �������� ���������
	{
		p = plist;
		plist = p->previous;
		delete p;
	}
}