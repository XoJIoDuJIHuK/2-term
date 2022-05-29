#include <iostream>
using namespace std;
const int N = 5;
int a[N];

void f(int k)
{
    int i, j, t, p;
    for (i = 0; i < N - k; i++) 
    {
        if (k < N - 2)
        {
            f(k + 1);
        }
        else 
        { 
            for (p = 0; p < N; p++) cout << " " << a[p];
            cout << endl;
        }
        t = a[k];
        for (j = k + 1; j < N; j++)
        {
            a[j - 1] = a[j];
        }
        a[j - 1] = t;
    }
}

void main()
{
    for (int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    f(0);
}