
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void func1()
{
	int N = 2, K = 4;
	const int n = 5;

	string mass2[n];
	ifstream fs("FILE1.txt");

	if (!fs) {
		cout << "Invalid file";
		exit(14);
	}
	for (int i = 0; i < 5; ++i) {
		if (i == 4) {
			fs >> mass2[i];
			cout << mass2[i];

		}
		else {
			fs >> mass2[i];
			cout << mass2[i];
			cout << endl;
		}
	}
	fs.close();
	ofstream fs2("FILE2.txt");
	if (!fs2) {
		cout << "Invalid file";
		exit(15);
	}
	for (N = N - 1; N <= K - 1; ++N)
	{
		if (N == K - 1) {
			fs2 << mass2[N];

		}
		else {
			fs2 << mass2[N];
			fs2 << endl;
		}
	}
	fs2.close();

	char sogl[] = "qQwWrRtTpPsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM";
	ifstream fin("FILE2.txt");
	char ch;
	int vcount = 0;
	while (fin.get(ch)) if (strchr(sogl, ch)) vcount++;
	cout << "num of soglasnyh " << vcount << endl;
	exit(12);
}

void func2()
{
	string stroka, groups[10];
	cout << "Enter line: ";
	getline(cin, stroka);
	for (int i = 0; i < stroka.length(); i++)
	{
		if (!(((stroka[i] >= '0') && (stroka[i] <= '9')) or stroka[i] == ' '))
		{
			cout << "Invalid characters\n";
			exit(34);
		}
	}
	for (int k = 0, j = 0; k < 50; k++)
	{
		if ((stroka[k] > 0) && (stroka[k] != ' '))
			{
			groups[j] += stroka[k];
			if (stroka[k + 1] == ' ')
			{
				j++;
			}
			}
		if (stroka[k + 1] == '\0')
		{
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (groups[i].length() % 2 == 0)
		{
			cout << groups[i] << endl;
		}
	}
}

int main()
{
    cout << "Enter 1 or 2\n";
    int a;
    cin >> a;
	cin.ignore(cin.rdbuf()->in_avail());
    cout << endl;
	if (a == 1)
	{
		func1();
	}
	else if (a == 2)
	{
		func2();
	}
	else
		return 1;
}