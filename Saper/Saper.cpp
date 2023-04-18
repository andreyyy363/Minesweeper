#include <iostream>
#include <ctime>
#include <iomanip>
#include <string> 
#include <format>
#include "constants.h"

using namespace std;

struct parameters
{
    int length, width, mine_number, number_of_cells, x, y;
};

//COUT ФУНКЦІЇ

//Cout помилки введення розміру та кількості мін

void errors()
{
    cin.clear();
    fflush(stdin);
    cout << endl << "Try again: ";
}

void stripes()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
}
//Cout для Win
void winner(bool checker, bool win, parameters& params, int** arr, int** check)
{
    int i, j;
    //Перевірка на перемогу
    if (checker)
        for (i = 0; i < params.length; i++)
            for (j = 0; j < params.width; j++)
                if (check[i][j] == FLAG && arr[i][j] == MINE)
                    win = true;

    if (win)
    {
        stripes();
        cout << "##  ##    ## ##   ##  ###           ##   ##    ####   ###  ##                      " << endl;
        cout << "##  ##   ##   ##  ##   ##           ##   ##     ##      ## ##                  #   " << endl;
        cout << "##  ##   ##   ##  ##   ##           ##   ##     ##     # ## #              #    #  " << endl;
        cout << " ## ##   ##   ##  ##   ##           ## # ##     ##     ## ##                     # " << endl;
        cout << "  ##     ##   ##  ##   ##           # ### #     ##     ##  ##              #    #  " << endl;
        cout << "  ##     ##   ##  ##   ##            ## ##      ##     ##  ##                  #   " << endl;
        cout << "  ##      ## ##    ## ##            ##   ##    ####   ###  ##                      " << endl;
        stripes();
    }
}
//Cout для Lose
void loser()
{
    stripes();
    cout << "##  ##    ## ##   ##  ###           ####      ## ##    ## ##   #### ##             " << endl;
    cout << "##  ##   ##   ##  ##   ##            ##      ##   ##  ##   ##  # ## ##           # " << endl;
    cout << "##  ##   ##   ##  ##   ##            ##      ##   ##  ####       ##         #   #  " << endl;
    cout << " ## ##   ##   ##  ##   ##            ##      ##   ##   #####     ##             #  " << endl;
    cout << "  ##     ##   ##  ##   ##            ##      ##   ##      ###    ##         #   #  " << endl;
    cout << "  ##     ##   ##  ##   ##            ##  ##  ##   ##  ##   ##    ##              # " << endl;
    cout << "  ##      ## ##    ## ##            ### ###   ## ##    ## ##    ####               " << endl;
    stripes();
}

//ГОЛОВНІ ФУНКЦІЇ

//Функція створення поля для гри

//Функція створення поля для гри
//////////////////////////////////////////////////////////////////////////////////////////////

class field
{
protected:
    int** create_array(parameters& params)
    {
        //Створення масиву для поля
        int** arr = new int* [params.length];
        for (int i = 0; i < params.length; ++i)
            arr[i] = new int[params.width];
        return arr;
    }

    int** assign_array(int** arr, parameters& params)
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

    int* define_mines_position(parameters& params)
    {
        int lenght_x_width = params.length * params.width;
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
                    mines[j] = rand() % lenght_x_width + 1;
        }
        return mines;
    }
    int** format_field(int** arr, int* mines, parameters& params)
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
    int** put_number_of_mines(int** arr, int* mines, parameters& params)
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

