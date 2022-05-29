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
	char letter_en = 'a'; //символ 'a' в таблице Windows-1251 находится на пересечении 6 строки и 1 столбца
	char letter_ru = 'о';//символ 'о' в таблице Windows-1251 находится на пересечении 14 строки и 14 столбца
	char *ptr_char = &letter_en;
	wchar_t w_letter_en = L'T';//символ 'T' в таблице Unicode находится на пересечении 5 строки и 4 столбца
	wchar_t w_letter_ru = L'Т';//символ 'Т' в таблице Unicode находится на пересечении 42 строки и 2 столбца
	wchar_t *ptr_wchar_t = &w_letter_en;
	short iks = 0x18; //0000 0000 0001 1000
	short minus_iks = 0xffe8;//1111 1111 1110 1000
	short *ptr_short = &iks;
	short short_min = 0x8000;//отрицательных чисел всего 32768, минимальное - -32768, т.е. 1000 0000 0000 0000
	short short_max = 0x7fff;//неотрицательных чисел всего 32768, значит, максимальное число - 32767, т.е. 0111 1111 1111 1111
	unsigned short us_min = 0x0000; //минимальное число - 0
	unsigned short us_max = 0xffff;//максимальное число - 65535, т.е. 1111 1111 1111 1111
	int Y = 0x19;//0000 0000 0000 0000 0000 0000 0001 1001
	int minus_Y = 0xffffffe7;//1111 1111 1111 1111 1111 1111 1110 0111
	int *ptr_int = &Y;
	int i_min = 0x80000000;//минимальное число - -2147483648, т.е. 1000 0000 0000 0000 0000 0000 0000 0000
	int i_max = 0x7fffffff;//максимальное число - 2147483647, т.е. 0111 1111 1111 1111 1111 1111 1111 1111
	unsigned int ui_min = 0x0;//минимальное число - 0
	unsigned int ui_max = 0xffffffff;//максимальное число - 4294967295, т.е. 1111 1111 1111 1111 1111 1111 1111 1111
	long Z = 0x1A;//0000 0000 0000 0000 0000 0000 0001 1010
	long minus_Z = 0xffffffe6;//1111 1111 1111 1111 1111 1111 1110 0110
	long l_min = 0x80000000;//минимальное число - -2147483648, т.е. 1000 0000 0000 0000 0000 0000 0000 0000
	long l_max = 0x7fffffff;//максимальное число - 2147483647, т.е. 0111 1111 1111 1111 1111 1111 1111 1111
	unsigned long ul_min = 0x0;//минимальное число - 0, т.е. 0000 0000 0000 0000 0000 0000 0000 0000
	unsigned long ul_max = 0xffffffff;//максимальное число - 4294967295, т.е. 1111 1111 1111 1111 1111 1111 1111 1111
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