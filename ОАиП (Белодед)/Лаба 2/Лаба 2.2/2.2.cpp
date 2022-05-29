#include <iostream>
#include <stdio.h>  
int main()
{
	setlocale(LC_ALL, "");
	FILE* mf;
	char str[50];
	errno_t err;
	char* estr;
	printf("Введите текст ");   
	std::cin >> (str);
	fopen_s(&mf, "a.txt", "w");       //Открытие для записи
	fputs(str, mf);
	fputs("\n", mf);
	fclose(mf);
	err = fopen_s(&mf, "a.txt", "r");  //Открытие для чтения
	if (err != NULL)                 //Проверка открытия файла
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
		printf("\nСчитаны строки:\n");
	estr = fgets(str, sizeof(str), mf); //Чтение строки файла      
	if (estr == NULL)         //Конец файла или ошибка чтения?
		if (feof(mf) != 0)
			printf("\nЧтение файла закончено\n");
		else
		{
			printf("\nОшибка чтения из файла\n");
			return -1;
		}
	puts(str);
	if (fclose(mf) == EOF)
		printf("Ошибка закрытия\n");
	return 0;
}
