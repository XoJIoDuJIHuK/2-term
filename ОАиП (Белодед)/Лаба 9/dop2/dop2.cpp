#include <iostream>
#include <string>
using namespace std;

struct Address
{
	string f;
	string i;
	string o;
	int kurs;
	int group;
	int year;
	int grades[5];
	Address* next;
	Address* prev;
};

void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

float av_grade(Address* p)
{
	float a = 0;
	for (int i = 0; i < 5; i++)
	{
		a += p->grades[i];
	}
	return (a / 5);
}

void copy(Address* target, Address* object)
{
	target->f = object->f;
	target->i = object->i;
	target->o = object->o;
	target->kurs = object->kurs;
	target->group = object->group;
	target->year = object->year;
	target->next = object->next;
	target->prev = object->prev;
	for (int i = 0; i < 5; i++)
	{
		target->grades[i] = object->grades[i];
	}
}

void swap_values(Address* target, Address* object)
{
	Address* buffer = new Address;
	buffer->f = object->f;
	buffer->i = object->i;
	buffer->o = object->o;
	buffer->kurs = object->kurs;
	buffer->group = object->group;
	buffer->year = object->year;
	for (int i = 0; i < 5; i++)
	{
		buffer->grades[i] = object->grades[i];
	}

	object->f = target->f;
	object->i = target->i;
	object->o = target->o;
	object->kurs = target->kurs;
	object->group = target->group;
	object->year = target->year;
	for (int i = 0; i < 5; i++)
	{
		object->grades[i] = target->grades[i];
	}

	target->f = buffer->f;
	target->i = buffer->i;
	target->o = buffer->o;
	target->kurs = buffer->kurs;
	target->group = buffer->group;
	target->year = buffer->year;
	for (int i = 0; i < 5; i++)
	{
		target->grades[i] = buffer->grades[i];
	}

	delete buffer;
}

void outputList(Address* phead, Address* plast)      //Вывод списка на экран
{
	Address* t = phead;
	while (t)
	{
		cout << t->f << ' ' << t->i << ' ' << t->o << ' ' << t->kurs << ' ' << t->group << ' ' << t->year << endl;
		t = t->next;
	}
	cout << "" << endl;
}

Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	cout << "Введите фамилию: ";
	cin >> temp->f;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите имя: ";
	cin >> temp->i;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите отчество: ";
	cin >> temp->o;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите курс: ";
	cin >> temp->kurs;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите группу: ";
	cin >> temp->group;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите год: ";
	cin >> temp->year;
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите 5 отметок: \n";
	for (int i = 0; i < 5; i++)
	{
		cin >> temp->grades[i];
	}
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void main(void)
{
	setlocale(LC_ALL, "Rus");
	Address* head = NULL;
	Address* last = NULL;
	int size = 4;
	for (int i = 0; i < size; i++)
	{
		insert(setElement(), &head, &last);
	}
	outputList(head, last);
	Address* head_1_kurs = NULL;
	Address* last_1_kurs = NULL;
	Address* head_2_kurs = NULL;
	Address* last_2_kurs = NULL;
	Address* temp = head;
	for (int i = 0; i < size; i++)
	{
		if (temp->kurs == 1)
		{
			Address* first = new Address;
			copy(first, temp);
			insert(first, &head_1_kurs, &last_1_kurs);
		}
		else if (temp->kurs == 2)
		{
			Address* second = new Address;
			copy(second, temp);
			insert(second, &head_2_kurs, &last_2_kurs);
		}
		temp = temp->next;
	}
	if (head_1_kurs->next)
	{
		swap_values(head_1_kurs, head_1_kurs->next);
	}
	if (head_2_kurs->next)
	{
		swap_values(head_2_kurs, head_2_kurs->next);
	}
	last_1_kurs->next = head_2_kurs;
	head_2_kurs->prev = last_1_kurs;
	outputList(head_1_kurs, last_2_kurs);
	float sum_of_grades_1_group[5] = { 0,0,0,0,0 }, sum_of_grades_2_group[5] = { 0,0,0,0,0 }, min_year = 9999, max_year = 0;
	float av_grade_1_group = 0, av_grade_2_group = 0;
	temp = head;
	Address* youngest = NULL, *oldest = NULL, *best_1_group = NULL, *best_2_group = NULL;
	for (int i = 0; i < size; i++)
	{
		if (temp->group == 1)
		{
			for (int j = 0; j < 5; j++)
			{
				sum_of_grades_1_group[j] += temp->grades[j];
			}
			if (av_grade(temp) > av_grade_1_group)
			{
				best_1_group = temp;
				av_grade_1_group = av_grade(temp);
			}
		}
		if (temp->group == 2)
		{
			for (int j = 0; j < 5; j++)
			{
				sum_of_grades_2_group[j] += temp->grades[j];
			}
			if (av_grade(temp) > av_grade_2_group)
			{
				best_2_group = temp;
				av_grade_2_group = av_grade(temp);
			}
		}
		if (temp->year > max_year)
		{
			youngest = temp;
			max_year = temp->year;
		}
		if (temp->year < min_year)
		{
			oldest = temp;
			min_year = temp->year;
		}
		temp = temp->next;
	}
	cout << "Average grades 1: ";
	for (int i = 0; i < 5; i++)
	{
		cout << sum_of_grades_1_group[i] / 5 << ' ';
	}
	cout << endl;
	cout << "Average grades 2: ";
	for (int i = 0; i < 5; i++)
	{
		cout << sum_of_grades_2_group[i] / 5 << ' ';
	}
	cout << endl;
	Address* t = youngest;
	cout << "Youngest:\n";
	cout << t->f << ' ' << t->i << ' ' << t->o << ' ' << t->kurs << ' ' << t->group << ' ' << t->year << endl;
	cout << "Oldest\n";
	t = oldest;
	cout << t->f << ' ' << t->i << ' ' << t->o << ' ' << t->kurs << ' ' << t->group << ' ' << t->year << endl;
	cout << "Best from 1 group:\n";
	t = best_1_group;
	cout << t->f << ' ' << t->i << ' ' << t->o << ' ' << t->kurs << ' ' << t->group << ' ' << t->year << endl;
	cout << "Best from 2 group:\n";
	t = best_2_group;
	cout << t->f << ' ' << t->i << ' ' << t->o << ' ' << t->kurs << ' ' << t->group << ' ' << t->year << endl;
}