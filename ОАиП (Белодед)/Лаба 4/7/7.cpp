#include <stdio.h>  
#include <cstdio>  
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct aviation
{
	int number_of_race;
	string final_point;
	string departure_time;
	string departure_date;
	int price;
	int amount_of_places;
};

void input(aviation* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Input aviation %d\n", i);
	cout << "Enter number of race: "; cin >> a->number_of_race;
	cout << "Enter final point: "; cin >> a->final_point;
	cout << "Enter departure_time: "; cin >> a->departure_time;
	cout << "Enter departure_date: "; cin >> a->departure_date;
	cout << "Enter price: "; cin >> a->price;
	cout << "Enter amount of places: "; cin >> a->amount_of_places;
	printf("End of input aviation %d\n\n", i);
}

void output(aviation* a, int i)
{
	setlocale(LC_ALL, "Rus");
	printf("Output aviation %d\n", i);
	cout << "last name: " << a->number_of_race << endl;
	cout << "final_point: " << a->final_point << endl;
	cout << "departure_time: " << a->departure_time << endl;
	cout << "departure_date: " << a->departure_date << endl;
	cout << "price: " << a->price << endl;
	cout << "amount of places : "; cin >> a->amount_of_places;
	printf("End of output aviation %d\n\n", i);
}

void write_in_file(aviation* a)
{
	setlocale(LC_ALL, "Rus");
	ofstream file_for_write("FILE1.txt", ios_base::app);
	if (file_for_write.is_open())
	{
		file_for_write << a->number_of_race << " " << a->final_point << " " << a->departure_time << " " << a->departure_date << " " << a->price << "\n";
		file_for_write.close();
	}
	else
	{
		cout << "Invalid file\n";
		exit(12);
	}
	file_for_write.close();
}

string read_from_file(int departure_date)
{
	string buffer_line;
	string all_strings[4];
	string words[5][6];
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
	for (int i = 0; i < departure_date; i++)
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
	int size = 5;
	setlocale(LC_ALL, "Rus");
	aviation BSTU[5];
	for (int i = 0; i < size; i++)
	{
		aviation* ptr_buffer = &BSTU[i];
		input(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		aviation* ptr_buffer = &BSTU[i];
		output(ptr_buffer, i);
	}
	for (int i = 0; i < size; i++)
	{
		aviation* ptr_buffer = &BSTU[i];
		write_in_file(ptr_buffer);
	}
	string word = read_from_file(size);
	int a = 0;
	cout << "1 - last name, 2 - exam name, 3 - departure_time, 4 - departure_date, 5 - president's last name "; cin >> a; cout << endl;
	switch (a)
	{
	case 1:
	{
		int buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			aviation* ptr_buffer = &BSTU[i];
			if (ptr_buffer->number_of_race == buffer)
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
			aviation* ptr_buffer = &BSTU[i];
			if (ptr_buffer->final_point == buffer)
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
		string buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			aviation* ptr_buffer = &BSTU[i];
			if (ptr_buffer->departure_time == buffer)
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
		string buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			aviation* ptr_buffer = &BSTU[i];
			if (ptr_buffer->departure_date == buffer)
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
		int buffer;
		cout << "Enter value "; cin >> buffer; cout << endl;
		for (int i = 0, counter = 0; i < size; i++)
		{
			aviation* ptr_buffer = &BSTU[i];
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
	}
}