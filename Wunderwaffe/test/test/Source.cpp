#include <iostream>
#include <string.h>
using namespace std;
void main()
{
    string Numbers[]{ "1", "2", "3" };
    cout << "\nArray of Numbers:" << ::endl;
    for (int i = 0; i < 3; i++)
        cout << Numbers[i] << endl;
}