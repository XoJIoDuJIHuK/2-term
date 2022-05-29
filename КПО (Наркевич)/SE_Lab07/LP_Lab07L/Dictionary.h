#pragma once
#include <cstring>

#define DICTNAMEMAXSIZE 20
#define TOO_LONG_DICT_NAME "1234567890_1234567890"
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
//#define TOO_LONG_ENTRY_NAME "1234567890_1234567890_1234567890"
#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02 "Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04 "AddEntry: ������������ ��������������"
#define THROW05 "GetEntry: �� ������ �������"
#define THROW06 "DelEntry: �� ������ �������"
#define THROW07 "UpdEntry: �� ������ �������"
#define THROW08 "UpdEntry: ������������ ��������������"

namespace Dictionary
{
	struct Entry
	{
		int id;     
		char name[ENTRYNAMEMAXSIZE];   
	};
	struct Instance    
	{
		char name[ENTRYNAMEMAXSIZE];     
		int maxsize = DICTMAXSIZE;       
		int size = 0;      
		Entry* dictionary;
		bool is_teacher = 0;
	};
	Instance Create
	(
		const char* name,
		int size
	);
	void AddEntry
	(
		Instance& ints,
		Entry ed
	);
	void DelEntry(
		Instance& inst,
		int id
	);
	void UpdEntry
	(
		Instance& ints,
		int id,
		Entry new_ed
	);
	Entry GetEntry(
		Instance& inst,
		int id
	);
	void Print(Instance& d);
	void Delete(Instance& d);
};