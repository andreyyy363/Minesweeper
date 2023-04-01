#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
const int MINE = 9, FLAG = 2, CHECKED = 1, NOTHING = 0;

//COUT ФУНКЦІЇ

//Cout помилки введення розміру та кількості мін
void errors(bool err_length, bool err_width, bool err_mines, bool err_coord_x, bool err_coord_y, bool err_coord_check, int length_x_width)
{
    cin.clear();
    fflush(stdin);
    cout << endl << "Try again!" << endl << endl;
    if (err_length)
        cout << "Please, enter field length (^) (8 - 30): ";
    if (err_width)
        cout << "Please, enter field width (>) (8 - 30): ";
    if (err_mines)
        cout << "Please, enter the number of mines (*) on the field (5 - " << length_x_width - 10 << "): ";
    if (err_coord_x || err_coord_y)
    {
        cout << "Enter ";
        if (err_coord_x)
            cout << "X ";
        else
            cout << "Y ";
        cout << "you want to ";
        if (err_coord_check)
            cout << "check: ";
        else
            cout << "put a flag: ";
    }
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
        for (i = 0; i < length; i++)
            for (j = 0; j < width; j++)
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