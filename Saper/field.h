#pragma once
#include "constants_and_variables.h"

class Field
{
private:
    
    int** arr;
    parameters params;
    int* mines;
    int length_x_width;

    void create_array();
    void assign_array();
    void define_mines_position();
    void format_field();
    void put_number_of_mines();
    void set_numb_of_mines(int i, int j);
    void clean_resouce(int** arr, parameters& params);

public:
    //Функція для запису розмірів та кількості мін
    Field(){};
    void size();
    void create_field();
    void clean_ram(int** arr, int** check, parameters& params);
    parameters getParams();
    int** getArray();
};