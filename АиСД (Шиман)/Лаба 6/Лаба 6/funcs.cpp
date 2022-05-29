#include "funcs.h"

int hash_f(string str, int* rand8)
{
	int sum = 0;
	for (int i = 0; i < str.length(); i++) sum += str[i] xor rand8[i];
	return sum;
}
void output(arr* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr* ptr = &tab[i];
		cout << "level #" << i << ":\n";
		do
		{
			if (ptr->str[0] == '\0')
			{
				cout << "Empty\n";
				break;
			}
			else
			{
				cout << "string: " << ptr->str << " number: " << ptr->num << endl;
			}
		} while (ptr = ptr->next);
	}
}
void dlt(arr* tab, int size, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->num == num)
	{
		if (ptr->next)
		{
			ptr->next = ptr->next->next;
			ptr->num = ptr->num;
			ptr->str = ptr->str;
		}
		else
		{
			ptr->num = 0;
			ptr->str = '\0';
		}
		return;
	}
	if (ptr->num)
	{
		arr* ptr_prev = new arr;
		while (ptr->next && ptr->next->num != num)
		{
			ptr_prev = ptr;
			ptr = ptr->next;
		}
		if (ptr->num == num)
		{
			ptr_prev->next = ptr->next;
			delete ptr;
			return;
		}
		cout << "error\n";
		exit(1);
	}
	cout << "not found\n";
	return;
}
void input(arr* tab, int size, string str, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (!ptr->num)
	{
		ptr->next = NULL;
		ptr->str = str;
		ptr->num = num;
	}
	else
	{
		while (ptr->next) ptr = ptr->next;
		arr* p = new arr;
		p->next = NULL;
		p->str = str;
		p->num = num;
		ptr->next = p;
	}
}
void search(arr* tab, int size, int num, int* rand8)
{
	int k = hash_f(to_string(num), rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->num)
	{
		while (ptr->next && ptr->num != num)
		{
			ptr = ptr->next;
		}
		if (ptr->num == num)
		{
			cout << "key: " << ptr->num << endl;
			return;
		}
		cout << "error\n";
		exit(1);
	}
	cout << "not found\n";
	return;
}