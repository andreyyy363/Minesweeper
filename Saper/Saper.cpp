#include <iostream>
#include <ctime>
#include <iomanip>
#include <string> 
#include <format>
#include "constants.h"

using namespace std;

struct parameters
{
    int length, width, mine_number, number_of_cells;
};

//COUT ФУНКЦІЇ

//Cout помилки введення розміру та кількості мін

void errors()
{
    cin.clear();
    fflush(stdin);
    cout << endl << "Try again!" << endl << endl;
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

int** create_field(parameters& params, int length_x_width)
{
    //Створення масиву для поля
    int** arr = new int* [params.length];
    for (int i = 0; i < params.length; ++i)
        arr[i] = new int[params.width];

    //Заповнення масиву від 1 до n
    int numb = 0;
    for (int i = 0; i < params.length; i++)
        for (int j = 0; j < params.width; j++)
        {
            numb++;
            arr[i][j] = numb;
        }

    //Генерація чисел, які будуть мінами
    int i, j;
    int* mines = new int[params.mine_number];
    srand((unsigned)time(NULL));

    for (i = 0; i < params.mine_number; i++)
    {
        mines[i] = rand() % length_x_width + 1;
    }

    //Якщо номери сгенерованих мін повторюються
    int n = 0;
    for (j = 0; j < params.mine_number - 1; j++)
    {
        n++;
        for (i = n; i < params.mine_number - 1; i++)
            if (mines[j] == mines[i])
                mines[j] = rand() % length_x_width + 1;
    }

    //Заміна номерів на 9 (*)
    for (int k = 0; k < params.mine_number - 1; k++)
    {
        for (i = 0; i < params.length; i++)
        {
            for (j = 0; j < params.width; j++)
            {
                if (arr[i][j] == mines[k])
                {
                    arr[i][j] = MINE;
                }
            }
        }
    }

    //Заміна номерів на 0 (.)
    for (i = 0; i < params.length; i++)
    {
        for (j = 0; j < params.width; j++)
        {
            if (arr[i][j] != MINE)
                arr[i][j] = NOTHING;
        }
    }
    delete[] mines;
    //Розміщення чисел, які позначають міни поблизу

    //Doesn't work :(

    for (i = 0; i < params.length; i++)
    {
        for (j = 0; j < params.width; j++)
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

    /*
    for (i = 0; i < params.length; i++)
    {
        for (j = 0; j < params.width; j++)
        {
            if (arr[i][j] != 9)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                    if (arr[i - 1][j - 1] == 9)
                        arr[i][j] += 1;

                if (i - 1 >= 0)
                    if (arr[i - 1][j] == 9)
                        arr[i][j] += 1;

                if (i - 1 >= 0 && j + 1 < params.width)
                    if (arr[i - 1][j + 1] == 9)
                        arr[i][j] += 1;

                if (j - 1 >= 0)
                    if (arr[i][j - 1] == 9)
                        arr[i][j] += 1;

                if (j + 1 < params.width)
                    if (arr[i][j + 1] == 9)
                        arr[i][j] += 1;

                if (i + 1 < params.length && j - 1 >= 0)
                    if (arr[i + 1][j - 1] == 9)
                        arr[i][j] += 1;

                if (i + 1 < params.length)
                    if (arr[i + 1][j] == 9)
                        arr[i][j] += 1;

                if (i + 1 < params.length && j + 1 < params.width)
                    if (arr[i + 1][j + 1] == 9)
                        arr[i][j] += 1;
            }
        }
    }
    */
    return arr;

}
//Створення масиву для перевірки на відкритість поля
    int** arrcheck(parameters & params)
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

    void size(parameters & params, int& length_x_width)
    {
        bool err_length = false, err_width = false, err_mines = false;
        bool err_coord_x = false, err_coord_y = false, err_coord_check = false;
        cout << "------------------------------" << endl;
        cout << "Please, enter field length (^) (8 - 30): ";

        while (!(cin >> params.length) || params.length < 8 || params.length > 30)
        {
            err_length = true;
            errors();
            err_length = false;
        }

        cout << "Please, enter field width (>) (8 - 30): ";
        while (!(cin >> params.width) || params.width < 8 || params.width > 30)
        {
            err_width = true;
            errors();
            err_width = false;
        }

        length_x_width = params.length * params.width;

        cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - 10 << "): ";

        while (!(cin >> params.mine_number) || params.mine_number < 5 || params.mine_number > length_x_width - 10)
        {
            err_mines = true;
            errors();
            err_mines = false;
        }
    }


    //Функція для coutа поля
    void coutfield(int** arr, int** check, parameters & params, bool lose, bool& mistake)
    {
        int i, j;
        if (mistake == true)
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
                    cout << setw(0) << i + 1 << setw(3) << "|" << setw(3);
                else
                    cout << setw(0) << i + 1 << setw(2) << "|" << setw(3);
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
    void fieldopening(int& x, int& y, parameters & params, int length_x_width)
    {
        //Вибір місця, яке бажаємо перевірити
        bool err_length = false, err_width = false, err_mines = false;
        bool err_coord_x = false, err_coord_y = false, err_coord_check = false;
        cout << "Enter X you want to check: ";
        while (!(cin >> x) || x <= 0 || x > params.width)
            errors();

        cout << "Enter Y you want to check: ";
        while (!(cin >> y) || y <= 0 || y > params.length)
            errors();

        x -= 1;
        y -= 1;
        system("cls");
    }
    //Функція для встановлення прапора
    void putflag(int** check, parameters & params)
    {
        int x, y;
        cout << "Enter X you want to put a flag: ";
        cin >> x;
        cout << endl;
        while (x <= 0 || x > params.width)
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
        while (y <= 0 || y > params.length)
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
    void autoopen(int x, int y, int** arr, parameters & params, int** check)
    {
        if (x < 0 || y < 0 || x >= params.width || y >= params.length)
            return;

        if (check[y][x] == 1)
            return;

        check[y][x] = 1;

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
    bool action_choice(int** arr, parameters & params, int length_x_width, int** check, bool& mistake, bool lose)
    {
        int x = 0, y = 0;
        string action;
        cout << endl;
        cout << "Choose an action: open a field (O) or put a flag (P): ";
        cin >> action;

        if (action == "o" || action == "O")
        {
            fieldopening(x, y, params, length_x_width);

            //Якщо обрано порожнє місце
            if (arr[y][x] != 9)
            {
                autoopen(x, y, arr, params, check);
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
    void check_field(int** arr, int** check, parameters & params, bool& checker, bool& win)
    {
        int i, j;
        for (i = 0; i < params.length; i++)
        {
            for (j = 0; j < params.width; j++)
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
    void cleanram(int** arr, int** check, parameters & params)
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
            size(game_parameters, length_x_width);
            system("cls");
            cout << "New game" << endl << endl;
            //Генерація поля
            int** arr = create_field(game_parameters, length_x_width);
            int** check = arrcheck(game_parameters);
            bool checker = false, win = false, lose = false, mistake = false, choice = false;
            while (!checker)
            {
                //Перевірка на відкриття усього поля
                coutfield(arr, check, game_parameters, lose, mistake);

                check_field(arr, check, game_parameters, checker, win);
                if (checker)
                    break;

                choice = action_choice(arr, game_parameters, length_x_width, check, mistake, lose);
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