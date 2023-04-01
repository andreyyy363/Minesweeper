#include <iostream>
#include <ctime>
#include <iomanip>
#include "cout_functions.h"
#include "cout_field.h"
#include "check_field.h"
#include "create_field.h"
#include "restart_and_clean_ram.h"

using namespace std;

//ГОЛОВНІ ФУНКЦІЇ

//Функція для запису розмірів та кількості мін

void size(int& length, int& width, int& mine_number, int& length_x_width)
{
    bool err_length = false, err_width = false, err_mines = false;
    bool err_coord_x = false, err_coord_y = false, err_coord_check = false;
    cout << "------------------------------" << endl;
    cout << "Please, enter field length (^) (8 - 30): ";

    while (!(cin >> length) || length < 8 || length > 30)
    {
        err_length = true;
        errors(err_length, err_width, err_mines, err_coord_x, err_coord_y, err_coord_check, length_x_width);
        err_length = false;
    }

    cout << "Please, enter field width (>) (8 - 30): ";
    while (!(cin >> width) || width < 8 || width > 30)
    {
        err_width = true;
        errors(err_length, err_width, err_mines, err_coord_x, err_coord_y, err_coord_check, length_x_width);
        err_width = false;
    }

    length_x_width = length * width;

    cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - 10 << "): ";

    while (!(cin >> mine_number) || mine_number < 5 || mine_number > length_x_width - 10)
    {
        err_mines = true;
        errors(err_length, err_width, err_mines, err_coord_x, err_coord_y, err_coord_check, length_x_width);
        err_mines = false;
    }
}

//Функція для відкриття поля
void fieldopening(int& x, int& y, int length, int width, int length_x_width)
{
    //Вибір місця, яке бажаємо перевірити
    bool err_length = false, err_width = false, err_mines = false;
    bool err_coord_x = false, err_coord_y = false, err_coord_check = false;
    cout << "Enter X you want to check: ";
    while (!(cin >> x) || x <= 0 || x > width)
    {
        err_coord_x = true;
        err_coord_check = true;
        errors(err_length, err_width, err_mines, err_coord_x, err_coord_y, err_coord_check, length_x_width);
        err_coord_x = false;
        err_coord_check = false;
    }

    cout << "Enter Y you want to check: ";
    while (!(cin >> y) || y <= 0 || y > length)
    {
        err_coord_y = true;
        err_coord_check = true;
        errors(err_length, err_width, err_mines, err_coord_x, err_coord_y, err_coord_check, length_x_width);
        err_coord_y = false;
        err_coord_check = false;
    }

    x -= 1;
    y -= 1;
    system("cls");
}
//Функція для встановлення прапора
void putflag(int** check, int length, int width)
{
    int x, y;
    cout << "Enter X you want to put a flag: ";
    cin >> x;
    cout << endl;
    while (x <= 0 || x > width)
    {
        cout << endl;
        cout << "Try again!" << endl;
        cout << endl << endl;
        cout << "Enter X you want to put a flag: ";
        cin >> x;
        cout << endl;
    }
    cout << "Enter Y you want to put a flag: ";
    cin >> y;
    cout << endl;
    while (y <= 0 || y > length)
    {
        cout << endl;
        cout << "Try again!" << endl;
        cout << endl << endl;
        cout << "Enter Y you want to put a flag: ";
        cin >> y;
        cout << endl;
    }
    x -= 1;
    y -= 1;
    system("cls");
    check[y][x] = FLAG;
}
//Функція для автоматичного відкривання поля, якщо обрано порожнє місце
void autoopen(int x, int y, int** arr, int length, int width, int** check)
{
    if (x < 0 || y < 0 || x >= width || y >= length)
        return;

    if (check[y][x] == 1)
        return;

    check[y][x] = 1;

    if (arr[y][x] == 0)
    {
        autoopen(x - 1, y - 1, arr, length, width, check);
        autoopen(x, y - 1, arr, length, width, check);
        autoopen(x + 1, y - 1, arr, length, width, check);
        autoopen(x - 1, y, arr, length, width, check);
        autoopen(x + 1, y, arr, length, width, check);
        autoopen(x - 1, y + 1, arr, length, width, check);
        autoopen(x, y + 1, arr, length, width, check);
        autoopen(x + 1, y + 1, arr, length, width, check);
    }
}
//Функція для обрання дії
bool action_choice(int** arr, int length, int width, int length_x_width, int** check, bool& mistake, bool lose)
{
    int x = 0, y = 0;
    string action;
    cout << endl;
    cout << "Choose an action: open a field (O) or put a flag (P): ";
    cin >> action;

    if (action == "o" || action == "O")
    {
        fieldopening(x, y, length, width, length_x_width);

        //Якщо обрано порожнє місце
        if (arr[y][x] != 9)
        {
            autoopen(x, y, arr, length, width, check);
            return true;
        }
        //Якщо обрано місце з міною
        else
        {
            lose = true;
            system("cls");
            coutfield(arr, check, length, width, lose, mistake);
            loser();
            return false;
        }
    }

    if (action == "p" || action == "P")
    {
        putflag(check, length, width);
        return true;
    }
    else
    {
        cout << endl << "Try again!" << endl;
        mistake = true;
        return true;
    }
}

//Хід гри
int main()
{
    int length, width, mine_number, length_x_width;
    cout << "Saper v.1.5 (alpha)" << endl;

    //ГРА
    while (true)
    {
        size(length, width, mine_number, length_x_width);
        system("cls");
        cout << "New game" << endl << endl;
        //Генерація поля
        int** arr = create_field(length, width, mine_number, length_x_width);
        int** check = arrcheck(length, width);
        bool checker = false, win = false, lose = false, mistake = false, choice = false;
        while (!checker)
        {
            //Перевірка на відкриття усього поля
            coutfield(arr, check, length, width, lose, mistake);

            check_field(arr, check, length, width, checker, win);
            if (checker)
                break;

            choice = action_choice(arr, length, width, length_x_width, check, mistake, lose);
            if (choice)
                continue;
            else
                break;
        }

        winner(checker, win, length, width, arr, check);
        cleanram(arr, check, length);

        //Рестарт гри (за бажанням гравця)
        bool stop = restart();
        if (stop)
            break;
        else
            continue;
    }
    return 0;
}