public:
    int** create_field(parameters& params)
    {
        int* mines = define_mines_position(params);
        int** arr = create_array(params);
        arr = put_number_of_mines(arr, mines, params);
        delete[] mines;
        return arr;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////

//Створення масиву для перевірки на відкритість поля
int** arrcheck(parameters& params)
{
    int** check = new int* [params.length];
    for (int i = 0; i < params.width; ++i)
        check[i] = new int[params.width];

    //Заповнення масиву нулями
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
            check[i][j] = 0;
    return check;
}
//Функція для запису розмірів та кількості мін

void size(parameters& params, int& length_x_width)
{
    cout << "------------------------------" << endl;
    cout << "Please, enter field length (^) (8 - 30): ";
    while (!(cin >> params.length) || params.length < 8 || params.length > 30)
        errors();
    cout << "Please, enter field width (>) (8 - 30): ";
    while (!(cin >> params.width) || params.width < 8 || params.width > 30)
        errors();
    length_x_width = params.length * params.width;
    cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - 10 << "): ";
    while (!(cin >> params.mine_number) || params.mine_number < 5 || params.mine_number > length_x_width - 10)
        errors();
}


//Функція для coutа поля
void coutfield(int** arr, int** check, parameters& params, bool lose, bool& mistake)
{
    int i, j;
    if (mistake)
    {
        mistake = false;
        return;
    }
    else
    {
        //Cout поля
        for (j = 0; j <= params.width; j++)
            cout << j << setw(5);
        cout << endl;

        for (j = 0; j <= (5 * params.width) - 3; j++)
            cout << "_";
        cout << endl;

        for (i = 0; i < params.length; i++)
        {
            if (i <= 8)
                cout << setw(0) << i + 1 << setw(2) << "|" << setw(3);
            else
                cout << setw(0) << i + 1 << setw(1) << "|" << setw(3);
            for (j = 0; j < params.width; j++)
            {
                if (check[i][j] == 1)
                {
                    if (arr[i][j] != MINE && arr[i][j] != 0)
                        cout << arr[i][j] << setw(5);
                    if (arr[i][j] != MINE && arr[i][j] == 0)
                        cout << "." << setw(5);
                }
                if (check[i][j] == FLAG)
                {
                    cout << "<|" << setw(5);
                }
                if (check[i][j] == NOTHING)
                {
                    if (arr[i][j] == MINE && lose == true)
                        cout << "*" << setw(5);
                    else
                        cout << "-" << setw(5);
                }
            }
            cout << " " << endl;
        }
    }
}
//Функція для відкриття поля
void fieldopening(parameters& params)
{
    //Вибір місця, яке бажаємо перевірити
    cout << "Enter X you want to check: ";
    while (!(cin >> params.x) || params.x <= 0 || params.x > params.width)
        errors();

    cout << "Enter Y you want to check: ";
    while (!(cin >> params.y) || params.y <= 0 || params.y > params.length)
        errors();
    params.x -= 1;
    params.y -= 1;
    system("cls");
}
//Функція для встановлення прапора
void putflag(int** check, parameters& params)
{
    cout << "Enter X you want to put a flag: ";
    while (!(cin >> params.x) || params.x <= 0 || params.x > params.width)
        errors();
    cout << "Enter Y you want to put a flag: ";
    while (!(cin >> params.y) || params.y <= 0 || params.y > params.length)
        errors();
    params.x -= 1;
    params.y -= 1;
    system("cls");
    check[params.y][params.x] = FLAG;
}
//Функція для автоматичного відкривання поля, якщо обрано порожнє місце
void autoopen(int x, int y, int** arr, parameters& params, int** check)
{
    if (x < 0 || y < 0 || x >= params.width || y >= params.length)
        return;

    if (check[y][x] == CHECKED)
        return;

    check[y][x] = CHECKED;

    if (arr[y][x] == 0)
    {
        autoopen(x - 1, y - 1, arr, params, check);
        autoopen(x, y - 1, arr, params, check);
        autoopen(x + 1, y - 1, arr, params, check);
        autoopen(x - 1, y, arr, params, check);
        autoopen(x + 1, y, arr, params, check);
        autoopen(x - 1, y + 1, arr, params, check);
        autoopen(x, y + 1, arr, params, check);
        autoopen(x + 1, y + 1, arr, params, check);
    }
}
//Функція для обрання дії
bool action_choice(int** arr, parameters& params, int** check, bool& mistake, bool lose)
{
    params.x = 0; 
    params.y = 0;
    string action;
    cout << endl;
    cout << "Choose an action: open a field (O) or put a flag (P): ";
    cin >> action;

    if (action == "o" || action == "O")
    {
        fieldopening(params);

        //Якщо обрано порожнє місце
        if (arr[params.y][params.x] != MINE)
        {
            autoopen(params.x, params.y, arr, params, check);
            return true;
        }
        //Якщо обрано місце з міною
        else
        {
            lose = true;
            system("cls");
            coutfield(arr, check, params, lose, mistake);
            loser();
            return false;
        }
    }

    if (action == "p" || action == "P")
    {
        putflag(check, params);
        return true;
    }
    else
    {
        cout << endl << "Try again!" << endl;
        mistake = true;
        return true;
    }
}
//Функція для перевірки поля
void check_field(int** arr, int** check, parameters& params, bool& checker, bool& win)
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

//Функція для рестарту гри
bool restart()
{
    string restart;
    bool stop;
    cout << "Do you want to play again? (Y/N): ";
    while (true)
    {
        cin >> restart;
        system("cls");
        if (restart == "y" || restart == "Y")
        {
            cout << endl;
            cout << "Good choice! :)";
            cout << endl;
            stop = false;
            break;
        }
        if (restart == "n" || restart == "N")
        {
            cout << endl;
            cout << "Okay, thanks for playing!";
            cout << endl;
            stop = true;
            break;
        }
        else
        {
            cout << endl << "Can you repeat?" << endl << "Do you want to play again? (Y/N): ";
            continue;
        }
    }
    return stop;
}

//Функція для очищення пам'яті
void cleanram(int** arr, int** check, parameters& params)
{
    for (int i = 0; i < params.length; ++i)
        delete[] arr[i];
    delete[] arr;

    for (int i = 0; i < params.length; ++i)
        delete[] check[i];
    delete[] check;
}

//Хід гри
int main()
{
    parameters game_parameters;
    int length_x_width;
    cout << "Saper v.1.5 (alpha)" << endl;

    //ГРА
    while (true)
    {
        field f;
        size(game_parameters, length_x_width);
        system("cls");
        cout << "New game" << endl << endl;
        //Генерація поля
        int** arr = f.create_field(game_parameters);
        int** check = arrcheck(game_parameters);
        bool checker = false, win = false, lose = false, mistake = false, choice = false;
        while (!checker)
        {
            //Перевірка на відкриття усього поля
            coutfield(arr, check, game_parameters, lose, mistake);

            check_field(arr, check, game_parameters, checker, win);
            if (checker)
                break;

            choice = action_choice(arr, game_parameters, check, mistake, lose);
            if (choice)
                continue;
            else
                break;
        }

        winner(checker, win, game_parameters, arr, check);
        cleanram(arr, check, game_parameters);

        //Рестарт гри (за бажанням гравця)
        bool stop = restart();
        if (stop)
            break;
        else
            continue;
    }
    return 0;
}