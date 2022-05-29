#include "funcs.h"

int hash_f(string num, int *rand8)
{
	int sum = 0;
	for (int i = 0; i < num.length(); i++) sum += num[i] xor rand8[i];
	return sum;
}
void output(arr *tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr *ptr = &tab[i];
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
				cout << "key: " << ptr->num << " owner: " << ptr->str << " hash: " << ptr->hash << endl;
			}
		} while (ptr = ptr->next);
	}
}
void input(arr* tab, int size, string num, string str, int* rand8)
{
	int hash;
	int k = hash_f(num, rand8);
	hash = k;
	while (k > size - 1) k -= size;
	arr *ptr = &tab[k];
	if (ptr->str[0] == '\0')
	{
		ptr->k = k;
		ptr->next = NULL;
		ptr->str = str;
		ptr->num = num;
		ptr->hash = hash;
	}
	else
	{
		while (ptr->next) ptr = ptr->next;
		arr *p = new arr;
		p->k = k;
		p->next = NULL;
		p->str = str;
		p->num = num;
		p->hash = hash;
		ptr->next = p;
	}
}
void search(arr* tab, int size, string num, int* rand8)
{
	int k = hash_f(num, rand8);
	while (k > size - 1) k -= size;
	arr* ptr = &tab[k];
	if (ptr->str[0] != '\0')
	{
		while (ptr->next && ptr->num != num) ptr = ptr->next;
		if (ptr->num == num)
		{
			cout << "key: " << ptr->num << " owner: " << ptr->str << " hash: " << ptr->hash << endl;
			return;
		}
	}
	cout << "not found\n";
	return;
}