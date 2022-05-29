//#include "stdafx.h"
#include "List.h"
bool Object::Insert(void* data)           // Вставка в начало
{
	bool rc = 0;
	if (Head == nullptr)
	{
		Head = new Element(nullptr, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(nullptr, data, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(void* data)    // Найти заданный элемент
{
	Element* rc = Head;
	while ((rc != nullptr) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*))     // Вывод
{
	Element* e = Head;
	while (e != nullptr)
	{
		f(e->Data);
		e = e->GetNext();
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // Удалить по ссылке
{
	bool rc = 0;
	if (rc = (e != nullptr))
	{
		if (e->Next != nullptr)
			e->Next->Prev = e->Prev;
		if (e->Prev != nullptr)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(void* data)      // Удалить по значению
{
	return Delete(Search(data));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != nullptr)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}

int Object::CountList()
{
	Element* e = Head;
	int rc = 0;
	while (e != nullptr)
	{
		rc++;
		e = e->GetNext();
	}
	return rc;
}

void Object::DeleteList(int a)
{
	Element* e = Head;
	for (int i = 0; i < a; i++)
	{
		Element* temp = e;
		e = e->GetNext();
		Delete(temp);
	}
}