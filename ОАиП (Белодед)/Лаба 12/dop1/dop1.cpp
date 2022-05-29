#include <iostream>
#include <string>
using namespace std;

struct tree
{
	int ph_num = 0;
	string owner = "\0";
	int tarif = 0;
	tree* left = NULL;
	tree* right = NULL;
	int height = 0;
} root = { 123, "qwerty", 1, NULL, NULL };

tree* set_new_element()
{
	tree* temp = new tree;
	cout << "Enter owner: "; cin >> temp->owner;
	cout << "Enter phone number: "; cin >> temp->ph_num;
	cout << "Enter tarif: "; cin >> temp->tarif;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void tarif_count(tree* t, int* mas)
{
	if (t)
	{
		switch (t->tarif)
		{
		case 1:
			(*mas)++;
		case 2:
			(*(mas + 1))++;
		}
		if (t->right)
		{
			tarif_count(t->right, mas);
		}
		if (t->left)
		{
			tarif_count(t->left, mas);
		}
	}
}

void insert(tree* t, tree* p)
{
	if (&root != NULL)
	{
		if (p->ph_num >= t->ph_num && t->right)
		{
			insert(t->right, p);
		}
		else if (p->ph_num >= t->ph_num)
		{
			t->right = p;
		}
		else if (p->ph_num < t->ph_num && t->left)
		{
			insert(t->left, p);
		}
		else if (p->ph_num < t->ph_num)
		{
			t->left = p;
		}
		else
		{
			cout << "Unexpected error\n";
			return;
		}
	}
}

void output(tree* t)
{
	if (t)
	{
		cout << t->owner << ' ' << t->ph_num << ' ' << t->tarif << endl;
		if (t->right)
		{
			output(t->right);
		}
		if (t->left)
		{
			output(t->left);
		}
	}
}

void search(tree* t, int num)
{
	if (t)
	{
		if (t->ph_num == num)
		{
			output(t);
			return;
		}
		else
		{
			if (t->right)
			{
				search(t->right, num);
			}
			if (t->left)
			{
				search(t->left, num);
			}
		}
	}
}

void main()
{
	for (int i = 0; i < 2; i++)
	{
		insert(&root, set_new_element());
	}
	output(&root);
	cout << "Enter phone number: ";
	int a; cin >> a;
	search(&root, a);
	int mas_tarif[2] = { 0, 0 };
	tarif_count(&root, mas_tarif);
	if (mas_tarif[0] > mas_tarif[1])
	{
		cout << "First tarif\n";
	}
	else
	{
		cout << "Second tarif\n";
	}
}