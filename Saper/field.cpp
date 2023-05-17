#include "print_functions.h"
#include "field.h"

void Field::create_array()
{
    //Створення масиву для поля
    arr = new int* [params.length];
    for (int i = 0; i < params.length; ++i)
        arr[i] = new int[params.width];
}

void Field::assign_array()
{
    //Заповнення масиву від 1 до n
    int numb = 0;
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
        {
            arr[i][j] = numb;
            numb++;
        }
}

void Field::define_mines_position()
{
    //Генерація чисел, які будуть мінами
    mines = new int[params.mine_number];
    srand((unsigned)time(NULL));
    for (int i = 0; i < params.mine_number; i++)
        mines[i] = rand() % length_x_width + 1;

    //Якщо номери сгенерованих мін повторюються
    int n = 0;
    for (int j = 0; j < params.mine_number; j++)
    {
        for (int i = j + 1; i < params.mine_number; i++)
            if (mines[j] == mines[i])
                mines[i] = rand() % length_x_width + 1;        
    }
}
void Field::format_field()
{
    assign_array();
    //Заміна номерів на 9 (*)
    for (int k = 0; k < params.mine_number; k++)
    {
        int i = mines[k] / params.width;
        int j = mines[k] % params.width;
        arr[i][j] = MINE;
    }
    //Заміна номерів на 0 (.)
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
            if (arr[i][j] != MINE)
                arr[i][j] = NOTHING;
}
void Field::put_number_of_mines()
{
    format_field();
    //Розміщення чисел, які позначають міни поблизу
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
            if (arr[i][j] != MINE)
                set_numb_of_mines(i, j);
}

void Field::set_numb_of_mines(int i, int j)
{
    for (int k = i > 0 ? i - 1 : 0; k <= i + 1 and k < params.length; k++)
        for (int l = j > 0 ? j - 1 : 0; l <= j + 1 and l < params.width; l++)
            if (arr[k][l] == MINE)
                arr[i][j] += 1;
}

//Функція для запису розмірів та кількості мін
void Field::size()
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

void Field::create_field()
{
    define_mines_position();
    create_array();
    put_number_of_mines();
    delete[] mines;
}

parameters Field::getParams()
{
    return params;
}
int** Field::getArray()
{
    return arr;
}
