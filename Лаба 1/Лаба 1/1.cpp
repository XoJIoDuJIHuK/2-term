#include <iostream>
#include <ctime>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void main()
{
    int n, j, end_time, start_time;
    cout << "Enter number ";
    cin >> j; cout << endl;
    start_time = clock();
    n = fib(j);
    end_time = clock();
    cout << "\n" << "Time "<< end_time << "-" <<start_time << " ms\n";
    std::cout <<"Chislo F = " << n << "\t";
}