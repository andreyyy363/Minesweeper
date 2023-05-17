#pragma once
#include "constants_and_variables.h"

class Action
{
private:
    int** arr;
    int** check;
    parameters params;

    void check_input(string var_name, int& var, int comparator);
    //������� ��� ������������ �������
    void coordinates(string action);
    //������� ��� ������������� ���������� ����, ���� ������ ������ ����
    void autoopen(int x, int y);

public:
    //������� ��� ������� 䳿
    bool action_choice(bools& bool_params);
    void set_fields(parameters, int**, int**);

};