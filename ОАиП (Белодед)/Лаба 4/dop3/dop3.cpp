#include <iostream>
#include <string>
using namespace std;

struct sanat
{
	string name;
	string place;
	bool profile;
	int amount;
};

void input(sanat* a, int i)
{
	printf("Input sanat[%d]\n", i);
	cout << "Enter name: "; getline(cin, a->name);	
	cout << "Enter place: "; getline(cin, a->place);	
	cout << "Enter profile: "; cin >> a->profile;
	cout << "Enter amount: "; cin >> a->amount;
	cin.ignore();
	printf("End of input sanat[%d]\n\n", i);
}

void output(sanat* a, int i)
{
	printf("Output sanat[%d]\n", i);
	cout << "name: " << a->name << endl;
	cout << "place: " << a->place << endl;
	cout << "profile: " << a->profile << endl;
	cout << "amount: " << a->amount << endl;
	printf("\End of output sanat[%d]\n\n", i);
}

void main()
{
	sanat data[4]/* = {{"q", "w", 1, 10}, {"e", "r", 0, 20}, {"t", "y", 1, 30}, {"u", "i", 0, 40} }*/, profile_1[4], profile_2[4], buffer;
	for (int i = 0; i < 4; i++)
	{
		sanat* ptr = &data[i];
		input(ptr, i);
	}
	int pro_1 = 0, pro_2 = 0;
	for (int i = 0; i < 4; i++)
	{
		sanat* ptr = &data[i];
		if (ptr->profile == true)
		{
			profile_1[pro_1] = data[i];
			pro_1++;
		}
		else
		{
			profile_2[pro_2] = data[i];
			pro_2++;
		}
	}

	sanat* ptr = &profile_1[0], *ptr_plus = &profile_1[1];
	if (ptr->name > ptr_plus->name)
	{
		buffer = profile_1[0];
		profile_1[0] = profile_1[1];
		profile_1[1] = buffer;
	}
	ptr = &profile_2[0], ptr_plus = &profile_2[1];
	if (ptr->name > ptr_plus->name)
	{
		buffer = profile_2[0];
		profile_2[0] = profile_2[1];
		profile_2[1] = buffer;
	}

	cout << "   name: ";
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr = &profile_1[i];
		cout << ptr->name << "  ";
	}
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr_2 = &profile_2[i];
		cout << ptr_2->name << "  ";
	}
	cout << endl;

	cout << "  place: ";
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr = &profile_1[i];
		cout << ptr->place << "  ";
	}
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr_2 = &profile_2[i];
		cout << ptr_2->place << "  ";
	}
	cout << endl;

	cout << "profile: ";
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr = &profile_1[i];
		cout << ptr->profile << "  ";
	}
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr_2 = &profile_2[i];
		cout << ptr_2->profile << "  ";
	}
	cout << endl;

	cout << " amount: ";
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr = &profile_1[i];
		cout << ptr->amount << " ";
	}
	for (int i = 0; i < 2; i++)
	{
		sanat* ptr_2 = &profile_2[i];
		cout << ptr_2->amount << " ";
	}
	cout << endl;
}