#include "print_functions.h"
#include "actions.h"

string OPEN_ACTIONS = "Oo";
string FLAG_ACTIONS = "Pp";


void Action::check_input(string var_name, int& var, int comparator)
{
    Print p;
    cout << "Enter " << var_name << ": ";
    while (!(cin >> var) || var <= 0 || var > comparator)
        p.print_error();
}

void Action::get_coordinates(string action)
{   
    check_input("X", params.x, params.width);
    check_input("Y", params.y, params.length);
    
    params.x -= 1;
    params.y -= 1; 

    if (FLAG_ACTIONS.find(action) != string::npos)
        check[params.y][params.x] = FLAG;       
    
    system("cls");
  
}

//Функція для автоматичного відкривання поля, якщо обрано порожнє місце
void Action::autoopen(int x, int y)
{
    if (x < 0 || y < 0 || x >= params.width || y >= params.length || check[y][x] == CHECKED)
        return;

    check[y][x] = CHECKED;

    if (arr[y][x] == 0)
    {
        autoopen(x - 1, y - 1);
        autoopen(x, y - 1);
        autoopen(x + 1, y - 1);
        autoopen(x - 1, y);
        autoopen(x + 1, y);
        autoopen(x - 1, y + 1);
        autoopen(x, y + 1);
        autoopen(x + 1, y + 1);
    }
}

//Функція для обрання дії
bool Action::action_choice(bools& bool_params)
{
    Print p;
    params.x = 0;
    params.y = 0;
    string action;

    cout << endl;
    cout << "Choose an action: open a Field (O) or put a flag (P): ";
    cin >> action;

    if (OPEN_ACTIONS.find(action) != string::npos)
    {
        get_coordinates(action);

        //Якщо обрано порожнє місце
        if (arr[params.y][params.x] != MINE)
        {
            autoopen(params.x, params.y);
            return true;
        }
        //Якщо обрано місце з міною
        bool_params.lose = true;
        system("cls");
        p.print_board(arr, check, params, bool_params);
        p.print_lose();
        return false;
    }
    else if(FLAG_ACTIONS.find(action) != string::npos)
    {
        get_coordinates(action);
        return true;
    }
    cout << endl << "Try again!" << endl;
    bool_params.mistake = true;
    return true;
}

void Action::set_fields(parameters params_, int** arr_, int** check_)
{
    params = params_;
    arr = arr_;
    check = check_;

}