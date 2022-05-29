#pragma once
#include <string>
#include <iostream>
#define INT_MAX 32767
using namespace std;
struct arr
{
	string str = "\0";
	int num = 0;
	arr* next = NULL;
};
int hash_f(string, int*);
void output(arr*, int);
void input(arr*, int, string, int, int*);
void search(arr*, int, int, int*);
void dlt(arr*, int, int, int*);