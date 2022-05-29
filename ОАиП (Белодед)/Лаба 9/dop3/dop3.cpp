#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	int number;
	Address* next;
	Address* prev;
};

void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->number << endl;
		t = t->next;
	}
	cout << "" << endl;
}

void main()
{
	cout << "Enter k: ";
	int k;
	cin >> k;
	Address* head = NULL;
	Address* last = NULL;
	for (int i = 0; i < 10; i++)
	{
		Address* e = new  Address();
		Address* p = last;
		if (last == NULL)
		{
			e->next = NULL;
			e->prev = NULL;
			e->number = i;
			last = e;
			head = e;
		}
		else
		{
			p->next = e;
			e->next = NULL;
			e->prev = p;
			e->number = i;
			last = e;
		}
	}
	last->next = head;
	head->prev = last;
	Address* temp = head;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < k; j++)
		{
			temp = temp->next;
		}
		printf("Number %d: %d\n", i + 1, temp->number);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
}