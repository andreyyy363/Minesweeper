#include "libraries.h"
#include "print_functions.h"
#include "constants_and_variables.h"
#include "actions.h"

//Функція для відкриття поля
void Action::open_field(parameters& params)
{
    Print p;
    //Вибір місця, яке бажаємо перевірити
    cout << "Enter X you want to check: ";
    while (!(cin >> params.x) || params.x <= 0 || params.x > params.width)
        p.errors();

    cout << "Enter Y you want to check: ";
    while (!(cin >> params.y) || params.y <= 0 || params.y > params.length)
        p.errors();
    params.x -= 1;
    params.y -= 1;
    system("cls");
}
//Функція для встановлення прапора
void Action::putflag(int** check, parameters& params)
{
    Print p;
    cout << "Enter X you want to put a flag: ";
    while (!(cin >> params.x) || params.x <= 0 || params.x > params.width)
        p.errors();
    cout << "Enter Y you want to put a flag: ";
    while (!(cin >> params.y) || params.y <= 0 || params.y > params.length)
        p.errors();
    params.x -= 1;
    params.y -= 1;
    system("cls");
    check[params.y][params.x] = FLAG;
}
//Функція для автоматичного відкривання поля, якщо обрано порожнє місце
void Action::autoopen(int x, int y, int** arr, parameters& params, int** check)
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
bool Action::action_choice(int** arr, parameters& params, int** check, bools& bool_params)
{
    Print p;
    params.x = 0;
    params.y = 0;
    string action;
    cout << endl;
    cout << "Choose an action: open a Field (O) or put a flag (P): ";
    cin >> action;

    if (action == "o" || action == "O")
    {
        open_field(params);

        //Якщо обрано порожнє місце
        if (arr[params.y][params.x] != MINE)
        {
            autoopen(params.x, params.y, arr, params, check);
            return true;
        }
        //Якщо обрано місце з міною
        else
        {
            bool_params.lose = true;
            system("cls");
            p.print_board(arr, check, params, bool_params);
            p.loser();
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
        bool_params.mistake = true;
        return true;
    }
}
