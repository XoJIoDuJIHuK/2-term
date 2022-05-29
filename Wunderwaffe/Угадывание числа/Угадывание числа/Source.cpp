#include <iostream>
#include <ctime>

void main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "Здравствуйте!" << endl;
switch1: cout << "Введите 1, если хотите начать, и 2, если хотите выйти" << endl;
	int a;
	cin >> a; cout << endl;
	switch (a)
	{
		case 1:
		{
			cout << "Отлично! ";
  TryAgain: cout << "Введите нижнюю границу для загадывания числа ";
			int b;
			cin >> b; printf("\n");
			cout << "Теперь введите верхнюю границу ";
			int c;
			cin >> c; printf("\n");
			if (c >= b)
			{
				srand(time(NULL));
				int random = b + rand() % (c - b + 1);
				cout << "Число загадано. Удачи!" << endl;
				int d;
				while (true)
				{
			  Diap: cout << "Пожалуйста, введите число, которое, как вы думаете, загадала программа "; cin >> d;
					if (d <= c and d >= b)
					{
						if (d == random)
						{
							cout << "Поздравляю! Вы угадали число! ";
				   switch2: cout << "Введите 1, если хотите попробовать ещё раз, и 2, если хотите выйти " << endl;
							cin >> a; cout << endl;
							switch (a)
							{
								case 1:
								{
									goto TryAgain;
								}
								case 2:
								{
									goto GoodBye;
								}
								default:
								{
									cout << "Некорректный ввод" << endl;
									goto switch2;
								}
							}
						}
						else
						{
							cout << "Увы, вы не правы" << endl;
				   switch3: cout << "Введите 1, если хотите продолжить, и 2, если хотите выйти ";
							cin >> a; cout << endl;
							switch (a)
							{
								case 1:
								{
									continue;
								}
								case 2:
								{
									goto GoodBye;
								}
								default:
								{
									cout << "Некорректный ввод";
									goto switch3;
								}
							}
						}
					}
					else
					{
						cout << "Пожалуйста, введите число в том диапазоне, который вы сами задали" << endl;
						goto Diap;
					}
				}
			}
			else
			{
				cout << "В следующий раз вводите числа правильно" << endl;
				goto TryAgain;
			}
		}
		case 2:
		{
   GoodBye: cout << "До свидания!" << endl;
			break;
		}
		default:
		{
			cout << "Некорректный ввод"; cout << endl;
			goto switch1;
		}
	}
}