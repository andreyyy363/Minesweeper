#pragma once
#include "constants_and_variables.h"

class Check
{
public:
    //��������� ������ ��� �������� �� ��������� ����
    int** arrcheck(parameters& params);
    //������� ��� �������� ����
    void check_field(int** arr, int** check, parameters& params, bools& bool_params);
};