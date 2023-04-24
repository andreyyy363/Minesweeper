#include "libraries.h"
#include "constants_and_variables.h"
#include "field.h"
#include "check_array.h"
#include "clean.h"

void Clean::clean_arr(int** arr, parameters & params)
{
    for (int i = 0; i < params.length; ++i)
        delete[] arr[i];
    delete[] arr;
}
void Clean::clean_check(int** check, parameters& params)
{

    for (int i = 0; i < params.length; ++i)
        delete[] check[i];
    delete[] check;
}

void Clean::clean_ram(int** arr, int** check, parameters& params)
{
    clean_arr(arr, params);
    clean_check(check, params);
}