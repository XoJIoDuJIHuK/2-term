#include <iostream>
using namespace std;

struct Queue
{
	int symbol;
	Queue* next;
};

void intoFIFO(Queue* ph[], int v) //���������� �������� � ����� �������
{
	Queue* p = new Queue;
	p->symbol = v;
	p->next = NULL;
	if (ph[0] == NULL)
		ph[0] = ph[1] = p;   //��������� � ������ �������
	else
	{
		ph[1]->next = p;
		ph[1] = p;
	}
}

void scan(Queue* ph[])           //����� ���� ������� ����� ������
{
	for (Queue* p = ph[0]; p != NULL; p = p->next)
		cout << p->symbol << ' ';
	cout << endl;
}

int find_max_element(Queue* ph[])           //���������� �������� ����������� �������� �������
{
	int max = -32000;
	for (Queue* p = ph[0]; p != NULL; p = p->next)
		if (p->symbol > max)
		{
			max = p->symbol;
		}
	return max;
}

int scan_first_element(Queue* ph[])           //������� �������� ������� �������� �������
{
	Queue* p = ph[0];
	return p->symbol;
}

char fromFIFO(Queue* ph[])      //�������� � ������� ������� ��������
{
	Queue* q;
	if (ph[0] == NULL) return -1;     // ������� �����
	q = ph[0];                        // ���������� ������� ��������
	ph[0] = q->next;
	if (ph[0] == NULL) ph[1] = NULL;
	char v = q->symbol;
	return v;
}

void main()
{
	Queue A;
	Queue* ptr_A = &A;
	ptr_A->next = NULL;
	ptr_A->symbol = 0;
	Queue* ph[2];
	ph[0] = &A;
	ph[1] = &A;
	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		intoFIFO(ph, a);
		if (i == 0)
		{
			int vv = fromFIFO(ph);
		}
	}
	scan(ph);
	int max = find_max_element(ph);
	while (true)
	{
		Queue* p = ph[0];
		if (scan_first_element(ph) == max)
		{
			break;
		}
		int buffer = fromFIFO(ph);
		intoFIFO(ph, buffer);
		scan(ph);
	}
}