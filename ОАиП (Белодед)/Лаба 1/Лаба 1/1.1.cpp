#include <iostream>
using namespace std;
int f1(const char* s)
{
	cout << s << " \n����������� ���� �1" << endl;
	return 1;
}
int f2(const char* s)
{
	cout << s << " \n����������� ���� �2" << endl;
	return 2;
}
void callfun(int (*f)(const char*), const char* s)
{
	cout << " f() = " << f(s) << '\n';
}
int main()
{
	setlocale(0, "Rus");
	callfun(f1, "s");
	callfun(f2, "w");
}
