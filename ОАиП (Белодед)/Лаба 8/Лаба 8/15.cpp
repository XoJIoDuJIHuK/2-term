#include <iostream>
using namespace std;
        
struct Queue
{
	char symbol;
	Queue* next;
};

void intoFIFO(Queue* ph[], int v) //Постановка элемента в конец очереди
{
	Queue* p = new Queue;
	p->symbol = v;
	p->next = NULL;
	if (ph[0] == NULL)
		ph[0] = ph[1] = p;   //включение в пустую очередь
	else
	{
		ph[1]->next = p;
		ph[1] = p;
	}
}

int length(Queue* ph[])           //Вывод длины очереди
{
	int i = 0;
	for (Queue* p = ph[0]; p != NULL; p = p->next)
	{
		i++;
	}
	return i;
}

void scan(Queue* ph[])           //Вывод элемента              
{
	for (Queue* p = ph[0]; p != NULL; p = p->next)
		cout << p->symbol << ' ';
	cout << endl;
}

char fromFIFO(Queue* ph[])      //Извлечение элемента 
{
	Queue* q;
	if (ph[0] == NULL) return -1;     // очередь пуста
	q = ph[0];                        // исключение первого элемента
	ph[0] = q->next;
	if (ph[0] == NULL) ph[1] = NULL;
	char v = q->symbol;
	return v;
}

void main()
{
	char ref_symbol;
	cout << "Enter reference symbol ";
	cin >> ref_symbol;
	Queue A;
	Queue* ptr_A = &A;
	ptr_A->next = NULL;
	ptr_A->symbol = ref_symbol;
	Queue* ph[2];
	ph[0] = &A;
	ph[1] = &A;
	while (true)
	{
		char a;
		cin >> a;
		if (a == ref_symbol)
		{
			break;
		}
		intoFIFO(ph, a);
	}
	for (int i = 0; i < 2; i++)
	{
		char vv = fromFIFO(ph);
	}
	scan(ph);
	cout << "FIFO length: " << length(ph);
}