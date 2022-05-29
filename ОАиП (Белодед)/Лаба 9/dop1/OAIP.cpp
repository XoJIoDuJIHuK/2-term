//#include "stdafx.h"
#include "List.h"
#include <iostream>
using namespace std;

struct Person
{
	char name[20];
	int age;
	Person* next;
};

void print(void* b)       //������� ������������ ��� ������ 
{
	Person* a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}

int main(/*int argc, _TCHAR* argv[]*/)
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { "������", 20 };
	Person a2 = { "�������", 25 };
	Person a3 = { "��������", 47 };
	bool rc;
	Object L1 = Create();   // �������� ������ � ������ L1
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	L1.PrintList(print);
	Element* e = L1.Search(&a3);
	Person* aa = (Person*)e->Data;
	cout << "������ �������= " << aa->name << endl;
	rc = L1.Delete(&a2);
	if (rc == true) cout << "������ �������" << endl;
	cout << "������:" << endl;
	L1.PrintList(print);
	int a = L1.CountList();
	cout << "�����: " << a << endl;
	L1.DeleteList(a);
	cout << "before list wipe\n";
	L1.PrintList(print);
	cout << "after list wipe\n";
	return 0;
}
