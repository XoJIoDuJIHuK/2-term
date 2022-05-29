//#include "stdafx.h"
#include "Tree.h"
#include <fstream>
using namespace std;
struct NodeTree
{
	int  key;
};
//-------------------------------
btree::CMP cmpfnc(void* x, void* y)    // ���������
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key < ((NodeTree*)y)->key)
		rc = btree::LESS;
	else
		if (((NodeTree*)x)->key > ((NodeTree*)y)->key)
			rc = btree::GREAT;
	return rc;
}
//-------------------------------
void printNode(void* x)               // ����� ��� ������
{
	cout << ((NodeTree*)x)->key << ends;
}
//-------------------------------
bool buildTree(const char* FileName, btree::Object& tree) //���������� ������ �� �����
{
	bool rc = true;
	FILE* inFile;
	fopen_s(&inFile, FileName, "r");
	if (inFile == NULL)
	{
		cout << "������ �������� �������� �����" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // ���������� ������ 
	{
		int num;
		fscanf_s(inFile, "%d", &num, 1);
		NodeTree* a = new NodeTree();
		a->key = num;
		tree.insert(a);
	}
	fclose(inFile);
	return rc;
}
FILE* outFile;
//-------------------------------
void saveToFile(void* x)              // ������ ������ �������� � ����
{
	NodeTree* a = (NodeTree*)x;
	int q = a->key;
	fprintf(outFile, "%d\n", q);
}
//-------------------------------
void saveTree(btree::Object& tree, const char* FileName)    //���������� ������ � ���� 
{
	fopen_s(&outFile, FileName, "w");
	if (outFile == NULL)
	{
		cout << "������ �������� ��������� �����" << endl;
		return;
	}
	tree.Root->scanDown(saveToFile);
	fclose(outFile);
}
//-------------------------------
int /*_tmain(int argc, _TCHAR* argv[])*/main()
{
	setlocale(LC_CTYPE, "Russian");
	btree::Object demoTree = btree::create(cmpfnc);
	int k, choice;
	NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 6 };
	bool rc = demoTree.insert(&a4);   //           4  
	rc = demoTree.insert(&a1);        //   1             
	rc = demoTree.insert(&a6);        //                   6
	rc = demoTree.insert(&a2);        //      2     
	rc = demoTree.insert(&a3);        //         3
	rc = demoTree.insert(&a5);        //                 5	
	for (;;)
	{
		NodeTree* a = new NodeTree;
		cout << "1 - ����� ������ �� �����" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ��������� � ����" << endl;
		cout << "5 - ��������� �� �����" << endl;
		cout << "6 - �������� ������" << endl;
		cout << "7 - ������ ��������������?" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choice;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:  	if (demoTree.Root)
			demoTree.Root->scanByLevel(printNode);
			  else
			cout << "������ ������" << endl;
			break;
		case 2: 	cout << "������� ����" << endl;  cin >> k;
			a->key = k;
			demoTree.insert(a);
			break;
		case 3:  	cout << "������� ����" << endl;  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
		case 4:   	saveTree(demoTree, "G.txt");
			break;
		case 5:  	buildTree("G.txt", demoTree);
			break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;
		case 7:
		{
			btree::Node* a = demoTree.Root;
			if (balance(a))
			{
				cout << "Tree balanced\n";
			}
			else
			{
				cout << "Tree unbalanced\n";
			}
		}
		}
	}
	return 0;
}