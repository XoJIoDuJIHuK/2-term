#pragma once 

struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA() {}
};
struct Object
{
	AAA** Data;
	Object(int, int(*)(AAA*));
	int Size;
	int N;
	int(*GetKey)(AAA*);
	bool Insert(AAA*);
	int SearchInd(int key);
	AAA* Search(int key);
	AAA* Delete(int key);
	bool Delete(AAA*);
	void Scan(void(*f)(AAA*));
	double koefzap();
	inline void double_size();
};
static void* DEL = (void*)-1;
Object Create(int size, int(*getkey)(AAA*));

