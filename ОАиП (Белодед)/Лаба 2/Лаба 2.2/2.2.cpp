#include <iostream>
#include <stdio.h>  
int main()
{
	setlocale(LC_ALL, "");
	FILE* mf;
	char str[50];
	errno_t err;
	char* estr;
	printf("������� ����� ");   
	std::cin >> (str);
	fopen_s(&mf, "a.txt", "w");       //�������� ��� ������
	fputs(str, mf);
	fputs("\n", mf);
	fclose(mf);
	err = fopen_s(&mf, "a.txt", "r");  //�������� ��� ������
	if (err != NULL)                 //�������� �������� �����
	{
		printf("������ �������� �����\n"); return -1;
	}
	else
		printf("\n������� ������:\n");
	estr = fgets(str, sizeof(str), mf); //������ ������ �����      
	if (estr == NULL)         //����� ����� ��� ������ ������?
		if (feof(mf) != 0)
			printf("\n������ ����� ���������\n");
		else
		{
			printf("\n������ ������ �� �����\n");
			return -1;
		}
	puts(str);
	if (fclose(mf) == EOF)
		printf("������ ��������\n");
	return 0;
}
