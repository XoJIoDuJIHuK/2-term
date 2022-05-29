#include <iostream>
#include <string>
using namespace std;

struct Stek
{
	int number;
	Stek* next;
} stek, stek_new;


int pop(Stek*& st) // ���������� ��������
{
	int tmp = st->number;
	Stek* pv = st;
	st = st->next;       // �������� ���������� �������������� �������
	delete pv;           // ������������� ������ 
	return tmp;
}

void push(Stek*& st, int d) // ���������� ��������
{
	Stek* pv = new Stek;
	pv->number = d;   // �������� ���������� � ����     
	pv->next = st;
	st = pv;
}


void main()
{
	int lower, higher;
	cout << "Enter lower border "; cin >> lower;
	cout << "Enter higher border "; cin >> higher;
	if (lower > higher)
	{
		cout << "Invalid borders";
		exit(12);
	}
	int size = 5;
	int a;
	Stek* ptr_stek = &stek;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number: ";
		cin >> a;
		push(ptr_stek, a);
	}
	for (int i = 0; i < size; i++)
	{
		if (lower <= pop(ptr_stek) <= higher)
		{
			cout << "Such element exists\n";
			exit(13);
		}
	}
}