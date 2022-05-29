#include <iostream>   
#include <stdio.h>       
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	FILE* fp;
	errno_t err;
	char const* st = "привет";
	err = fopen_s(&fp, "a.bin", "w");
	if (err != 0)
	{
		perror("ошибка открытия a.txt");
		return EXIT_FAILURE;
	}
	fwrite(st, strlen(st), 1, fp);
	printf("Записан элемент\n");
	fclose(fp);


	char str[50];
	char* estr;
	err = fopen_s(&fp, "a.bin", "r");  //Открытие для чтения
	if (err != NULL)                 //Проверка открытия файла
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
		printf("\nСчитаны строки:\n");
	estr = fgets(str, sizeof(str), fp); //Чтение строки файла      
	if (estr == NULL)         //Конец файла или ошибка чтения?
		if (feof(fp) != 0)
			printf("\nЧтение файла закончено\n");
		else
		{
			printf("\nОшибка чтения из файла\n");
			return -1;
		}
	puts(str);
	if (fclose(fp) == EOF)
		printf("Ошибка закрытия\n");
	return 0;
}
