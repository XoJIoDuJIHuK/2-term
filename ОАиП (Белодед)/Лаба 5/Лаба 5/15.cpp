#include <iostream>
#include <bitset>
#include <string>
using namespace std;

enum specs
{
	spec_1 = 1, spec_2, spec_3
} spec[2];

struct vuz
{
	string vuz_name;
	string vuz_adress;
	int study_cost;
	bitset<9> conkurs;
	string spec;
};

void input(vuz *a, int i, specs* ptr_spec)
{
	int i_conkurs = 0;
	int b = 0;
	printf("Enter vuz[%d]\n", i);
	cout << "Enter vuz_name "; cin >> a->vuz_name;
	cout << "Enter vuz_adress "; cin >> a->vuz_adress;
	cout << "Enter study_cost "; cin >> a->study_cost;
	cout << "Enter conkurs "; cin >> i_conkurs; a->conkurs = i_conkurs;
	cout << "Enter 1 for spec_1, 2 for spec_2, 3 for spec_3 "; cin >> b;
	if (b == 1)
	{
		*(ptr_spec + i) = spec_1;
	}
	else if (b == 2)
	{
		*(ptr_spec + i) = spec_2;;
	}
	else if (b == 3)
	{
		*(ptr_spec + i) = spec_3;
	}
	else
	{
		cout << "Invalid spec\n";
		exit(12);
	}
}

void output(vuz* a, int i, specs* ptr_spec)
{
	printf("Output of vuz %d\n", i);
	printf("vuz_name = "); cout << a->vuz_name; cout << endl;
	printf("vuz_adress = "); cout << a->vuz_adress; cout << endl;
	printf("study_cost = %d\n", a->study_cost);
	cout << "conkurs = "; cout << a->conkurs; cout << endl;
	printf("spec = "); cout << *(ptr_spec + i); cout << endl;
}

void func2();

void main()
{
	//func2();
	//exit(1);
	spec[0] = spec_1;
	spec[1] = spec_1;
	specs* ptr_spec = &spec[0];
	int size = 2;
	vuz vuzes[2];
	for (int i = 0; i < size; i++)
	{
		vuz* ptr_vuz = &vuzes[i];
		input(ptr_vuz, i, ptr_spec);
	}
	for (int i = 0; i < size; i++)
	{
		vuz* ptr_vuz = &vuzes[i];
		output(ptr_vuz, i, ptr_spec);
	}
}

void func2()
{
	string vuz_name[2], adress[2], spec[2]; int cost[2] = {0, 0}, conkurs[2] = {0, 0};
	union abitur
	{
		abitur() {}
		~abitur() {}
		string vuz_name;
		string adress;
		string spec;
		int cost = 123;
		int conkurs;
	};
	struct abiturient
	{
		string vuz_name;
		string adress;
		int cost;
		int conkurs;
		string spec;
	} vuz[2];
	abitur uni[2];
	for (int i = 0; i < 2; i++)
	{
		abiturient* ptr_abiturient = &vuz[i];
		cout << "Start abitur #" << i << endl;
		cout << "Enter vuz_name "; cin >> vuz_name[i];
		ptr_abiturient->vuz_name = vuz_name[i];
		cout << "Enter adress "; cin >> adress[i];
		ptr_abiturient->adress = adress[i];
		cout << "Enter spec "; cin >> spec[i];
		ptr_abiturient->spec = spec[i];
		cout << "Enter cost "; cin >> cost[i];
		ptr_abiturient->cost = cost[i];
		cout << "Enter conkurs "; cin >> conkurs[i];
		ptr_abiturient->conkurs = conkurs[i];
		cout << "End" << endl;
	}
	int i_min = 0, conkurs_min = 9999;
	for (int i = 0; i < 2; i++)
	{
		abiturient* ptr_abiturient = &vuz[i];
		if (ptr_abiturient->conkurs < conkurs_min)
		{
			i_min = i;
			conkurs_min = ptr_abiturient->conkurs;
		}
	}
	abiturient* ptr_abiturient = &vuz[i_min];
	cout << "i_min = " << i_min << endl;
	printf("vuz_name = "); cout << ptr_abiturient->vuz_name; cout << endl;
	printf("vuz_adress = "); cout << ptr_abiturient->adress; cout << endl;
	printf("cost = %d\n", ptr_abiturient->cost);
	printf("conkurs = %d\n", ptr_abiturient->conkurs);
	printf("spec = "); cout << ptr_abiturient->spec; cout << endl;
}