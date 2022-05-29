#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date
{
	day dd;
	month mm;
	year yyyy;
} date1 = {1,2,1999}, date2 = {2,2,2000}, date3 = {1,2,1999};

bool operator==(Date& a, Date& b)
{
	if ( (a.yyyy != b.yyyy) || (a.mm != b.mm) || (a.dd != b.dd) )
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator<(Date& a, Date& b)
{
	if (a.yyyy < b.yyyy)
	{
		return true;
	}
	else if (a.yyyy > b.yyyy)
	{
		return false;
	}
	else
	{
		if (a.mm < b.mm)
		{
			return true;
		}
		else if (a.mm > b.mm)
		{
			return false;
		}
		else
		{
			if (a.dd < b.dd)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool operator>(Date& a, Date& b)
{
	if (a.yyyy > b.yyyy)
	{
		return true;
	}
	else if (a.yyyy < b.yyyy)
	{
		return false;
	}
	else
	{
		if (a.mm > b.mm)
		{
			return true;
		}
		else if (a.mm < b.mm)
		{
			return false;
		}
		else
		{
			if (a.dd > b.dd)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void main()
{
	cout << "date1 < date2? ";
	if (date1 < date2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	cout << "date1 > date2? ";
	if (date1 > date2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	cout << "date1 == date2? ";
	if (date1 == date2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	cout << "date1 == date3? ";
	if (date1 == date3)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
}