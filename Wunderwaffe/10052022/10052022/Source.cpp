#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

struct Uzel  //��� ���� ������.
{
    char Key; //������.
    Uzel* Left;
    Uzel* Right;
};

struct zveno  //��� ����� �����.
{
    Uzel* Element; //������.
    zveno* Sled;
};

class Tree
{
private:
    Uzel* Root; //��������� �� ������ ������.
    zveno* Stack;
    float Operation(char, float, float);
public:
    Tree();
    void Udalenie(Uzel**);
    void V_stack(Uzel*);
    void PrintTree(Uzel*, int); //����� ��p��� �� ��p�� �������
    float Evalbintree(Uzel* T);
    Uzel* GetTree() { return Root; };
};

Tree::Tree()
{
    Stack = NULL;  //������� ��������� ����.
    //��p��p������ ���������� ����� ��p���.
    Root = new (Uzel);
    Root->Right = NULL;
}

void Tree::Udalenie(Uzel** tmp)
{
    zveno* q;

    if (Stack != NULL)
    {
        (*tmp) = Stack->Element; q = Stack;
        Stack = Stack->Sled; delete q;
    }
}

void Tree::V_stack(Uzel* Elem)
{
    zveno* q = new (zveno);

    q->Element = Elem;
    q->Sled = Stack; Stack = q;
}

void Tree::PrintTree(Uzel* w, int l)
//����� ��p��� �� ��p�� �������.
{
    if (w != NULL)
    {
        PrintTree(w->Right, l + 1);
        for (int i = 1; i <= l; i++) cout << "   ";
        cout << w->Key << endl;
        PrintTree(w->Left, l + 1);
    }
}

float Tree::Operation(char Symbol, float Operand_1, float Operand_2)
{
    float temp;

    switch (Symbol)
    {
    case '+': temp = Operand_1 + Operand_2; break;
    case '-': temp = Operand_1 - Operand_2; break;
    case '*': temp = Operand_1 * Operand_2; break;
    case '/': temp = Operand_1 / Operand_2; break;
    case '^': temp = exp(Operand_2 * log(Operand_1));
    }
    return temp;
}

float Tree::Evalbintree(Uzel* T)
{
    float opnd1, opnd2, rez = 0;
    char  symb, tmp[2];

    tmp[1] = '\0';

    if (T != NULL)
    {
        if (strchr("+-*/^", T->Key) != NULL)
        {
            opnd1 = Evalbintree(T->Left);
            opnd2 = Evalbintree(T->Right);
            symb = T->Key;
            rez = Operation(symb, opnd1, opnd2);
        }
        else
        {
            tmp[0] = T->Key;
            rez = atoi(tmp);
        }
        return rez;
    }
}

void main()
{
    setlocale(LC_ALL, "Rus");
    char Formula_Post[30];
    char k; //��������������� ��p�������.
    Uzel* Ukazatel = NULL;

    cout << "������� ��p����, ���������� � ����������� ��p��... \n";
    cin >> Formula_Post;
    //�������� "��p���p���" ����� Formula_Post.
    _strrev(Formula_Post);
    cout << "�p������� � ����p����� ��p���-��p����...\n";

    Tree A;
    Uzel* Temp = A.GetTree(); //������� ���������.
    //��p��p������ ��p��� ������ � ����� ��� �� ��p��.
    for (int i = 0; i < strlen(Formula_Post); i++)
    {
        k = Formula_Post[i];
        //��p������ � ������� ������� k.
        if (strchr("+-*/^", k) != NULL)
        { //������ - ���p����.
            if (Temp->Right == NULL) //����������� �p���� ����.
            {
                //����p��p������ ����� ��� ������������ ����.
                Temp->Right = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Right;
                //������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                //������ �� �p�������� ���� --> ����.
                A.V_stack(Temp);
            }
            else //���� �p���� ����.
            { //����p��p������ ����� ��� ������������ ����.
                Temp->Left = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Left;
                // ������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                //������ �� �p�������� ���� --> ����.
                A.V_stack(Temp);
            }
        }
        else //������ - ���p���.
            if (Temp->Right == NULL) //����������� �p���� ����.
            {
                //����p��p������ ����� ��� ������������ ����.
                Temp->Right = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Right;
                //������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // ������� ��������� "����p�������" �����.
                A.Udalenie(&Ukazatel);
                Temp = Ukazatel;
            }
            else   //���� �p���� ����.
            { //����p��p������ ����� ��� ������������ ����.
                Temp->Left = new (Uzel);
                // ��������� ��������� �� ����������� ����.
                Temp = Temp->Left;
                // ������������� ������������ ����.
                Temp->Key = k;
                Temp->Left = Temp->Right = NULL;
                // ������� ��������� "����p�������" �����.
                A.Udalenie(&Ukazatel);
                Temp = Ukazatel;
            }
    } //����� for.
    cout << "\n����p������ ����� ��p���-��p����...\n";
    A.PrintTree(A.GetTree()->Right, 0);
    cout << "��������� ���������� �������� ��p������...\n";
    cout << A.Evalbintree(A.GetTree()->Right);

    cout << "\n";
    system("PAUSE");
}
