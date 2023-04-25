#pragma once
#include "constants_and_variables.h"

class Check
{
public:
    //Створення масиву для перевірки на відкритість поля
    int** arrcheck(parameters& params);
    //Функція для перевірки поля
    void check_field(int** arr, int** check, parameters& params, bools& bool_params);
};