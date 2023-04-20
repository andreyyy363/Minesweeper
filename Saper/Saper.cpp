#include <iostream>
#include <ctime>
#include <iomanip>
#include <string> 
#include "constants.h"

using namespace std;

struct parameters
{
    int length, width, mine_number, number_of_cells, x, y;
};

struct bools
{
    bool checker, win, lose, mistake, choice;
};

class print
{
    protected:
    //Функція для coutа поля

        void print_column_numbers(parameters& params)
        {
            int j;
            for (j = 0; j <= params.width; j++)
                cout << j << setw(5);
            cout << endl;
            for (j = 0; j <= (5 * params.width) - 3; j++)
                cout << "_";
            cout << endl;
        }
        void print_line_numbers(int i)
        {
            if (i <= 8)
                cout << setw(0) << i + 1 << setw(2) << "|" << setw(3);
            else
                cout << setw(0) << i + 1 << setw(1) << "|" << setw(3);
        }

        void print_empty_field(int i, int j, int** arr, int** check)
        {
            if (check[i][j] == 1)
            {
                if (arr[i][j] != MINE && arr[i][j] != 0)
                    cout << arr[i][j] << setw(5);
                if (arr[i][j] != MINE && arr[i][j] == 0)
                    cout << "." << setw(5);
            }
        }

        void print_flag(int i, int j, int** check)
        {
            if (check[i][j] == FLAG)
            {
                cout << "<|" << setw(5);
            }
        }
        void print_mines(int i, int j, int** check, int** arr, bools& bool_params)
        {
            if (check[i][j] == NOTHING)
            {
                if (arr[i][j] == MINE && bool_params.lose == true)
                    cout << "*" << setw(5);
                else
                    cout << "-" << setw(5);
            }
        }
    public:
        void print_board(int** arr, int** check, parameters& params, bools& bool_params)
        {
            int i, j;
            if (!bool_params.mistake)
            {
                //Cout поля
                print_column_numbers(params);
                for (i = 0; i < params.length; i++)
                {
                    print_line_numbers(i);
                    for (j = 0; j < params.width; j++)
                    {
                        print_empty_field(i, j, arr, check);
                        print_flag(i, j, check);
                        print_mines(i, j, check, arr, bool_params);
                    }
                    cout << " " << endl;
                }
            }
            else
            {
                bool_params.mistake = false;
                return;
            }
        }

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
        void winner(bools& bool_params, parameters& params, int** arr, int** check)
        {
            int i, j;
            //Перевірка на перемогу
            if (bool_params.checker)
                for (i = 0; i < params.length; i++)
                    for (j = 0; j < params.width; j++)
                        if (check[i][j] == FLAG && arr[i][j] == MINE)
                            bool_params.win = true;

            if (bool_params.win)
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
};

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
        //Функція для запису розмірів та кількості мін
        void size(parameters& params, int& length_x_width)
        {
            print p;
            cout << "------------------------------" << endl;
            cout << "Please, enter field length (^) (8 - 30): ";
            while (!(cin >> params.length) || params.length < MIN_FIELD_SIZE || params.length > MAX_FIELD_SIZE)
                p.errors();
            cout << "Please, enter field width (>) (8 - 30): ";
            while (!(cin >> params.width) || params.width < MIN_FIELD_SIZE || params.width > MAX_FIELD_SIZE)
                p.errors();
            length_x_width = params.length * params.width;
            cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - MIN_AVAILABLE_CELLS << "): ";
            while (!(cin >> params.mine_number) || params.mine_number < MIN_AMOUNT_MINES || params.mine_number > length_x_width - MIN_AVAILABLE_CELLS)
                p.errors();
        }
        int** create_field(parameters& params)
        {
            int* mines = define_mines_position(params);
            int** arr = create_array(params);
            arr = put_number_of_mines(arr, mines, params);
            delete[] mines;
            return arr;
        }
};

class action
{
    protected:
        //Функція для відкриття поля
        void open_field(parameters& params)
        {
            print p;
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
        void putflag(int** check, parameters& params)
        {
            print p;
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
    public:
        //Функція для обрання дії
        bool action_choice(int** arr, parameters& params, int** check, bools& bool_params)
        {
            print p;
            params.x = 0;
            params.y = 0;
            string action;
            cout << endl;
            cout << "Choose an action: open a field (O) or put a flag (P): ";
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
};

class check
{
    public:
        //Створення масиву для перевірки на відкритість поля
        int** arrcheck(parameters& params)
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
        void check_field(int** arr, int** check, parameters& params, bools& bool_params)
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
};
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

class clean
{
    protected:
        void clean_arr(int** arr, parameters& params)
        {
            for (int i = 0; i < params.length; ++i)
                delete[] arr[i];
            delete[] arr;
        }
        void clean_check(int** check, parameters& params)
        {

            for (int i = 0; i < params.length; ++i)
                delete[] check[i];
            delete[] check;
        }
    public:
        void clean_ram(int** arr, int** check, parameters& params)
        {
            clean_arr(arr, params);
            clean_check(check, params);
        }
};

//Хід гри
int main()
{
    parameters game_parameters;
    bools bool_parameters;
    field f;
    print p;
    action a;
    check ch;
    clean c;
    int length_x_width;
    
    cout << "Saper v.1.5 (alpha)" << endl;

    //ГРА
    while (true)
    {
        f.size(game_parameters, length_x_width);
        system("cls");
        cout << "New game" << endl << endl;
        //Генерація поля
        int** arr = f.create_field(game_parameters);
        int** check = ch.arrcheck(game_parameters);
        bool_parameters.checker = false, bool_parameters.win = false;
        bool_parameters.lose = false, bool_parameters.mistake = false, bool_parameters.choice = false;
        while (!bool_parameters.checker)
        {
            //Перевірка на відкриття усього поля
            p.print_board(arr, check, game_parameters, bool_parameters);

            ch.check_field(arr, check, game_parameters, bool_parameters);
            if (bool_parameters.checker)
                break;

            bool_parameters.choice = a.action_choice(arr, game_parameters, check, bool_parameters);
            if (bool_parameters.choice)
                continue;
            else
                break;
        }

        p.winner(bool_parameters, game_parameters, arr, check);
        c.clean_ram(arr, check, game_parameters);

        //Рестарт гри (за бажанням гравця)
        
        if (restart())
            break;
    }
    return 0;
}