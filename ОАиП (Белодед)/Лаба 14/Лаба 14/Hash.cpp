#include "Hash.h"
#include <iostream>

int HashFunction(int key, int size, int p)
{
	bool a = 1;
	if (a)
	{
		return ((key % size + (key % size + 1) * p) % size);
	}
	else
	{
		return ((key + p) % size);
	}
}

Object Create(int size, int(*getkey)(AAA*)) 
{
	return *(new Object(size, getkey));
}

Object::Object(int size, int(*getkey)(AAA*))
{
	N = 0;
	Size = size;
	GetKey = getkey;
	Data = new AAA*[size];
	for (int i = 0; i < size; ++i)
		Data[i] = NULL;
}

bool Object::Insert(AAA* d)
{
	if (N != Size)
		for (int i = 0, t = GetKey(d), j = HashFunction(t, Size, 0); i != Size * Size; j = HashFunction(j, Size, ++i))
			if (Data[j] == NULL || Data[j] == DEL)
			{
				Data[j] = d;
				N++;
				return true;
			}
	return false;
}

int Object::SearchInd(int key)
{
	int t = -1;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, Size, 0); Data[j] != NULL && i != Size; j = HashFunction(key, Size, ++i))
			if (Data[j] != DEL && GetKey(Data[j]) == key)
			{
				t = j;
				break;
			}
	return t;
}

AAA* Object::Search(int key)
{
	int t = SearchInd(key);
	return (t >= 0) ? (Data[t]) : (NULL);
}

AAA* Object::Delete(int key)
{
	int i = SearchInd(key);
	AAA* t = Data[i];
	if (t != NULL)
	{
		Data[i] = (AAA*)DEL;
		N--;
	}
	return t;
}

bool Object::Delete(AAA* d)
{
	return (Delete(GetKey(d)) != NULL);
}

void Object::Scan(void(*f)(AAA*))
{
	for (int i = 0; i < this->Size; i++)
	{
		std::cout << " Ёлемент " << i << ": ";
		if (Data[i] == NULL)
			std::cout << " пусто" << std::endl;
		else if (Data[i] == DEL)

			std::cout << " удален" << std::endl;
		/*else f((this->Data)[i]);*/
		else f(Data[i]);
	}
}

double Object::koefzap()
{
	return (double)N / Size;
}

inline void Object::double_size()
{
	
}