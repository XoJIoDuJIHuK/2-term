#include <iostream>   
#include <stdio.h>       
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	FILE* fp;
	errno_t err;
	char const* st = "������";
	err = fopen_s(&fp, "a.bin", "w");
	if (err != 0)
	{
		perror("������ �������� a.txt");
		return EXIT_FAILURE;
	}
	fwrite(st, strlen(st), 1, fp);
	printf("������� �������\n");
	fclose(fp);


	char str[50];
	char* estr;
	err = fopen_s(&fp, "a.bin", "r");  //�������� ��� ������
	if (err != NULL)                 //�������� �������� �����
	{
		printf("������ �������� �����\n"); return -1;
	}
	else
		printf("\n������� ������:\n");
	estr = fgets(str, sizeof(str), fp); //������ ������ �����      
	if (estr == NULL)         //����� ����� ��� ������ ������?
		if (feof(fp) != 0)
			printf("\n������ ����� ���������\n");
		else
		{
			printf("\n������ ������ �� �����\n");
			return -1;
		}
	puts(str);
	if (fclose(fp) == EOF)
		printf("������ ��������\n");
	return 0;
}
