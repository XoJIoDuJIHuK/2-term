#include <stdio.h>  
#include <cstdio>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct prepod
{
	string last_name;
	string exam_name;
	int day;
	int month;
};

void input(prepod *a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Input prepod BSTU[%d]\n", i);
	cout << "Enter last name: "; cin >> a->last_name;
	cout << "Enter exam_name: "; cin >> a->exam_name;
	cout << "Enter day: "; cin >> a->day;
	cout << "Enter month: "; cin >> a->month;
	printf("End of input prepod BSTU[%d]\n\n", i);
}

void output(prepod* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Output prepod BSTU[%d]\n", i);
	cout << "last name: " << a->last_name << endl;
	cout << "exam_name: " << a->exam_name << endl;
	cout << "day: " << a->day << endl;
	cout << "month: " << a->month << endl;
	printf("End of output prepod BSTU[%d]\n\n", i);
}

void write_in_file(prepod* a)
{
	setlocale(LC_ALL, "Rus");
	ofstream file_for_write("FILE1.txt", ios_base::app);
	if (file_for_write.is_open())
	{
		file_for_write << a->last_name << " " << a->exam_name << " " << a->day << " " << a->month << "\n";
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
	prepod BSTU[5];
	for (int i = 0; i < size; i++)
	{
		prepod* ptr_buffer = &BSTU[i];
		input(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		prepod* ptr_buffer = &BSTU[i];
		output(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		prepod* ptr_buffer = &BSTU[i];
		write_in_file(ptr_buffer);
	}
	string word = read_from_file(size);
	int a = 0;
	cout << "1 - last name, 2 - exam name, 3 - day, 4 - month "; cin >> a; cout << endl;
	switch (a)
	{
		case 1:
		{
			string buffer;
			cout << "Enter value "; cin >> buffer; cout << endl;
			for (int i = 0, counter = 0; i < size; i++)
			{
				prepod* ptr_buffer = &BSTU[i];
				if (ptr_buffer->last_name == buffer)
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
				prepod* ptr_buffer = &BSTU[i];
				if (ptr_buffer->exam_name == buffer)
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
				prepod* ptr_buffer = &BSTU[i];
				if (ptr_buffer->day == buffer)
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
				prepod* ptr_buffer = &BSTU[i];
				if (ptr_buffer->month == buffer)
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