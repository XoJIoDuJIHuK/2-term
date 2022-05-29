#include <iostream>
#include <string>
#include <bitset>
using namespace std;

union union_goods
{
	string good_name;
	int price;
	int amount;
	int tax;
};

struct good
{
	string good_name;
	int price;
	int amount;
	int tax;
};

void input(good* a, int i)
{
	printf("Enter good[%d]\n", i);
	cout << "Enter good_name "; cin >> a->good_name;
	cout << "Enter price "; cin >> a->price;
	cout << "Enter amount "; cin >> a->amount;
	cout << "Enter tax: 1 for 5% ... 6 for 30% ";
	int tax_divided = 0;
	cin >> tax_divided;
	if (0 < tax_divided < 7)
	{
		a->tax = tax_divided * 5;
	}
	else
	{
		cout << "Tax error";
		exit(123);
	}
}

void output(good* a, int i)
{
	printf("Output of good %d\n", i);
	printf("good_name = "); cout << a->good_name; cout << endl;
	printf("price = %d\n", a->price);
	printf("amount = %d\n", a->amount);
	printf("tax = %d", a->tax); cout << "%\n";
}

void func1()
{
	enum tax
	{
		tax_5 = 1, tax_10, tax_15, tax_20, tax_25, tax_30
	} taxes[2];
	tax* ptr_taxes = &taxes[0];
	struct good
	{
		string good_name;
		int price;
		int amount;
		int tax;
	};
	int size = 2;
	good goods[2];
	for (int i = 0; i < size; i++)
	{
		good* ptr_goods = &goods[i];
		printf("Enter good[%d]\n", i);
		cout << "Enter name "; cin >> ptr_goods->good_name;
		cout << "Enter price "; cin >> ptr_goods->price;
		cout << "Enter amount "; cin >> ptr_goods->amount;
		int i_tax = 0;
		cout << "Enter tax "; cin >> i_tax;
		if (i_tax == 1)
		{
			*(ptr_taxes + i) = tax_5;
		}
		else if (i_tax == 2)
		{
			*(ptr_taxes + i) = tax_10;
		}
		else if (i_tax == 3)
		{
			*(ptr_taxes + i) = tax_15;
		}
		else if (i_tax == 4)
		{
			*(ptr_taxes + i) = tax_20;
		}
		else if (i_tax == 5)
		{
			*(ptr_taxes + i) = tax_25;
		}
		else if (i_tax == 6)
		{
			*(ptr_taxes + i) = tax_30;
		}
		else
		{
			cout << "Invalid spec\n";
			exit(12);
		}
	}
	cout << "Enter price_search ";
	int price_search;
	cin >> price_search;
	for (int i = 0; i < size; i++)
	{
		good* ptr_goods = &goods[i];
		if (ptr_goods->price == price_search)
		{
			printf("Output of good %d\n", i);
			printf("good_name = "); cout << ptr_goods->good_name; cout << endl;
			printf("price = "); cout << ptr_goods->price; cout << endl;
			printf("amount = "); cout << ptr_goods->amount; cout << endl;
			printf("tax = "); cout << (int)ptr_goods->tax * 5; cout << endl;
		}
	}
	system("pause");
}

void main()
{
	func1();
	exit(12);
	int amount = 2;
	good goods[2];
	for (int i = 0; i < amount; i++)
	{
		good* ptr_good = &goods[i];
		input(ptr_good, i);
	}
	cout << "Enter good_name_search ";
	string good_name_search;
	cin >> good_name_search;
	for (int i = 0; i < amount; i++)
	{
		good* ptr_good = &goods[i];
		if (ptr_good->good_name == good_name_search)
		{
			output(ptr_good, i);
		}
	}
	system("pause");
}