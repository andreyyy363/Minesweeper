#pragma once
#include "constants_and_variables.h"

class Action
{
private:
    int** arr;
    int** check;
    parameters params;

    void check_input(string var_name, int& var, int comparator);
    //Функція для встановлення прапора
    void coordinates(string action);
    //Функція для автоматичного відкривання поля, якщо обрано порожнє місце
    void autoopen(int x, int y);

public:
    //Функція для обрання дії
    bool action_choice(bools& bool_params);
    void set_fields(parameters, int**, int**);

};