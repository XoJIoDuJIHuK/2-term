#include <iostream>
#include <string>
using namespace std;

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
	if ((i_year % 4) == 0)
	{
		return true;
	}
	else
	{
		return false;
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
	int num = num_in_year(str, num_of_days);
	int num_birthday = num_in_year(birthday, num_of_days);
	char march_check[2] {str[2], str[3]};
	int i_march_check = atoi(march_check);
	int distance = abs(num - num_birthday);
	if (distance <= 183)
	{
		printf("Дней до моего дня рождения: %d\n", distance);
	}
	else if ((i_march_check >= 3) && vis)
	{
		//string str_31_12 = str;
		//str_31_12[0] = '3';
		//str_31_12[1] = '1';
		//str_31_12[2] = '1';
		//str_31_12[3] = '2';
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