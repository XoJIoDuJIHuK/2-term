#include <iostream>
#include <Windows.h>
using namespace std;

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int main()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            SetColor(i, j);
            cout << "       Hello!!!!      ";
            SetColor(15, 0);
            cout << "   [" << i << "][" << j << "]\n";
        }
    }
    system("PAUSE");
    return 0;
}