#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
const int MINE = 9, FLAG = 2, CHECKED = 1, NOTHING = 0;

//COUT ФУНКЦІЇ

//Cout помилки введення розміру та кількості мін
void err_size(bool err_length, bool err_width, bool err_mines, int length_x_width)
{
    cout << endl << "Try again!" << endl << endl;
    if (err_length)
        cout << "Please, enter field length (^) (8 - 30): ";
    if (err_width)
        cout << "Please, enter field width (>) (8 - 30): ";
    if (err_mines)
        cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - 10 << "): ";
}

void stripes()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
}
//Cout для Win
void winner(bool checker, bool win, int length, int width, int** arr, int** check)
{
    int i, j;
    //Перевірка на перемогу
    if (checker)
    {
        for (i = 0; i < length; i++)
        {
            for (j = 0; j < width; j++)
            {
                if (check[i][j] == FLAG && arr[i][j] == MINE)
                    win = true;
            }
        }
    }
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
int** arrfield(const int length, const int width, int mine_number, int lenght_x_width)
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
    int *mines = new int[mine_number];
    srand(time(NULL));

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
//Створення масиву для перевірки на відкритість поля
int** arrcheck(const int length, const int width)
{
    int** check = new int* [length];
    for (int i = 0; i < width; ++i)
        check[i] = new int[width];

    //Заповнення масиву нулями
    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            check[i][j] = 0;
    return check;
}
//Функція для запису розмірів та кількості мін

void size(int& length, int& width, int& mine_number, int& length_x_width)
{
    bool err_length = false, err_width = false, err_mines = false;
    cout << "------------------------------" << endl;
    cout << "Please, enter field length (^) (8 - 30): ";
    while (!(cin >> length) || length < 8 || length > 30)
    {
        cin.clear();
        fflush(stdin);
        err_length = true;
        err_size(err_length, err_width, err_mines, length_x_width);
        err_length = false;
    }

    cout << "Please, enter field width (>) (8 - 30): ";
    while (!(cin >> width) || width < 8 || width > 30)
    {
        cin.clear();
        fflush(stdin);
        err_width = true;
        err_size(err_length, err_width, err_mines, length_x_width);
        err_width = false;
    }

    length_x_width = length * width;

    cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - 10 << "): ";

    while (!(cin >> mine_number) || mine_number < 5 || mine_number > length_x_width - 10)
    {
        cin.clear();
        fflush(stdin);
        err_mines = true;
        err_size(err_length, err_width, err_mines, length_x_width);
        err_mines = false;
    }
}
//Функція для coutа поля
void coutfield(int** arr, int** check, int length, int width, bool lose, bool& mistake)
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
        for (j = 0; j <= width; j++)
            cout << j << setw(5);
        cout << endl;

        for (j = 0; j <= (5 * width) - 3; j++)
            cout << "_";
        cout << endl;

        for (i = 0; i < length; i++)
        {
            if (i <= 8)
                cout << setw(0) << i + 1 << setw(2) << "|" << setw(3);
            else
                cout << setw(0) << i + 1 << setw(1) << "|" << setw(3);
            for (j = 0; j < width; j++)
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
void fieldopening(int& x, int& y, int length, int width)
{
    //Вибір місця, яке бажаємо перевірити
    cout << "Enter X you want to check: ";
    cin >> x;
    cout << endl;
    while (x < 0 || x > width)
    {
        cout << endl;
        cout << "Try again!" << endl;
        cout << endl << endl;
        cout << "Enter X you want to check: ";
        cin >> x;
        cout << endl;
    }
    cout << "Enter Y you want to check: ";
    cin >> y;
    cout << endl;
    while (y < 0 || y > length)
    {
        cout << endl;
        cout << "Try again!" << endl;
        cout << endl << endl;
        cout << "Enter Y you want to check: ";
        cin >> y;
        cout << endl;
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
    while (x < 0 || x > width)
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
    while (y < 0 || y > length)
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
bool action_choice(int x, int y, int** arr, int length, int width, int** check, bool &mistake, bool lose)
{
    string action;
    cout << endl;
    cout << "Choose an action: open a field (O) or put a flag (P): ";
    cin >> action;
    cout << endl;

    if (action == "o" || action == "O")
    {
        fieldopening(x, y, length, width);

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
void cleanram(int** arr, int** check, int length)
{
    for (int i = 0; i < length; ++i)
        delete[] arr[i];
    delete[] arr;

    for (int i = 0; i < length; ++i)
        delete[] check[i];
    delete[] check;
}

//Хід гри
int main()
{
    int length, width, i, j, mine_number, length_x_width;
    cout << "Saper v.1.5 (alpha)" << endl;

    //ГРА
    while (true)
    {
        size(length, width, mine_number, length_x_width);
        system("cls");
        cout << "New game" << endl << endl;
        //Генерація поля
        int** arr = arrfield(length, width, mine_number, length_x_width);
        int** check = arrcheck(length, width);
        bool checker = false, win = false, lose = false, mistake = false;
        while (!checker)
        {
            //Перевірка на відкриття усього поля
            coutfield(arr, check, length, width, lose, mistake);

            for (i = 0; i < length; i++)
            {
                for (j = 0; j < width; j++)
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
            if (checker)
                break;

            int x = 0, y = 0;

            if (action_choice(x, y, arr, length, width, check, mistake, lose))
                continue;

            if (!(action_choice(x, y, arr, length, width, check, mistake, lose)))
                break;
        }
        
        winner(checker, win, length, width, arr, check);
        cleanram(arr, check, length);

        //Рестарт гри (за бажанням гравця)
        bool stop = restart();
        if (stop)
            break;
        if (!stop)
            continue;
    }
    return 0;
}