#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//Створення масиву для перевірки на відкритість поля
int** arrcheck(const int length, const int width)
{
    int** check = new int* [length];
    for (int i = 0; i < width; ++i)
        check[i] = new int[width];

    //Заповнення масиву нулями
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            check[i][j] = 0;
    return check;
}

//Функція для перевірки поля
void check_field(int** arr, int** check, int length, int width, bool& checker, bool& win)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (check[i][j] == 0)
            {
                if (arr[i][j] == 9)
                {
                    checker = true;
                    win = true;
                }
                else
                {
                    checker = false;
                    win = false;
                    break;
                }
            }
            else
                checker = true;
        }
        if (!checker)
            break;
    }
}