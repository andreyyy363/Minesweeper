#include "field.h"
#include "check_array.h"
#include "clean.h"

void Clean::clean_resouce(int** resource, parameters& params)
{
    for (int i = 0; i < params.length; ++i)
        delete[] resource[i];
    delete[] resource;
}

void Clean::clean_ram(int** arr, int** check, parameters& params)
{
    clean_resouce(arr, params);
    clean_resouce(check, params);
}