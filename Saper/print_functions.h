#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string> 
#include "constants_and_variables.h"

using namespace std;

class Print
{
protected:
    //Функція для coutа поля

    void print_column_numbers(parameters& params);

    void print_line_numbers(int i);

    void print_empty_field(int i, int j, int** arr, int** check);

    void print_flag(int i, int j, int** check);

    void print_mines(int i, int j, int** check, int** arr, bools& bool_params);
        
public:
    void print_board(int** arr, int** check, parameters& params, bools& bool_params);


    void errors();


    void stripes();

    //Cout для Win
    void winner(bools& bool_params, parameters& params, int** arr, int** check);

    //Cout для Lose
    void loser();

};