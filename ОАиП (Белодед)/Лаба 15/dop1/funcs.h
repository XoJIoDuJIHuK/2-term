#pragma once
#include <iostream>
struct Object
{
	void** Data;
	Object(int, int(*)(void*));
	int Size;
	int N;
	int(*GetKey)(void*);
	bool Insert(void*); 
	int SearchInd(int key);
	void* Search(int key);
	void* Delete(int key);
	bool Delete(void*);
	void Scan(void(*f)(void*));
	double koefzap();
};
static void* DEL = (void*)-1;
Object Create(int size, int(*getkey)(void*));
