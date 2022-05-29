#include <stdio.h>  
#include <fstream>
using namespace std;

int main()
{
	int k; FILE* fin;
	fopen_s(&fin, "D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.4\\name1.txt", "rt");
	ofstream fout1("D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.4\\name2.txt");
	ofstream fout2("D:\\_УЧЁБА_\\Лабораторные работы\\ОАиП (Белодед)\\Лаба 3\\Лаба 3.4\\name3.txt");
	printf("Vvedite 4islo k\n");
	scanf_s("%d", &k);
	while (!feof(fin))
	{
		char s[255] = "";
		fgets(s, 254, fin);
		if (strlen(s) <= k)
			fout1 << s;
		else
		{
			for (int i = strlen(s) - k - 1; i < strlen(s); i++)
				fout1 << s[i];
		}
		if (strlen(s) < k)
			fout2 << " " << endl;
		else
			fout2 << s[k - 1] << endl;
	}
	fclose(fin);
	fout1.close();
	fout2.close();
	return 0;
}
