#include <iostream>
using namespace std;

void func()
{
	cout << "123" << endl;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	bool tr = true, fl = false;
	char letter_en = 'a'; //������ 'a' � ������� Windows-1251 ��������� �� ����������� 6 ������ � 1 �������
	char letter_ru = '�';//������ '�' � ������� Windows-1251 ��������� �� ����������� 14 ������ � 14 �������
	char *ptr_char = &letter_en;
	wchar_t w_letter_en = L'T';//������ 'T' � ������� Unicode ��������� �� ����������� 5 ������ � 4 �������
	wchar_t w_letter_ru = L'�';//������ '�' � ������� Unicode ��������� �� ����������� 42 ������ � 2 �������
	wchar_t *ptr_wchar_t = &w_letter_en;
	short iks = 0x18; //0000 0000 0001 1000
	short minus_iks = 0xffe8;//1111 1111 1110 1000
	short *ptr_short = &iks;
	short short_min = 0x8000;//������������� ����� ����� 32768, ����������� - -32768, �.�. 1000 0000 0000 0000
	short short_max = 0x7fff;//��������������� ����� ����� 32768, ������, ������������ ����� - 32767, �.�. 0111 1111 1111 1111
	unsigned short us_min = 0x0000; //����������� ����� - 0
	unsigned short us_max = 0xffff;//������������ ����� - 65535, �.�. 1111 1111 1111 1111
	int Y = 0x19;//0000 0000 0000 0000 0000 0000 0001 1001
	int minus_Y = 0xffffffe7;//1111 1111 1111 1111 1111 1111 1110 0111
	int *ptr_int = &Y;
	int i_min = 0x80000000;//����������� ����� - -2147483648, �.�. 1000 0000 0000 0000 0000 0000 0000 0000
	int i_max = 0x7fffffff;//������������ ����� - 2147483647, �.�. 0111 1111 1111 1111 1111 1111 1111 1111
	unsigned int ui_min = 0x0;//����������� ����� - 0
	unsigned int ui_max = 0xffffffff;//������������ ����� - 4294967295, �.�. 1111 1111 1111 1111 1111 1111 1111 1111
	long Z = 0x1A;//0000 0000 0000 0000 0000 0000 0001 1010
	long minus_Z = 0xffffffe6;//1111 1111 1111 1111 1111 1111 1110 0110
	long l_min = 0x80000000;//����������� ����� - -2147483648, �.�. 1000 0000 0000 0000 0000 0000 0000 0000
	long l_max = 0x7fffffff;//������������ ����� - 2147483647, �.�. 0111 1111 1111 1111 1111 1111 1111 1111
	unsigned long ul_min = 0x0;//����������� ����� - 0, �.�. 0000 0000 0000 0000 0000 0000 0000 0000
	unsigned long ul_max = 0xffffffff;//������������ ����� - 4294967295, �.�. 1111 1111 1111 1111 1111 1111 1111 1111
	float S = 16;
	float minus_S = -16;
	float *ptr_float = &S;
	int i_S = 16;
	double zero = 0.0;
	double *ptr_double = &zero;
	double divbyzero = 1.0 / zero;
	cout << "inf = " << divbyzero << endl;
	divbyzero *= -1;
	cout << "-inf = " << divbyzero << endl;
	double a = 0.0;
	double b = 0.0 / a;
	double negative_sqrt = sqrt(-1);
	cout << "0.0/0.0 = " << b << endl;
	cout << "sqrt(-1) = " << negative_sqrt << endl;
	cout << "*ptr_char = " << *ptr_char << endl;
	cout << "*ptr_char + 3 = " << *(ptr_char + 3) << endl;
	void (*ptr_void)();
	ptr_void = func;
	ptr_void();
}