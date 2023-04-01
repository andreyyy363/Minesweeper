#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//Функція створення поля для гри

int** create_field(const int length, const int width, int mine_number, int lenght_x_width)
{
    //Створення масиву для поля
    int** arr = new int* [length];
    for (int i = 0; i < length; ++i)
        arr[i] = new int[width];

    //Заповнення масиву від 1 до n
    int numb = 0;
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
        {
            numb++;
            arr[i][j] = numb;
        }

    //Генерація чисел, які будуть мінами
    int i, j;
    int* mines = new int[mine_number];
    srand((unsigned)time(NULL));

    for (i = 0; i < mine_number; i++)
    {
        mines[i] = rand() % lenght_x_width + 1;
    }

    //Якщо номери сгенерованих мін повторюються
    int n = 0;
    for (j = 0; j < mine_number - 1; j++)
    {
        n++;
        for (i = n; i < mine_number - 1; i++)
            if (mines[j] == mines[i])
                mines[j] = rand() % lenght_x_width + 1;
    }

    //Заміна номерів на 9 (*)
    for (int k = 0; k < mine_number - 1; k++)
    {
        for (i = 0; i < length; i++)
        {
            for (j = 0; j < width; j++)
            {
                if (arr[i][j] == mines[k])
                {
                    arr[i][j] = MINE;
                }
            }
        }
    }

    //Заміна номерів на 0 (.)
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (arr[i][j] != MINE)
                arr[i][j] = NOTHING;
        }
    }
    delete[] mines;
    //Розміщення чисел, які позначають міни поблизу
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (arr[i][j] != 9)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                    if (arr[i - 1][j - 1] == 9)
                        arr[i][j] += 1;

                if (i - 1 >= 0)
                    if (arr[i - 1][j] == 9)
                        arr[i][j] += 1;

                if (i - 1 >= 0 && j + 1 < width)
                    if (arr[i - 1][j + 1] == 9)
                        arr[i][j] += 1;

                if (j - 1 >= 0)
                    if (arr[i][j - 1] == 9)
                        arr[i][j] += 1;

                if (j + 1 < width)
                    if (arr[i][j + 1] == 9)
                        arr[i][j] += 1;

                if (i + 1 < length && j - 1 >= 0)
                    if (arr[i + 1][j - 1] == 9)
                        arr[i][j] += 1;

                if (i + 1 < length)
                    if (arr[i + 1][j] == 9)
                        arr[i][j] += 1;

                if (i + 1 < length && j + 1 < width)
                    if (arr[i + 1][j + 1] == 9)
                        arr[i][j] += 1;
            }
        }
    }
    return arr;
}