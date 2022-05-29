#include <iostream>
#include <string>
using namespace std;

struct tree
{
	int key;
	string data;
	tree* left;
	tree* right;
};

tree* find_by_key(tree* t, int key)
{
	if (t->key == key)
	{
		return t;
	}
	else
	{
		find_by_key(t->left, key);
		find_by_key(t->right, key);
	}
}

void insert(tree* t)
{
	tree* p = new tree;
	cout << "enter key: ";
	int key;
	cin >> key;
	p->key = key;
	cout << "enter string: ";
	string str;
	cin >> str;
	p->data = str;
	p->left = NULL;
	p->right = NULL;
	if (key > t->key)
	{
		t->right = p;
	}
	else if (key < t->key)
	{
		t->left = p;
	}
	else
	{
		cout << "invalid key";
		exit(1);
	}
}

void output_tree(tree* t)
{
	cout << "key: " << t->key << ", string: " << t->data << endl;
	if (t->left)
	{
		output_tree(t->left);
	}
	if (t->right)
	{
		output_tree(t->right);
	}
}

void output_el(tree* t)
{
	cout << "key: " << t->key << ", string: " << t->data << endl;
}

void count_children(tree* t, int* i)
{
	if (t->key == 0)
	{
		if (t->right)
		{
			(*i)++;
			count_children(t->right, i);
		}
	}
	else
	{
		if (t->right)
		{
			(*i)++;
			count_children(t->right, i);
		}
		if (t->left)
		{
			(*i)++;
			count_children(t->left, i);
		}
	}
}

void search_by_key(tree* t, int key)
{
	if (t->key == key)
	{
		output_el(t);
		return;
	}
	else
	{
		if (t->left)
		{
			search_by_key(t->left, key);
		}
		if (t->right)
		{
			search_by_key(t->right, key);
		}
	}
}

void del_el(tree* t)
{
	if (t)
	{
		delete t;
	}
}

void del_tree(tree* t)
{
	if (t)
	{
		if (t->left)
		{
			del_tree(t->left);
		}
		if (t->right)
		{
			del_tree(t->right);
		}
		delete t;
	}
}

void average(tree* t, float* sum, int* i)
{
	if (t)
	{
		(*i)++;
		(*sum) += t->key;
		if (t->left)
		{
			average(t->left, sum, i);
		}
		if (t->right)
		{
			average(t->right, sum, i);
		}
	}
}

void summa(tree* t, int* s)
{
	if (t)
	{
		if (t->key != 0)
		{
			(*s) += t->key;
		}
		if (t->left)
		{
			summa(t->left, s);
		}
		if (t->right)
		{
			summa(t->right, s);
		}
	}
}

void summa_versh(tree* t, int* s)
{
	if (t)
	{
		if ((t->key != 0) && (t->left || t->right))
		{
			(*s) += t->key;
		}
		if (t->left)
		{
			summa_versh(t->left, s);
		}
		if (t->right)
		{
			summa_versh(t->right, s);
		}
	}
}

void main()
{
	tree* root = new tree;
	root->data = "koren";
	root->key = 0;
	root->left = NULL;
	root->right = NULL;
	int i = 0, counter = 0, sum_of_leaves = 0, sum_of_versh = 0;
	float  sum = 0;
	insert(root);
	insert(root->right);
	output_tree(root);
	count_children(root, &i);
	cout << "number of children = " << i << endl;
	average(root, &sum, &counter);
	cout << "average = " << sum / counter << endl;
	summa(root, &sum_of_leaves);
	cout << "sum of leaves = " << sum_of_leaves << endl;
	summa_versh(root, &sum_of_versh);
	cout << "summa vershin = " << sum_of_versh << endl;
}