#include <iostream>
#include <string>
#include <bitset>
using namespace std;

union union_states
{
	string state_name;
	string capital;
	int population;
	int size;
	string president;
};

struct state
{
	string state_name;
	string capital;
	int population;
	int size;
	string president;
};

void input(state* a, int i)
{
	printf("Enter state[%d]\n", i);
	cout << "Enter state_name "; cin >> a->state_name;
	cout << "Enter capital "; cin >> a->capital;
	cout << "Enter population "; cin >> a->population;
	cout << "Enter size "; cin >> a->size;
	cout << "Enter president "; cin >> a->president;
}

void output(state* a, int i)
{
	printf("Output of state %d\n", i);
	printf("state_name = "); cout << a->state_name; cout << endl;
	printf("capital = "); cout << a->capital; cout << endl;
	printf("population = %d\n", a->population);
	printf("size = %d\n", a->size);
	printf("president = "); cout << a->president; cout << endl;
}

void func1()
{
	enum facult
	{
		facult_5 = 1, facult_10, facult_15, facult_20, facult_25, facult_30
	} faculties[2];
	facult* ptr_faculties = &faculties[0];
	struct student
	{
		string fio;
		int date;
		string spec;
		string group;
		string facult;
		int grade;
	};
	int size = 2;
	student students[2];
	for (int i = 0; i < size; i++)
	{
		student* ptr_students = &students[i];
		printf("Enter student[%d]\n", i);
		cout << "Enter fio "; cin.ignore(); getline(cin, ptr_students->fio);
		cout << "Enter date "; cin >> ptr_students->date;
		cout << "Enter spec "; cin >> ptr_students->spec;
		cout << "Enter group "; cin >> ptr_students->group;
		int i_facult = 0;
		cout << "Enter facult: 1 to 6 "; cin >> i_facult;
		if (i_facult == 1)
		{
			*(ptr_faculties + i) = facult_5;
		}
		else if (i_facult == 2)
		{
			*(ptr_faculties + i) = facult_10;
		}
		else if (i_facult == 3)
		{
			*(ptr_faculties + i) = facult_15;
		}
		else if (i_facult == 4)
		{
			*(ptr_faculties + i) = facult_20;
		}
		else if (i_facult == 5)
		{
			*(ptr_faculties + i) = facult_25;
		}
		else if (i_facult == 6)
		{
			*(ptr_faculties + i) = facult_30;
		}
		else
		{
			cout << "Invalid spec\n";
			exit(12);
		}
		cout << "Enter grade "; cin >> ptr_students->grade;
	}
	cout << "Enter grade_search ";
	int grade_search;
	cin >> grade_search;
	for (int i = 0; i < size; i++)
	{
		student* ptr_students = &students[i];
		if (ptr_students->grade == grade_search)
		{
			printf("Output of student %d\n", i);
			printf("fio = "); cout << ptr_students->fio; cout << endl;
			bitset<9> bit_date = ptr_students->date;
			printf("date = "); cout << bit_date; cout << endl;
			printf("spec = "); cout << ptr_students->spec; cout << endl;
			printf("group = "); cout << ptr_students->group; cout << endl;
			printf("facult = "); cout << ptr_students->facult; cout << endl;
			printf("grade = "); cout << ptr_students->grade; cout << endl;
		}
	}
	system("pause");
}

void main()
{
	//func1();
	//exit(12);
	int size = 2;
	state states[2];
	for (int i = 0; i < size; i++)
	{
		state* ptr_state = &states[i];
		input(ptr_state, i);
	}
	cout << "Enter state_name_search ";
	string state_name_search;
	cin >> state_name_search;
	for (int i = 0; i < size; i++)
	{
		state* ptr_state = &states[i];
		if (ptr_state->state_name == state_name_search)
		{
			output(ptr_state, i);
		}
	}
	system("pause");
}