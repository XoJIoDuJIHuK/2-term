#include <iostream>
#include <string>
#include <bitset>
using namespace std;

union union_flights
{
	int number;
	string dest_point;
	string departure_time;
	string departure_date;
	int price;
	int amount;
};

struct flights
{
	int number;
	string dest_point;
	string departure_time;
	string departure_date;
	int price;
	int amount;
};

void input(flights* a, int i)
{
	printf("Enter state[%d]\n", i);
	cout << "Enter number "; cin >> a->number;
	cout << "Enter dest_point "; cin >> a->dest_point;
	cout << "Enter departure_time "; cin >> a->departure_time;
	cout << "Enter departure_date "; cin >> a->departure_date;
	cout << "Enter price "; cin >> a->price;
	cout << "Enter amount "; cin >> a->amount;
}

void output(flights* a, int i)
{
	printf("Output of state %d\n", i);
	printf("number = "); cout << a->number; cout << endl;
	printf("dest_point = "); cout << a->dest_point; cout << endl;
	printf("time = "); cout << a->departure_time; cout << endl;
	printf("date = "); cout << a->departure_date; cout << endl;
	printf("price = "); cout << a->price; cout << endl;
	printf("amount = "); cout << a->amount; cout << endl;
}

void func1()
{
	enum point
	{
		point1 = 1, point2, point3
	} points[2];
	point* ptr_points = &points[0];
	struct flights
	{
		int number;
		int i_dest_point = 0;
		int departure_time;
		int departure_date;
		int price;
		int amount;
	};
	int size = 2;
	flights planes[2];
	for (int i = 0; i < size; i++)
	{
		flights* ptr_flight = &planes[i];
		printf("Enter flight[%d]\n", i);
		cout << "Enter number "; cin >> ptr_flight->number;
		int i_dest_point = 0;
		cout << "Enter dest_point "; cin >> i_dest_point;
		if (i_dest_point == 1)
		{
			*(ptr_points + i) = point1;
		}
		else if (i_dest_point == 2)
		{
			*(ptr_points + i) = point2;;
		}
		else if (i_dest_point == 3)
		{
			*(ptr_points + i) = point3;
		}
		else
		{
			cout << "Invalid spec\n";
			exit(12);
		}
		cout << "Enter departure_time "; cin >> ptr_flight->departure_time;
		cout << "Enter departure_date "; cin >> ptr_flight->departure_date;
		cout << "Enter price "; cin >> ptr_flight->price;
		cout << "Enter amount "; cin >> ptr_flight->amount;
	}
	cout << "Enter departure_date_search ";
	int departure_date_search;
	cin >> departure_date_search;
	for (int i = 0; i < size; i++)
	{
		flights* ptr_flight = &planes[i];
		if (ptr_flight->departure_date == departure_date_search)
		{
			flights* ptr_flight = &planes[i];
			printf("Output of flight %d\n", i);
			printf("number = "); cout << ptr_flight->number; cout << endl;
			printf("dest_point = "); cout << points[i]; cout << endl;
			printf("time = "); cout << ptr_flight->departure_time; cout << endl;
			bitset<9> departure_date = ptr_flight->departure_date;
			printf("date = "); cout << departure_date; cout << endl;
			printf("price = "); cout << ptr_flight->price; cout << endl;
			printf("amount = "); cout << ptr_flight->amount; cout << endl;
		}
	}
	system("pause");
}

void main()
{
	/*func1();
	exit(12);*/
	int size = 2;
	flights planes[2];
	for (int i = 0; i < size; i++)
	{
		flights* ptr_flight = &planes[i];
		input(ptr_flight, i);
	}
	cout << "Enter state_name_search ";
	string dest_point_search;
	cin >> dest_point_search;
	for (int i = 0; i < size; i++)
	{
		flights* ptr_flight = &planes[i];
		if (ptr_flight->dest_point == dest_point_search)
		{
			output(ptr_flight, i);
		}
	}
	system("pause");
}