#include <iostream>
#include <string>
using namespace std;

int max_number_of_steps = 0;
int N, middle, new_N;

int max_steps()
{
    while (new_N != 1)
    {
        cout << new_N << endl;
        if (new_N % 2 == 0)
            new_N = new_N / 2;
        else
            new_N = new_N / 2 + 1;
        max_number_of_steps++;
    }
    return max_number_of_steps++;
}

int main()
{
    system("chcp 1251 > nul");
    int left = 1;
    string answer, question;
    do
    {
        cout << "Введите верхний порог: ";
        cin >> N;
        new_N = N;

        while (N - left)
        {
            int middle = left + (N - left) / 2;
            cout << middle << " - мало / много / угадал" << endl;
            cin >> answer;
            if (answer == "мало")
            {
                left = middle + 1;
            }
            else if (answer == "много")
            {
                N = middle;
            }
            else if (answer == "угадал")
            {
                cout << "Вы загадали число " << middle << endl;
                break;
            }
        }
        cout << "Максимальное количество шагов: " << max_steps() << endl;

        cout << "Хотите сыграть еще? (д или н)?\n";
        cin >> question;
        system("pause");
    } while (question == "Д" || question == "д");
}