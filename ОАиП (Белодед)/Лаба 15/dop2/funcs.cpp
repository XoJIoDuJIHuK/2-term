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
				if (ptr == (arr*)DEL)
				{
					cout << "deleted" << endl;
					return;
				}
				cout << "string: " << ptr->str << endl;
			}
		} while (ptr = ptr->next);
	}
}
void input(arr* tab, int size, string str, int* rand8)
{
	int k = hash_f(str, rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->str[0] == '\0')
	{
		ptr->next = NULL;
		ptr->str = str;
	}
	else
	{
		while (ptr->next) ptr = ptr->next;
		arr* p = new arr;
		p->next = NULL;
		p->str = str;
		ptr->next = p;
	}
}
void search(arr* tab, int size, string str, int* rand8)
{
	int count = 0;
	int k = hash_f(str, rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->str[0] != '\0')
	{
		while (ptr->next && ptr->str != str)
		{
			ptr = ptr->next;
			count++;
		}
		if (ptr->str == str)
		{
			cout << "key: " << ptr->str << endl;
			cout << "number of comparisons: " << count << endl;
			return;
		}
		cout << "error\n";
		exit(1);
	}
	cout << "not found\n";
	return;
}
void delete_by_char(arr *tab, int size, string str, int *rand8)
{
	int k = hash_f(str, rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->str[0] != '\0')
	{
		arr* ptr_prev = ptr;
		if (ptr->str == str)
		{
			if (ptr->next)
			{
				ptr->str = ptr->next->str;
				ptr_prev = ptr->next;
				ptr->next = ptr_prev->next;
				delete ptr_prev;
			}
			else
			{
				ptr->str = '\0';
			}
			return;
		}
		while (ptr->next && ptr->next->str != str)
		{
			ptr = ptr->next;
		}
		if (!ptr->next && ptr->str != str)
		{
			cout << "not found\n";
			return;
		}
		ptr = ptr->next;
		if (ptr->str == str)
		{
			ptr_prev->next = ptr->next;
			delete ptr_prev;
			return;
		}
		cout << "error\n";
		exit(1);
	}
	cout << "not found\n";
	return;
}