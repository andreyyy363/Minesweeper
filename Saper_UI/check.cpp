
#include "check.h"
#include "libraries.h"
#include "constants_and_variables.h"
#include "field.h"

//Створення масиву для перевірки на відкритість поля
int** Check::arrcheck(parameters & params)
{
    int** check = new int* [params.length];
    for (int i = 0; i < params.length; ++i)
        check[i] = new int[params.width];

    //Заповнення масиву нулями
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
            check[i][j] = 0;

    return check;
}

//Функція для перевірки поля
void Check::check_field(int** arr, int** check, parameters& params, bools& bool_params)
{
    int i, j;
    for (i = 0; i < params.length; i++)
    {
        for (j = 0; j < params.width; j++)
        {
            if (check[i][j] == 0)
            {
                if (arr[i][j] == MINE)
                {
                    bool_params.checker = true;
                    bool_params.win = true;
                }
                else
                {
                    bool_params.checker = false;
                    bool_params.win = false;
                    break;
                }
            }
            else
                bool_params.checker = true;
        }
        if (!bool_params.checker)
            break;
    }
}

