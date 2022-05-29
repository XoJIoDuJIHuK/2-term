#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int a; errno_t err;
    FILE* f;
    err = fopen_s(&f, "a.txt", "r");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (a = 0; a < 70; a += 3)
    {
        fprintf(f, "%d, ", a);
    }
    printf("Данные записаны в файл a.txt\n");
    char str[100];
    fscanf(f, "%s", str);
    cout << str << endl;
    fclose(f);
    return 0;
}
