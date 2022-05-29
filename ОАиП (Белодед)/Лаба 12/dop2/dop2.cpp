#include <iostream>
using namespace std;

struct tree
{
	int value;
	tree* left;
	tree* right;
} root = { 0, NULL, NULL };

void output(tree* t)
{
	if (t)
	{
		cout << t->value << endl;
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

tree* set_new_element()
{
	tree* temp = new tree;
	cout << "Enter value: ";
	cin >> temp->value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(tree* t, tree* p)
{
	if (t)
	{
		if (!t->left)
		{
			t->left = p;
			return;
		}
		else if (!t->right)
		{
			t->right = p;
			return;
		}
		else
		{
			insert(t->right, p);
		}
	}
}

void main()
{
	cout << "Enter N: "; int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		insert(&root, set_new_element());
	}
	output(&root);
}