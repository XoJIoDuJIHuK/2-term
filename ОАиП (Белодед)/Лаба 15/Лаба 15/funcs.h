#pragma once
#include <string>
#include <iostream>
using namespace std;
struct arr
{
	int k;
	int hash;
	string str = "\0";
	string num = "\0";
	arr* next = NULL;
};
int hash_f(string, int*);
void output(arr*, int);
void input(arr*, int, string, string, int*);
void search(arr*, int, string, int*);