#include "funcs.h"

int HashFunction(int key, int size, int p)
{
	return ((int)(key % size + (key % size + 1) * p) % size);
}

int Next_hash(int key, int size, int p)
{
	return ((key % size + (key % size + 1) * p) % size);
}

Object Create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}

Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->Size = size;	
	this->GetKey = getkey;		
	this->Data = new void* [size];
	for (int i = 0; i < size; ++i)	
		Data[i] = NULL;
}

bool Object::Insert(void* d)
{
	bool b = false;
	if (N != Size)
		for (int i = 0, t = GetKey(d), j = HashFunction(t, Size, 0); i != Size * Size && !b; j = Next_hash(j, Size, ++i))
			if (Data[j] == NULL || Data[j] == DEL)
			{
				Data[j] = d;
				N++; 	
				b = true;	
			}
	return b;
}

int Object::SearchInd(int key)
{
	int t = -1;		
	bool b = false;
	if (N != 0) 
		for (int i = 0, j = HashFunction(key, Size, 0); Data[j] != NULL && i != Size * Size && !b; j = HashFunction(key, Size, ++i))
			if (Data[j] != DEL) 
				if (GetKey(Data[j]) == key)
				{
					t = j;
					b = true;
				}
	return t;
}

void* Object::Search(int key) 
{
	int t = SearchInd(key);
	return (t >= 0) ? (Data[t]) : (NULL);
}

void* Object::Delete(int key)
{
	int i = SearchInd(key);
	void* t = Data[i]; 
	if (t != NULL) 
	{
		Data[i] = DEL;
		N--;
	}
	return t;
}

bool Object::Delete(void* d)
{
	return (Delete(GetKey(d)) != NULL);
}

void Object::Scan(void(*f)(void*))
{
	for (int i = 0; i < this->Size; i++)
	{
		std::cout << " Ёлемент " << i << ": ";
		if ((this->Data)[i] == NULL)
			std::cout << " пусто" << std::endl;
		else if ((this->Data)[i] == DEL)
			std::cout << " удален" << std::endl;
		else f((this->Data)[i]);
	}
}


double  Object::koefzap() 
{
	return (double)N / Size;
}
