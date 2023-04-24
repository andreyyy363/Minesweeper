#include "libraries.h"
#include "print_functions.h"
#include "constants_and_variables.h"
#include "field.h"

int** Field::create_array(parameters& params)
{
    //Створення масиву для поля
    int** arr = new int* [params.length];
    for (int i = 0; i < params.length; ++i)
        arr[i] = new int[params.width];
    return arr;
}

int** Field::assign_array(int** arr, parameters& params)
{
    //Заповнення масиву від 1 до n
    int numb = 0;
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
        {
            numb++;
            arr[i][j] = numb;
        }
    return arr;
}

int* Field::define_mines_position(parameters& params)
{
    //Генерація чисел, які будуть мінами
    int* mines = new int[params.mine_number];
    int length_x_width = params.length * params.width;
    srand((unsigned)time(NULL));
    for (int i = 0; i < params.mine_number; i++)
        mines[i] = rand() % length_x_width + 1;
    //Якщо номери сгенерованих мін повторюються
    int n = 0;
    for (int j = 0; j < params.mine_number - 1; j++)
    {
        n++;
        for (int i = n; i < params.mine_number - 1; i++)
            if (mines[j] == mines[i])
                mines[j] = rand() % length_x_width + 1;
    }
    return mines;
}
int** Field::format_field(int** arr, int* mines, parameters& params)
{
    arr = assign_array(arr, params);
    //Заміна номерів на 9 (*)
    for (int k = 0; k < params.mine_number - 1; k++)
    {
        for (int i = 0; i < params.length; i++)
        {
            for (int j = 0; j < params.width; j++)
            {
                if (arr[i][j] == mines[k])
                {
                    arr[i][j] = MINE;
                }
            }
        }
    }
    //Заміна номерів на 0 (.)
    for (int i = 0; i < params.length; i++)
    {
        for (int j = 0; j < params.width; j++)
        {
            if (arr[i][j] != MINE)
                arr[i][j] = NOTHING;
        }
    }
    return arr;
}
int** Field::put_number_of_mines(int** arr, int* mines, parameters& params)
{
    arr = format_field(arr, mines, params);
    //Розміщення чисел, які позначають міни поблизу
    for (int i = 0; i < params.length; i++)
    {
        for (int j = 0; j < params.width; j++)
        {
            if (arr[i][j] != MINE)
            {
                for (int k = i > 0 ? i - 1 : 0; k <= i + 1 and k < params.length; k++)
                    for (int l = j > 0 ? j - 1 : 0; l <= j + 1 and l < params.width; l++)
                        if (arr[k][l] == MINE)
                            arr[i][j] += 1;
            }
        }
    }
    return arr;
}

//Функція для запису розмірів та кількості мін
void Field::size(parameters& params, int& length_x_width)
{
    Print p;
    cout << "------------------------------" << endl;
    cout << "Please, enter Field length (^) (8 - 30): ";
    while (!(cin >> params.length) || params.length < MIN_FIELD_SIZE || params.length > MAX_FIELD_SIZE)
        p.errors();
    cout << "Please, enter Field width (>) (8 - 30): ";
    while (!(cin >> params.width) || params.width < MIN_FIELD_SIZE || params.width > MAX_FIELD_SIZE)
        p.errors();
    length_x_width = params.length * params.width;
    cout << "Please, enter the number of mines (*) on the Field (5 - " << length_x_width - MIN_AVAILABLE_CELLS << "): ";
    while (!(cin >> params.mine_number) || params.mine_number < MIN_AMOUNT_MINES || params.mine_number > length_x_width - MIN_AVAILABLE_CELLS)
        p.errors();
}
int** Field::create_field(parameters& params)
{
    int* mines = define_mines_position(params);
    int** arr = create_array(params);
    arr = put_number_of_mines(arr, mines, params);
    delete[] mines;
    return arr;
}
