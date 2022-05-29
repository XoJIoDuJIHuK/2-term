#include <iostream>
#include <fstream>
using namespace std;
double inFile(ifstream& f, char s[]); //������� ������ �� �����
void fromFile(ofstream& f, double a, char s[]); //������� ������ � ����

void main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	char str[40];
	ifstream ifile;
	ofstream ofile;
	cout << "\n ������ ��� ����� ��� ������: \n";
	cin >> str;
	a = inFile(ifile, str);
	cout << "\n ����������� �� ����� ����� = " << a;
	b = pow(a, 2);
	cout << "\n b=" << b;
	cout << "\n ������ ��� ����� ��� ������: \n";
	cin >> str;
	fromFile(ofile, b, str);
	cout << endl;
}
double inFile(ifstream& f, char s[40]) //������� ������ �� �����
{
	double a;
	f.open(s);
	if (f.fail())  //�������� �������� �����
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	f >> a;      //������ ����� �� ����� � ���������� a 
	f.close();
	return a;
}
void fromFile(ofstream& f, double a, char s[40]) //������� ������ � ����
{
	f.open(s);
	if (f.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	f << a;            //������ ����� �� ���������� a � ���� 
	f.close();
}
