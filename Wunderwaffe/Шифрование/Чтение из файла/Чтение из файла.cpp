#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    string krypted;
    ifstream in("D:\\_�ר��_\\Wunderwaffe\\����������\\������������� ������.txt"); //�������� �����
    if (in.is_open()) //���� ���� ������
    {
        while (getline(in, krypted)) //������������ ����������� ����� ����������
        {

        }
    }

    char end[30];
    for (unsigned int i = 0; i < krypted.length(); i++)
    {
        int n = (int)krypted[i];
        end[i] = (char)(n - 1); //����������
    }

    ofstream out;          // ����� ��� ������
    out.open("D:\\_�ר��_\\Wunderwaffe\\����������\\�������� ������.txt"); // �������� �����
    if (out.is_open()) //���� ���� ������
    {
        for (int i = 0; i < krypted.length(); i++)
        {
            out << end[i];
        }
    }

    cout << "End of program" << endl;
    return 0;
}