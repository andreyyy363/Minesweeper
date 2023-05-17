#pragma once
#include "constants_and_variables.h"

class Check
{
private:
    parameters params;

public:
    Check(parameters& params);
    Check(){};

    //Створення масиву для перевірки на відкритість поля
    int** arrcheck();
    //Функція для перевірки поля
    void check_field(int** arr, int** check, bools& bool_params);
    void check_win(bools& bool_params, int** arr, int** check);
};