#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    string source;
    ifstream in("D:\\_�ר��_\\Wunderwaffe\\����������\\�������� ������.txt"); //�������� �����
    if (in.is_open()) //���� ���� ������
    {
        while (getline(in, source)) //������������ ����������� ����� ����������
        {
            
        }
    }
    char krypted[30];

    for (unsigned int i = 0; i < source.length(); i++)
    {
        int n = (int)source[i];
        krypted[i] = (char)(n+1); //����������
    }

    ofstream out;          // ����� ��� ������
    out.open("D:\\_�ר��_\\Wunderwaffe\\����������\\������������� ������.txt"); // �������� �����
    if (out.is_open())
    {
        for (int i = 0; i < source.length(); i++)
        {
            out << krypted[i];
        }
    }

    cout << "End of program" << endl;
    return 0;
}