#include <iostream>
#include <string>
using namespace std;

struct student
{
	string fio;
	int num_of_exams = 5;
	int grades[5];
};

void input(student* a, int i)
{
	printf("Input student[%d]\n", i);
	cout << "Enter fio: "; getline(cin, a->fio);
	cout << "Enter 5 grades: ";
	for (int j = 0; j < 5; j++)
	{
		cin >> a->grades[j];
		if (5 >= a->grades[j] >= 0)
		{
			continue;
		}
		else
		{
			cout << "Invalid grade";
			exit(12);
		}
	}
	cout << "End of grades input\n";
	cin.ignore();
	printf("End of input student[%d]\n\n", i);
}

void output(student* a, int i)
{
	printf("Output student[%d]\n", i);
	cout << "fio: " << a->fio << endl;
	cout << "Grades: ";
	for (int j = 0; j < 5; j++)
	{
		cout << a->grades[j] << " ";
	}
	printf("\nEnd of output student[%d]\n\n", i);
}

int great_student_check(student* a, int* ptr_great_students)
{
	for (int j = 0; j < 5; j++)
	{
		if (a->grades[j] < 4)
		{
			return 0;
		}
	}
	*ptr_great_students = *ptr_great_students + 1;
	return 1;
}

void main()
{
	int all_students = 2, great_students = 0;
	float hallmark = 0;
	int* ptr_great_students = &great_students;
	student data[5];
	for (int i = 0; i < 2; i++)
	{
		student* ptr_student = &data[i];
		input(ptr_student, i);
	}
	for (int i = 0; i < 2; i++)
	{
		student* ptr_student = &data[i];
		output(ptr_student, i);
	}
	for (int i = 0; i < 2; i++)
	{
		student* ptr_student = &data[i];
		great_student_check(ptr_student, ptr_great_students);
	}
	hallmark = (float)great_students / (float)all_students;
	cout << hallmark << endl;
}