#include <iostream>
#include <string>
using namespace std;

struct TRAIN
{
	string dest_point;
	int train_number;
	string depart_time;
};

void input(TRAIN* a, int i)
{
	printf("Input TRAIN[%d]\n", i);
	cout << "Enter dest_point: "; getline(cin, a->dest_point);
	cout << "Enter train_number: "; cin >> a->train_number;
	cout << "Enter depart_time: "; cin >> a->depart_time;
	cout << "End of input\n";
	cin.ignore();
	printf("End of input TRAIN[%d]\n\n", i);
}

void output(TRAIN* a, int i)
{
	printf("Output[%d]\n", i);
	cout << "dest_point: " << a->dest_point << endl;
	cout << "train_number: " << a->train_number << endl;
	cout << "depart_time: " << a->depart_time << endl;
	printf("\nEnd of output[%d]\n\n", i);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	TRAIN data[8];
	for (int i = 0; i < 8; i++)
	{
		TRAIN* ptr_TRAIN = &data[i];
		input(ptr_TRAIN, i);
	}
	//for (int i = 0; i < 2; i++)
	//{
	//	TRAIN* ptr_TRAIN = &data[i];
	//	output(ptr_TRAIN, i);
	//}
	TRAIN buffer;
	while (true)
	{
		int counter = 0;
		for (int i = 0; i < 7; i++)
		{
			TRAIN *ptr_TRAIN = &data[i], *ptr_TRAIN_plus_1 = &data[i + 1];
			if (ptr_TRAIN->dest_point > ptr_TRAIN_plus_1->dest_point)
			{
				buffer = data[i];
				data[i] = data[i + 1];
				data[i + 1] = buffer;
				counter++;
			}
		}
		if (counter == 0)
		{
			cout << "\nSort complete\n";
			break;
		}
	}
	string time;
	cout << "Enter time: "; cin >> time;
	int counter = 0;
	for (int i = 0; i < 8; i++)
	{
		TRAIN* ptr_TRAIN = &data[i];
		if (ptr_TRAIN->depart_time > time)
		{
			output(ptr_TRAIN, i);
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "No trains\n";
	}
}