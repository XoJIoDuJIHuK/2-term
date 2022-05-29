#include <iostream>
#include <string>
using namespace std;

char a = 0x62;

string f(string s)
{
	if (a <= 'z')
	{
		s += s;
		s += a;
		a += 1;
		return f(s);
	}
	else return s;
}

string full_string()
{
	char a = 0x62;
	string str = "a";
	//for (int i = 0; i < 26; i++)
	//{
	//	str += str;
	//	str += a;
	//	a += 1;
	//}

	return f(str);
}

void main()
{
	cout << "Enter n: ";
	int n;
	cin >> n;
	string str = full_string();
	cout << str[n] << endl;
}