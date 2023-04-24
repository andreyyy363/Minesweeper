#pragma once
#include "constants_and_variables.h"

class Field
{
protected:
    int** create_array(parameters& params);
    int** assign_array(int** arr, parameters& params);
    int* define_mines_position(parameters& params);
    int** format_field(int** arr, int* mines, parameters& params);
    int** put_number_of_mines(int** arr, int* mines, parameters& params);
public:
    //������� ��� ������ ������ �� ������� ��
    void size(parameters& params, int& length_x_width);
    int** create_field(parameters& params);

};