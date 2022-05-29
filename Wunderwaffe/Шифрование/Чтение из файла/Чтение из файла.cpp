#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    string krypted;
    ifstream in("D:\\_УЧЁБА_\\Wunderwaffe\\Шифрование\\Зашифрованные данные.txt"); //открытие файла
    if (in.is_open()) //если файл открыт
    {
        while (getline(in, krypted)) //присваивание содержимого файла переменной
        {

        }
    }

    char end[30];
    for (unsigned int i = 0; i < krypted.length(); i++)
    {
        int n = (int)krypted[i];
        end[i] = (char)(n - 1); //шифрование
    }

    ofstream out;          // поток для записи
    out.open("D:\\_УЧЁБА_\\Wunderwaffe\\Шифрование\\Конечные данные.txt"); // открытие файла
    if (out.is_open()) //если файл открыт
    {
        for (int i = 0; i < krypted.length(); i++)
        {
            out << end[i];
        }
    }

    cout << "End of program" << endl;
    return 0;
}