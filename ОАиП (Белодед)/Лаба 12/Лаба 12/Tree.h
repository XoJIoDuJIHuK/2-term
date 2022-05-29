#pragma once
#include <iostream>
namespace btree
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Node
	{
		Node* parent;            // ��������� �� ��������  
		Node* left;              // ��������� �� ����� �����
		Node* right;             // ��������� �� ������ �����
		void* data;              //  ������    
		Node(Node* p, Node* l, Node* r, void* d) // �����������
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}
		Node* next();              // ��������� �� �����
		Node* prev();              // ���������� �� �����
		Node* min();               // ������� � ���������
		Node* max();               // �������� � ���������  
		void scanDown(void(*f)(void* n));    // ����� ��������� ������ ����     
		void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int);
		int getLevel();
		void scanByLevel(void(*f)(void* n));

	};
	struct Object         // ��������� ��������� ������ 
	{
		Node* Root;                    // ��������� �� ������
		CMP(*compare)(void*, void*);   // ������� ���������	
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL;
			compare = f;
		};
		bool isLess(void* x1, void* x2)	const
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2)const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2)const
		{
			return compare(x1, x2) == EQUAL;
		};
		bool insert(void* data);           // �������� �������
		Node* search(void* d, Node* n);    // ����� �������
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);         // ������� �� ������ �������� 
		bool deleteByData(void* data)       // ������� �� �����
		{
			return deleteByNode(search(data));
		};
	};
	Object create(CMP(*f)(void*, void*));      // ������� �������� ������ 
	void walkthrough_r_le_ri(Node* t);
	void walkthrough_le_r_ri(Node* t);
	void walkthrough_le_ri_r(Node* t);
	bool balance(Node* t);
};
