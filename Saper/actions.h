#pragma once
#include "constants_and_variables.h"

class Action
{
protected:
    //������� ��� �������� ����
    void open_field(parameters& params);
    //������� ��� ������������ �������
    void putflag(int** check, parameters& params);
    //������� ��� ������������� ���������� ����, ���� ������ ������ ����
    void autoopen(int x, int y, int** arr, parameters& params, int** check);
public:
    //������� ��� ������� 䳿
    bool action_choice(int** arr, parameters& params, int** check, bools& bool_params);

};