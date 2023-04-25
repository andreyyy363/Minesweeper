#include "libraries.h"
#include "constants_and_variables.h"
#include "field.h"
#include "check_array.h"

//��������� ������ ��� �������� �� ��������� ����
int** Check::arrcheck(parameters & params)
{
    int** check = new int* [params.length];
    for (int i = 0; i < params.length; ++i)
        check[i] = new int[params.width];

    //���������� ������ ������
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
            check[i][j] = 0;
    return check;
}

//������� ��� �������� ����
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