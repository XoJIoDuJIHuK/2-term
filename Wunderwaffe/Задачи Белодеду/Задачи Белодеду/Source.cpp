#include <iostream>
using namespace std;
void main()
{
	static char str1[28] = "String 1";
	static char str2[40] = "String 2";
	const char* str3 = " String 3.";
	strcat_s(str1, str3);
	strcat_s(str2, str1);
	puts(str2);
}