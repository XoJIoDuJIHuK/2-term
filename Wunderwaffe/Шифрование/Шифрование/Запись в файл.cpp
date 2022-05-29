#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    string source;
    ifstream in("D:\\_УЧЁБА_\\Wunderwaffe\\Шифрование\\Исходные данные.txt"); //открытие файла
    if (in.is_open()) //если файл открыт
    {
        while (getline(in, source)) //присваивание содержимого файла переменной
        {
            
        }
    }
    char krypted[30];

    for (unsigned int i = 0; i < source.length(); i++)
    {
        int n = (int)source[i];
        krypted[i] = (char)(n+1); //шифрование
    }

    ofstream out;          // поток для записи
    out.open("D:\\_УЧЁБА_\\Wunderwaffe\\Шифрование\\Зашифрованные данные.txt"); // открытие файла
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