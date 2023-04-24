#include "print_functions.h"
#include "constants_and_variables.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string> 

using namespace std;

void Print::print_column_numbers(parameters& params)
{
    int j;
    for (j = 0; j <= params.width; j++)
        cout << j << setw(5);
    cout << endl;
    for (j = 0; j <= (5 * params.width) - 3; j++)
        cout << "_";
    cout << endl;
}
void Print::print_line_numbers(int i)
{
    if (i <= 8)
        cout << setw(0) << i + 1 << setw(2) << "|" << setw(3);
    else
        cout << setw(0) << i + 1 << setw(1) << "|" << setw(3);
}

void Print::print_empty_field(int i, int j, int** arr, int** check)
{
    if (check[i][j] == 1)
    {
        if (arr[i][j] != MINE && arr[i][j] != 0)
            cout << arr[i][j] << setw(5);
        if (arr[i][j] != MINE && arr[i][j] == 0)
            cout << "." << setw(5);
    }
}

void Print::print_flag(int i, int j, int** check)
{
    if (check[i][j] == FLAG)
    {
        cout << "<|" << setw(5);
    }
}
void Print::print_mines(int i, int j, int** check, int** arr, bools& bool_params)
{
    if (check[i][j] == NOTHING)
    {
        if (arr[i][j] == MINE && bool_params.lose == true)
            cout << "*" << setw(5);
        else
            cout << "-" << setw(5);
    }
}

void Print::print_board(int** arr, int** check, parameters& params, bools& bool_params)
{
    int i, j;
    if (!bool_params.mistake)
    {
        //Cout ����
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

void Print::errors()
{
    cin.clear();
    fflush(stdin);
    cout << endl << "Try again: ";
}

void Print::stripes()
{
    cout << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << endl;
}
//Cout ��� Win
void Print::winner(bools& bool_params, parameters& params, int** arr, int** check)
{
    int i, j;
    //�������� �� ��������
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
//Cout ��� Lose
void Print::loser()
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
