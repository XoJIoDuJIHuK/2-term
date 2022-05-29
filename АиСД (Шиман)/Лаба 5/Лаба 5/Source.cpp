#include <iostream>
#include <string>
using namespace std;

struct stek
{
	char symb = NULL;
	stek* prev = NULL;
} root;
stek* last = &root;

void error()
{
	cout << "skobki rasstavlenbI neverno\n";
	exit(1);
}

void insert(char symb)
{
	stek* t = new stek;
	t->symb = symb;
	t->prev = last;
	last = t;
}

void main()
{
	string str;
	cout << "Enter string: ";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (0x28 <= str[i] <= 0x7D)
		{
			if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
			{
				insert(str[i]);
			}
			else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}')) switch (str[i])
			{
				case ')':
				{
					if (last->symb == '(')
					{
						stek* p = last;
						last = last->prev;
						delete p;
					}
					else error();
					break;
				}
				case ']':
				{
					if (last->symb == '[')
					{
						stek* p = last;
						last = last->prev;
						delete p;
					}
					else error();
					break;
				}
				case '}':
				{
					if (last->symb == '{')
					{
						stek* p = last;
						last = last->prev;
						delete p;
					}
					else error();
					break;
				}
			}
		}
		else
		{
			cout << "Invalid string";
			exit(1);
		}
	}
	cout << "skobki rasstavlenbI verno\n";
	system("pause");
}