#include <stdio.h>  
#include <cstdio>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct goods
{
	string good_name;
	int price;
	int amount;
	int percent;
};

void input(goods* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Input goods [%d]\n", i);
	cout << "Enter last name: "; cin >> a->good_name;
	cout << "Enter price: "; cin >> a->price;
	cout << "Enter amount: "; cin >> a->amount;
	cout << "Enter percent: "; cin >> a->percent;
	printf("End of input goods [%d]\n\n", i);
}

void output(goods* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Output goods [%d]\n", i);
	cout << "last name: " << a->good_name << endl;
	cout << "price: " << a->price << endl;
	cout << "amount: " << a->amount << endl;
	cout << "percent: " << a->percent << endl;
	printf("End of output goods [%d]\n\n", i);
}

void write_in_file(goods* a)
{
	setlocale(LC_ALL, "Rus");
	ofstream file_for_write("FILE1.txt", ios_base::app);
	if (file_for_write.is_open())
	{
		file_for_write << a->good_name << " " << a->price << " " << a->amount << " " << a->percent << "\n";
		file_for_write.close();
	}
	else
	{
		cout << "Invalid file\n";
		exit(12);
	}
	file_for_write.close();
}

string read_from_file(int size)
{
	string buffer_line;
	string all_strings[4];
	string words[5][4];
	ifstream file_for_read("FILE1.txt");
	if (!file_for_read.is_open())
	{
		cout << "Invalid file\n";
		exit(3);
	}
	else
	{
		int i = 0;
		while (getline(file_for_read, buffer_line))
		{
			all_strings[i] = buffer_line;
			i++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int k = 0, j = 0; k < 50; k++)
		{
			if ((all_strings[i][k] > 0) && (all_strings[i][k] != ' '))
			{
				words[i][j] += all_strings[i][k];
				if (all_strings[i][k + 1] == ' ')
				{
					j++;
				}
			}
			if (all_strings[i][k + 1] == '\0')
			{
				break;
			}
		}
	}
	file_for_read.close();
	return words[0][0];
}

void main()
{
	int size = 2;
	setlocale(LC_ALL, "Rus");
	goods BSTU[5];
	for (int i = 0; i < size; i++)
	{
		goods* ptr_buffer = &BSTU[i];
		input(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		goods* ptr_buffer = &BSTU[i];
		output(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		goods* ptr_buffer = &BSTU[i];
		write_in_file(ptr_buffer);
	}
	string word = read_from_file(size);
	int a = 0;
	cout << "1 - good_name, 2 - price, 3 - amount, 4 - percent "; cin >> a; cout << endl;
	switch (a)
	{
	case 1:
	{
		string buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			goods* ptr_buffer = &BSTU[i];
			if (ptr_buffer->good_name == buffer)
			{
				output(ptr_buffer, i);
				counter++;
			}
			if (i == size - 1 && counter == 0)
			{
				cout << "None found\n";
			}
		}
		exit(12);
	}
	case 2:
	{
		int buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			goods* ptr_buffer = &BSTU[i];
			if (ptr_buffer->price == buffer)
			{
				output(ptr_buffer, i);
				counter++;
			}
			if (i == size - 1 && counter == 0)
			{
				cout << "None found\n";
			}
		}
		exit(12);
	}
	case 3:
	{
		int buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			goods* ptr_buffer = &BSTU[i];
			if (ptr_buffer->amount == buffer)
			{
				output(ptr_buffer, i);
				counter++;
			}
			if (i == size - 1 && counter == 0)
			{
				cout << "None found\n";
			}
		}
		exit(12);
	}
	case 4:
	{
		int buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			goods* ptr_buffer = &BSTU[i];
			if (ptr_buffer->percent == buffer)
			{
				output(ptr_buffer, i);
				counter++;
			}
			if (i == size - 1 && counter == 0)
			{
				cout << "None found\n";
			}
		}
		exit(12);
	}
	}
}