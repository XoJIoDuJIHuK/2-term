#include <fstream>
#include <iostream>
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50];            // ����� ��� �������� ������������ �� ����� ������
    ofstream fout("t.txt");   // �������� ������� fout ������ ofstream ��� ������ 
    fout << "������ � ������� � �++"; // ������ ������ � ����
    fout.close();
    ifstream fin("t.txt");    // �������� ������� fin ������ ifstream ��� ������  
    if (!fin.is_open())
        cout << "���� �� ����� ���� ������!\n";
    else
    {
        fin >> buff;           // ���������� ������� ����� �� �����
        cout << buff << endl;  // ������ �����
        fin.getline(buff, 50); // ���������� ������ �� �����
        fin.close();
        cout << buff << endl;   // ������ ������
    }
}
