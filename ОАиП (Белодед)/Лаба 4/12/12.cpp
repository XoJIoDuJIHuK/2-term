#include <stdio.h>  
#include <cstdio>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct state
{
	string state_name;
	string capital_name;
	int population;
	int size;
	string pres_last_name;
};

void input(state* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Input state %d\n", i);
	cout << "Enter state name: "; cin >> a->state_name;
	cout << "Enter capital name: "; cin >> a->capital_name;
	cout << "Enter population: "; cin >> a->population;
	cout << "Enter size: "; cin >> a->size;
	cout << "Enter president's last name: "; cin >> a->pres_last_name;
	printf("End of input state %d\n\n", i);
}

void output(state* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Output state %d\n", i);
	cout << "last name: " << a->state_name << endl;
	cout << "capital_name: " << a->capital_name << endl;
	cout << "population: " << a->population << endl;
	cout << "size: " << a->size << endl;
	cout << "president's last name: " << a->pres_last_name << endl;
	printf("End of output state %d\n\n", i);
}

void write_in_file(state* a)
{
	setlocale(LC_ALL, "Rus");
	ofstream file_for_write("FILE1.txt", ios_base::app);
	if (file_for_write.is_open())
	{
		file_for_write << a->state_name << " " << a->capital_name << " " << a->population << " " << a->size << " " << a->pres_last_name << "\n";
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
	string words[5][5];
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
	state BSTU[5];
	for (int i = 0; i < size; i++)
	{
		state* ptr_buffer = &BSTU[i];
		input(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		state* ptr_buffer = &BSTU[i];
		output(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		state* ptr_buffer = &BSTU[i];
		write_in_file(ptr_buffer);
	}
	string word = read_from_file(size);
	int a = 0;
	cout << "1 - last name, 2 - exam name, 3 - population, 4 - size, 5 - president's last name "; cin >> a; cout << endl;
	switch (a)
	{
	case 1:
	{
		string buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			state* ptr_buffer = &BSTU[i];
			if (ptr_buffer->state_name == buffer)
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
		string buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			state* ptr_buffer = &BSTU[i];
			if (ptr_buffer->capital_name == buffer)
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
			state* ptr_buffer = &BSTU[i];
			if (ptr_buffer->population == buffer)
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
			state* ptr_buffer = &BSTU[i];
			if (ptr_buffer->size == buffer)
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
	case 5:
	{
		string buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			state* ptr_buffer = &BSTU[i];
			if (ptr_buffer->pres_last_name == buffer)
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