#include <iostream>
using namespace std;

class Spisok
{
private:
	struct node
	{
		int elem;
		node* next;
	} *phead;
public:
	Spisok()
	{
		phead = new node;
		phead->next = NULL;
		phead->elem = 0;
	}
	void POSTROENIE()
	{
		node* t;
		int el = 1;
		t = phead;
		(*t).next = NULL;
		while (true)
		{
			cin >> el;
			if (el)
			{
				t->elem = el;
				t->next = new node;
				t = t->next;
			}
			else
			{
				t->elem = 0;
				break;
			}
		}
		return;
	}
	void VYVOD()
	{
		node* t;
		t = phead;
		while (true)
		{
			if (t->elem == 0) break;
			cout << t->elem << endl;
			t = t->next;
		}
		return;
	}
	void OCHISTKA()
	{
		node* t;
		t = phead;
		while (true)
		{
			int elem = t->elem;
			delete t;
			if (elem == 0) break;
			t = t->next;
		}
		return;
	}
};

void main()
{
	setlocale(LC_ALL, "Rus");
	Spisok A;
	A.POSTROENIE();
	A.VYVOD();
	A.OCHISTKA();
}