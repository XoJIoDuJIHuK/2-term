#include <iostream>
#include <windows.h>
using namespace std;
#include "stdafx.h"
#include "D:\_УЧЁБА_\Лабораторные работы\КПО (Наркевич)\SE_Lab07\LP_Lab07L\Dictionary.h"
using namespace Dictionary;

#ifdef TEST_CREATE_01
	#define MACROS_ALREADY_EXISTS
#endif

#ifdef TEST_CREATE_02
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_ADD_ENTRY_03)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_ADD_ENTRY_04)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_GET_ENTRY_05)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_GET_ENTRY_06)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_UPD_ENTRY_07)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_UPD_ENTRY_08)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#if !defined(ERROR_MORE_THAN_ONE_MACROS) and defined(TEST_DICTIONARY)
	#ifdef MACROS_ALREADY_EXISTS
		#define ERROR_MORE_THAN_ONE_MACROS
	#else
		#define MACROS_ALREADY_EXISTS
	#endif
#endif

#ifdef ERROR_MORE_THAN_ONE_MACROS
	#error один макрос уже определён
#endif

#ifdef MACROS_ALREADY_EXISTS
	#undef MACROS_ALREADY_EXISTS
#endif

void main()
{
	setlocale(LC_ALL, "rus");
	try
	{
#ifdef TEST_DICTIONARY
		Instance d1 = Create("Teachers", 5);
		d1.is_teacher = 1;
		Entry e1 = { 1, "Teacher1" },
			e2 = { 2, "Teacher2" },
			e3 = { 3, "Teacher3" },
			e4 = { 4, "Teacher4" },
			e5 = { 5, "Teacher5" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		AddEntry(d1, e5);
		Print(d1);
		Entry ex2 = GetEntry(d1, 4);
		cout << "4th teacher's id: " << ex2.id << endl;
		DelEntry(d1, 2);
		cout << "\nDictionary after deleting element with id 2:\n";
		Print(d1);
		Entry newentry1 = { 6, "Teacher6" };
		UpdEntry(d1, 3, newentry1);
		cout << "\nAfter change of element with ID 3: \n";
		Print(d1);
		Instance d2 = Dictionary::Create("Students", 7);
		Entry s1 = { 1, "student1" },
			s2 = { 2, "student2" },
			s3 = { 3, "student3" },
			s4 = { 4, "student4" },
			s5 = { 5, "student5" },
			s6 = { 6, "student6" },
			s7 = { 7, "student7" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		AddEntry(d2, s4);
		AddEntry(d2, s5);
		AddEntry(d2, s6);
		AddEntry(d2, s7);
		Entry newentry3 = { 7, "student8" };
		UpdEntry(d2, 7, newentry3);
		Print(d2);
		cout << "After deleting of the 6th student: " << endl;
		DelEntry(d2, 6);
		Print(d2);
		cout << "Getting number 4: " << endl;
		GetEntry(d2, 4).name;
		Delete(d1);
		Delete(d2);
#endif
#ifdef TEST_CREATE_01
		Instance d1 = Create(TOO_LONG_DICT_NAME, 5);
#endif

#ifdef TEST_CREATE_02
		Instance d1 = Create("Teachers", DICTMAXSIZE + 1);
#endif

#ifdef TEST_ADD_ENTRY_03
		Instance d1 = Create("Teachers", 0);
		Entry e1 = { 1, "Teacher1" };
		AddEntry(d1, e1);
#endif

#ifdef TEST_ADD_ENTRY_04
		Instance d1 = Create("Teachers", 0);
		Entry e1 = { 1, "Teacher1" },
			e2 = { 1, "Teacher2" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
#endif

#ifdef TEST_GET_ENTRY_05
		Instance d1 = Create("Teachers", 1);
		Entry e1 = { 1, "Teacher1" };
		AddEntry(d1, e1);
		GetEntry(d1, 2);
#endif

#ifdef TEST_GET_ENTRY_06
		Instance d1 = Create("Teachers", 1);
		Entry e1 = { 1, "Teacher1" };
		AddEntry(d1, e1);
		DelEntry(d1, 2);
#endif

#ifdef TEST_GET_ENTRY_07
		Instance d1 = Create("Teachers", 1);
		Entry e1 = { 1, "Teacher1" },
			e2 = { 2, "Teacher2" };
		AddEntry(d1, e1);
		UpdEntry(d1, 2, e2);
#endif

#ifdef TEST_GET_ENTRY_08
		Instance d1 = Create("Teachers", 1);
		Entry e1 = { 1, "Teacher1" },
			e2 = { 1, "Teacher2" };
		AddEntry(d1, e1);
		UpdEntry(d1, 1, e2);
#endif
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}