#pragma once
#include <string>
#include <iostream>
using namespace std;
struct arr
{
	string str = "\0";
	arr* next = NULL;
};
int hash_f(string, int*);
void output(arr*, int);
void input(arr*, int, string, int*);
void search(arr*, int, string, int*);
void delete_by_char(arr*, int, string, int*);
static void* DEL = (void*)-1;
