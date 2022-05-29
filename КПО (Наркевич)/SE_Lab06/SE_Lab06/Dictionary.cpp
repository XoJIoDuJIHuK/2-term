#include "Dictionary.h"
#include <iostream>
#include "stdafx.h"

using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int size)
{
	Instance NewDict;
	if (strlen(name) > DICTNAMEMAXSIZE) throw THROW01;
	if (size > DICTMAXSIZE)	throw THROW02;
	strcpy_s(NewDict.name, name);
	NewDict.maxsize = size;
	NewDict.dictionary = new Entry[size];
	return NewDict;
}

void Dictionary::AddEntry(Instance& inst, Entry ed)
{
	if (inst.size >= inst.maxsize) throw  THROW03;
	for (int i = 0; i < inst.size + 1; i++)
	{
		if (inst.dictionary[i].id == ed.id) throw THROW04;
	}
	inst.dictionary[inst.size] = ed;
	inst.size++;
}

void  Dictionary::DelEntry(Instance& inst, int id) {
	for (int i = 1; i <= inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.size; j++)
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.size--;
			return;
		}
	}
	throw THROW05;
}

Entry Dictionary::GetEntry(Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			std::cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}
	throw THROW05;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed)  
{
	for (int i = 0; i < inst.size; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (int j = 0; j < inst.size; j++)
			{
				if ((j != i) && (new_ed.id == inst.dictionary[j].id)) throw THROW08;
			}
			inst.dictionary[i].id = new_ed.id;
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			return;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08;
	}
	throw THROW07;
}

void Dictionary::Print(Instance& d)
{
	if (d.is_teacher)
	{
		std::cout << "----------Teachers----------\n";
	}
	else
	{
		std::cout << "----------Students----------\n";
	}
	for (int i = 0; i < d.size; i++)
	{
		std::cout << "" << d.dictionary[i].id << ' ' << d.dictionary[i].name << endl;
	}
}

void Dictionary::Delete(Instance &inst)
{
	delete inst.dictionary;
}