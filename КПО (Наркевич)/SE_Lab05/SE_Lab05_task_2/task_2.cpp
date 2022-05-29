#include <iostream>
#include <string>
using namespace std;

enum form_of_exam { Экзамен = 1, Зачёт };

typedef string discipline;
typedef int grade;

struct control
{
	discipline disc;
	form_of_exam form;
	grade max_grade;
} control1 = {"OAiP", Экзамен, 9}, control2 = {"KSiS", Зачёт, 8}, control3 = {"KPO", Экзамен, 7};

bool operator==(control& a, control& b)
{
	if ((a.disc != b.disc) || (a.form != b.form) || (a.max_grade != b.max_grade))
	{
		return false;
	}
	else
	{
		return true;
	}
}

control operator+(control& a, int b)
{
	a.max_grade += b;
	return a;
}

void output(control& a)
{
	cout << a.disc << ' ';
	if (a.form == 1)
	{
		cout << "Экзамен ";
	}
	else if (a.form == 2)
	{
		cout << "Зачёт ";
	}
	cout << a.max_grade << endl;
}

void main()
{
	output(control1);
	control1 = control1 + 1;
	output(control1);
	cout << "control2 == control3? ";
	if (control2 == control3)
	{
		cout << "да\n";
	}
	else
	{
		cout << "нет\n";
	}
}