#include <iostream>
#include <Windows.h>
#include <conio.h>

#define OX 200 //задание размеров поля
#define OY 50  

int main()
{
    char scene[OX][OY * 2]; //определение двумерного массива

    for (int x = 0; x < OX; x++) { 
        for (int y = 0; y < OY * 2; y++)
        {
            scene[x][y] = ' ';
            if (y % 5 == 0)
            {
                scene[x][y] = '-';
            }
            if (x % 5 == 0)
            {
                scene[x][y] = '|';
            }
            if (x % 5 == 0 and y % 5 == 0)
            {
                scene[x][y] = '+';
            }
        }
    }

    for (int x = 0; x < OX; x++) {
        double y = 2 * x; 
      if (abs(y) < OY) //проверка на нахождение точки внутри поля
          scene[x][(int)round(y - OY)] = '*';

    }
    for (int x = 0; x < OX; x++) {
        double y = x * x;
        if (abs(y) < OY)
            scene[x][(int)round(y - OY)] = '*';

    }
    for (int x = 0; x < OX; x++) {
        double y = x / 2;
        if (abs(y) < OY)
            scene[x][(int)round(y - OY)] = '*';

    }
    for (int x = 0; x < OX; x++) {
        double y = x;
        if (abs(y) < OY)
            scene[x][(int)round(y - OY)] = '*';

    }
    for (int x = 0; x < OX; x++) {
        double y = sin(x);
        if (abs(y) < OY)
            scene[x][(int)round(y - OY)] = '*';

    }

    for (int y = OY * 2 - 1; y >= 0; y--) {
     printf("%03d ", y - OY); //вывод значений игрека слева от оси ординат
      for (int x = 0; x < OX; x++) {
         printf("%c", scene[x][y]);
        }
       printf("\n");
    }
    return 0;
}