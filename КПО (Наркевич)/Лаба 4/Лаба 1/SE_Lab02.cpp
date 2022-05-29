#include <iostream>
#include <string>
using namespace std;

string str_month;
int prog_day_number = 256;

void prog_day_date(int* mas)
{
	int month = 0, day = 0;
	for (int i = 0, num = prog_day_number; i < 12; i++)
	{
		if (num - mas[i] > 0)
		{
			month = i + 1;
			num -= mas[i];
		}
		else
		{
			day = num;
			break;
		}
	}
	cout << "programmer day date: " << day << '.' << month << endl;
}

string string_month(int i_month)
{
	string mas_of_months[12] = { "January", "February", "March", "April", "May", "June", 
								 "July", "August", "September", "October", "November", "December" };
	return mas_of_months[i_month-1];
}

void inc_input_check(string str, int num_of_days[])
{
	if (str.length() != 8)
	{
		cout << "Invalid length";
		exit(14);
	}
	for (int i = 0; i < 8; i++)
	{
		if ((str[i] < '0') || (str[i] > '9'))
		{
			cout << "Enter only digits";
			exit(15);
		}
	}
	char c_month[2] = { str[2], str[3] };
	int i_month = atoi(c_month);
	if ((i_month == 0) || (i_month > 12))
	{
		cout << "Invalid month\n";
		exit(16);
	}
	cout << string_month(i_month) << endl;
	char c_day[2] = { str[0], str[1] };
	int i_day = atoi(c_day);
	if ((i_day == 0) || (i_day > num_of_days[i_month]))
	{
		cout << "Invalid day\n";
		exit(17);
	}
}

bool def_vis_year(string str)
{
	char c_year[4] = { str[4], str[5], str[6], str[7] };
	int i_year = atoi(c_year);
	if (i_year % 4 == 0)
	{
		if (i_year % 100 == 0)
		{
			if (i_year % 400 == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int num_in_year(string str, int num_of_days[12])
{
	char c_month[2] = { str[2], str[3] };
	int i_month = atoi(c_month);
	char c_day[2] = { str[0], str[1] };
	int i_day = atoi(c_day);
	int num = i_day;
	for (int i = 0; i < i_month; i++)
	{
		num += num_of_days[i];
	}
	return(num);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	bool vis = false;
	string str, birthday;
	int num_of_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Enter your birthday DDMMYYYY ";
	cin >> birthday;
	inc_input_check(birthday, num_of_days);
	cout << "Enter string: ";
	cin >> str;
	cout << endl;
	inc_input_check(str, num_of_days);
	vis = def_vis_year(str);
	if (vis)
	{
		num_of_days[2] += 1;
	}
	prog_day_date(num_of_days);
	int num = num_in_year(str, num_of_days);
	int num_birthday = num_in_year(birthday, num_of_days);
	char month[2] {str[2], str[3]};
	int i_month = atoi(month);
	int distance = abs(num - num_birthday);
	if (distance <= 183)
	{
		printf("Дней до моего дня рождения: %d\n", distance);
	}
	else if ((i_month >= 3) && vis)
	{
		printf("Дней до моего дня рождения: %d\n", 366 - distance);
	}
	else
	{
		printf("Дней до моего дня рождения: %d\n", 365 - distance);
	}
	if (vis == true)
	{
		cout << "Год високосный" << endl;
	}
	else
	{
		cout << "Год невисокосный" << endl;
	}
	cout << "Номер дня в году: " << num << endl;
	system("pause");
}