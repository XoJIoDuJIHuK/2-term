#include <iostream>   
#include <fstream>
using namespace std;
void main(void)
{
    setlocale(0, "Rus");
    char const* st = "������";  char* buf;
    ofstream fout("acplus.bin");
    if (fout.fail())
    {
        cout << "\n ������ �������� �����";
        exit(1);
    }
    fout.write((char*)&st, sizeof(st));
    cout << "������� �������\n";
    fout.close();
    ifstream fin("acplus.bin");
    if (fin.fail())
    {
        cout << "\n ������ �������� �����";
        exit(1);
    }
    fin.read((char*)&buf, sizeof(st));
    cout << buf << endl;
    fin.close();
}
