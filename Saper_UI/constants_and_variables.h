#pragma once
const int MINE = 9, FLAG = 2, CHECKED = 1, NOTHING = 0;
int const MIN_AVAILABLE_CELLS = 10;
int const MIN_AMOUNT_MINES = 5;
int const MIN_FIELD_SIZE = 8;
int const MAX_FIELD_SIZE = 30;

struct parameters
{
    int length, width, mine_number, number_of_cells, x, y;
};

struct bools
{
    bool checker, win, lose, mistake, choice;
};