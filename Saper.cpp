#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//Функція створення поля для гри
int **arrfield(const int l, const int w, int m, int lw)
{
    //Створення масиву для поля
    int **arr = new int*[l];
    for(int i = 0; i < l; ++i)
        arr[i] = new int[w];

    //Заповнення масиву від 1 до n
    int numb = 0;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < w; j++)
        {
            numb++;
            arr[i][j] = numb;
        }

    //Генерація чисел, які будуть мінами
    int mines[m], i, j;
    srand (time(NULL));

    for (i = 0; i < m ; i++)
    {
        mines[i] = rand() % lw + 1;
    }

    //Якщо номери сгенерованих мін повторюються
    int n = 0;
    for(j = 0; j < m - 1; j++)
    {
        n++;
        for(i = n; i < m - 1; i++)
            if(mines[j] == mines[i])
                mines[j] = rand() % lw + 1;
    }

    //Заміна номерів на 9 (*)
    for (int k = 0; k < m - 1; k++)
    {
        for(i = 0; i < l; i++)
        {
            for(j = 0; j < w; j++)
            {
                if(arr[i][j] == mines[k])
                {
                    arr[i][j] = 9;
                }
            }
        }
    }

    //Заміна номерів на 0 (.)
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(arr[i][j] != 9)
                arr[i][j] = 0;
        }
    }

    //Розміщення чисел, які позначають міни поблизу
    for (i = 0; i < l; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(arr[i][j] != 9)
            {
                if(i - 1 >= 0 && j - 1 >= 0)
                    if (arr[i - 1][j - 1] == 9)
                        arr[i][j] += 1;

                if(i - 1 >= 0)
                    if(arr[i - 1][j] == 9)
                        arr[i][j] += 1;

                if(i - 1 >= 0 && j + 1 < w)
                    if(arr[i - 1][j + 1] == 9)
                        arr[i][j] += 1;

                if(j - 1 >= 0)
                    if(arr[i][j - 1] == 9)
                        arr[i][j] += 1;

                if(j + 1 < w)
                    if(arr[i][j + 1] == 9)
                        arr[i][j] += 1;

                if(i + 1 < l && j - 1 >= 0)
                    if(arr[i + 1][j - 1] == 9)
                        arr[i][j] += 1;

                if(i + 1 < l)
                    if(arr[i + 1][j] == 9)
                        arr[i][j] += 1;

                if(i + 1 < l && j + 1 < w)
                    if(arr[i + 1][j + 1] == 9)
                        arr[i][j] += 1;
            }
        }
    }
    return arr;
}
//Створення масиву для перевірки на відкритість поля
int **arrcheck(const int l, const int w)
{
    int ** check = new int * [l];
    for(int i = 0; i < w; ++i)
        check[i] = new int[w];

    //Заповнення масиву нулями
    for(int i = 0; i < l; i++)
        for(int j = 0; j < w; j++)
                check [i][j] = 0;
    return check;
}
//Функція для запису розмірів та кількості мін
void size(int &l, int &w, int &m, int &lw)
{
    cout << "------------------------------" << endl;
    cout << "Please, enter field length (^) (8 - 30): ";
    cin >> l;
    cout << endl;
    while(l < 8 || l > 30)
    {
        cout << "Try again!" << endl;
        cout << endl;
        cout << "Please, enter field length (^) (8 - 30): ";
        cin >> l;
        cout << endl;
    }
    cout << "Please, enter field width (>) (8 - 30): ";
    cin >> w;
    cout << endl;
    while(w < 8 || w > 30)
    {
        cout << "Try again!" << endl;
        cout << endl;
        cout << "Please, enter field width (>) (8 - 30): ";
        cin >> w;
        cout << endl;
    }

    lw = l * w;

    cout << "Please, enter the number of mines (*) on the field (5 - " << lw - 10 << "): ";
    cin >> m;
    cout << endl;

    while(m < 5 || m > lw - 10)
    {
        cout << "Try again!" << endl;
        cout << endl;
        cout << "Please, enter the number of mines (*) on the field (5 - " << lw - 10 << "): ";
        cin >> m;
        cout << endl;
    }
}
//Функція для coutа поля
void coutfield(int ** arr, int ** check, int l, int w, bool lose, bool &mistake)
{
    int i, j;
    if(mistake == true)
    {
        mistake = false;
        return;
    }
    else
    {
        //Cout поля
        for (j = 0; j <= w; j++)
        cout << j << setw(5);
        cout << endl;

        for (j = 0; j <= 2.4 * w; j++)
            cout << "__";
        cout << endl;

        for (i = 0; i < l; i++)
        {
            if(i <= 8)
                cout  << setw(0) << i + 1 << setw(2) << "|" << setw(3);
            else
                cout  << setw(0) << i + 1 << setw(1) << "|" << setw(3);
            for (j = 0; j < w; j++)
            {
                if(check[i][j] == 1)
                {
                    if(arr[i][j] != 9 && arr[i][j] != 0)
                            cout << arr[i][j] << setw (5);
                    if(arr[i][j] != 9 && arr[i][j] == 0)
                            cout << "." << setw(5);
                }
                if(check[i][j] == 2)
                {
                    cout << "<|" << setw (5);
                }
                if (check[i][j] == 0)
                {
                    if(arr[i][j] == 9 && lose == true)
                        cout << "*" << setw(5);
                    else
                        cout << "-" << setw (5);
                }
            }
            cout << " " << endl;
        }
    }
}
//Функція для відкриття поля
void fieldopening(int &x, int &y, int l, int w)
{
    //Вибір місця, яке бажаємо перевірити
    cout << "Enter X you want to check: ";
    cin >> x;
    cout << endl;
    while(x < 0 || x > w)
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
    while(y < 0 || y > l)
    {
        cout << endl;
        cout << "Try again!" << endl;
        cout << endl << endl;
        cout << "Enter Y you want to check: ";
        cin >> y;
        cout << endl;
    }
    x -=1;
    y -=1;
    system("cls");
}
//Функція для встановлення прапора
void putflag(int ** check, int l, int w)
{
    int x, y;
    cout << "Enter X you want to put a flag: ";
    cin >> x;
    cout << endl;
    while(x < 0 || x > w)
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
    while(y < 0 || y > l)
    {
        cout << endl;
        cout << "Try again!" << endl;
        cout << endl << endl;
        cout << "Enter Y you want to put a flag: ";
        cin >> y;
        cout << endl;
    }
    x -=1;
    y -=1;
    system("cls");
    check[y][x] = 2;
}
//Функція для автоматичного відкривання поля, якщо обрано порожнє місце
void autoopen(int x, int y, int ** arr, int l, int w, int ** check)
{
    if (x < 0 || y < 0 || x >= w || y >= l)
        return;

    if (check[y][x] == 1)
        return;

    check[y][x] = 1;

    if (arr[y][x] == 0)
    {
        autoopen(x - 1, y - 1, arr, l, w, check);
        autoopen(x, y - 1, arr, l, w, check);
        autoopen(x + 1, y - 1, arr, l, w, check);
        autoopen(x - 1, y, arr, l, w, check);
        autoopen(x + 1, y, arr, l, w, check);
        autoopen(x - 1, y + 1, arr, l, w, check);
        autoopen(x, y + 1, arr, l, w, check);
        autoopen(x + 1, y + 1, arr, l, w, check);
    }
}
//Cout для Win
void winner()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
    cout << "##  ##    ## ##   ##  ###           ##   ##    ####   ###  ##              " << endl;
    cout << "##  ##   ##   ##  ##   ##           ##   ##     ##      ## ##          #   " << endl;
    cout << "##  ##   ##   ##  ##   ##           ##   ##     ##     # ## #      #    #  " << endl;
    cout << " ## ##   ##   ##  ##   ##           ## # ##     ##     ## ##             # " << endl;
    cout << "  ##     ##   ##  ##   ##           # ### #     ##     ##  ##      #    #  " << endl;
    cout << "  ##     ##   ##  ##   ##            ## ##      ##     ##  ##          #   " << endl;
    cout << "  ##      ## ##    ## ##            ##   ##    ####   ###  ##              " << endl;
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
}
//Cout для Lose
void loser()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
    cout << "##  ##    ## ##   ##  ###           ####      ## ##    ## ##   #### ##             " << endl;
    cout << "##  ##   ##   ##  ##   ##            ##      ##   ##  ##   ##  # ## ##           # " << endl;
    cout << "##  ##   ##   ##  ##   ##            ##      ##   ##  ####       ##         #   #  " << endl;
    cout << " ## ##   ##   ##  ##   ##            ##      ##   ##   #####     ##             #  " << endl;
    cout << "  ##     ##   ##  ##   ##            ##      ##   ##      ###    ##         #   #  " << endl;
    cout << "  ##     ##   ##  ##   ##            ##  ##  ##   ##  ##   ##    ##              # " << endl;
    cout << "  ##      ## ##    ## ##            ### ###   ## ##    ## ##    ####               " << endl;
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
}
//Функція для очищення пам'яті
void cleanram(int ** arr, int ** check, int l)
{
    for(int i = 0; i < l; ++i)
        delete[] arr[i];
    delete[] arr;

    for(int i = 0; i < l; ++i)
        delete[] check[i];
    delete[] check;
}
//Хід гри
int main()
{
    int l, w, i, j, m, lw;

    cout << "Saper v.1.0" << endl;

    //ГРА
    for(;;)
    {
        size(l, w, m, lw);
        system("cls");
        cout << "New game" << endl;
        cout << endl;

        //Генерація поля
        int **arr = arrfield(l, w, m, lw);
        int **check = arrcheck(l, w);

        bool checker = false, win = false, lose = false, mistake = false;
        while(checker == false)
        {
            //Перевірка на відкриття усього поля
            coutfield(arr, check, l, w, lose, mistake);

            for(i = 0; i < l; i++)
            {
                for(j = 0; j < w; j++)
                {
                    if(check[i][j] == 0)
                    {
                        if(arr[i][j] == 9)
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
                if (checker == false)
                    break;
            }
            if(checker == true)
                break;

            int x = 0, y = 0;
            char action;
            cout << endl;
            cout << "Choose an action: open a field (O) or put a flag (P): ";
            cin >> action;
            cout << endl;

            if (action == 'o' || action == 'O')
            {
                fieldopening(x, y, l, w);

                //Якщо обрано порожнє місце
                if(arr[y][x] != 9)
                {
                    autoopen(x, y, arr, l, w, check);
                    continue;
                }
                //Якщо обрано місце з міною
                else
                {
                    lose = true;
                    system("cls");
                    coutfield(arr, check, l, w, lose, mistake);
                    loser();
                    break;
                }
            }
            if(action == 'p' || action == 'P')
            {
                putflag(check, l, w);
                continue;
            }
            else
            {
                cout << endl << "Try again!" << endl;
                mistake = true;
                continue;
            }
        }
        //Перевірка на перемогу
        if(checker == true)
        {
            for(i = 0; i < l; i++)
            {
                for(j = 0; j < w; j++)
                {
                    if(check[i][j] == 2 && arr[i][j] == 9)
                        win = true;
                }
            }
        }
        if(win == true)
        {
            winner();
        }

        cleanram(arr, check, l);

        //Рестарт гри (за бажанням гравця)
        char restart;
        cout << "Do you want to play again? (Y/N): ";
        cin >> restart;

        if(restart == 'Y' || restart == 'y')
        {
            cout << endl;
            cout << "Good choice! :)";
            cout << endl;
            continue;
        }

        if(restart == 'N' || restart == 'n')
        {
            cout << endl;
            cout << "Okay, thanks for playing!";
            cout << endl;
            break;
        }
    }
    return 0;
}
