#pragma once
#include "constants_and_variables.h"

class Clean
{
protected:
    void clean_arr(int** arr, parameters& params);

    void clean_check(int** check, parameters& params);

public:
    void clean_ram(int** arr, int** check, parameters& params);

};