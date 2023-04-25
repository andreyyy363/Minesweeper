#pragma once
#include "constants_and_variables.h"

class Action
{
protected:
    //Функція для відкриття поля
    void open_field(parameters& params);
    //Функція для встановлення прапора
    void putflag(int** check, parameters& params);
    //Функція для автоматичного відкривання поля, якщо обрано порожнє місце
    void autoopen(int x, int y, int** arr, parameters& params, int** check);
public:
    //Функція для обрання дії
    bool action_choice(int** arr, parameters& params, int** check, bools& bool_params);

};