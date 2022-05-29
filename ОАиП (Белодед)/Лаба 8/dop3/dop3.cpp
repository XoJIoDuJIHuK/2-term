#include <iostream>
#include <fstream>
#include <string>
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

void scan(Queue* ph[])           //Вывод всей очереди через пробел
{
	for (Queue* p = ph[0]; p != NULL; p = p->next)
		cout << p->symbol << ' ';
	cout << endl;
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

int find_max_element(Queue* ph[])           //Возвращает значение наибольшего элемента очереди
{
	int max = -32000;
	for (Queue* p = ph[0]; p != NULL; p = p->next)
		if (p->symbol > max)
		{
			max = p->symbol;
		}
	return max;
}

int scan_first_element(Queue* ph[])           //Возврат значения первого элемента очереди
{
	Queue* p = ph[0];
	return p->symbol;
}

char fromFIFO(Queue* ph[])      //Удаление и возврат первого элемента
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
	ifstream f("f.txt");
	ofstream g("g.txt");
	Queue A;
	Queue* ptr_A = &A;
	ptr_A->next = NULL;
	ptr_A->symbol = 0;
	Queue* ph[2];
	ph[0] = &A;
	ph[1] = &A;
	string mas_of_strings[4];
	if (f.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			string new_string;
			Queue letters, numbers;
			Queue *ptr_letters = &letters, *ptr_numbers = &numbers;
			ptr_letters->next = NULL;
			ptr_letters->symbol = '0';
			ptr_numbers->next = NULL;
			ptr_numbers->symbol = '0';
			Queue* pl[2];
			Queue *pn[2];
			pl[0] = &letters;
			pl[1] = &letters;
			pn[0] = &numbers;
			pn[1] = &numbers;
			getline(f, mas_of_strings[i]);
			for (int j = 0; j < mas_of_strings[i].length(); j++)
			{
				if (('0' <= mas_of_strings[i][j]) and (mas_of_strings[i][j] <= '9'))
				{
					intoFIFO(pn, mas_of_strings[i][j]);
				}
				else
				{
					intoFIFO(pl, mas_of_strings[i][j]);
				}
			}
			fromFIFO(pn);
			fromFIFO(pl);
			for (Queue* p = pl[0]; p != NULL; p = p->next)
			{
				new_string += p->symbol;
			}
			for (Queue* p = pn[0]; p != NULL; p = p->next)
			{
				new_string += p->symbol;
			}
			mas_of_strings[i] = new_string;
			g << new_string << endl;
		}
	}
	else
	{
		cout << "Invalid file\n";
	}
}