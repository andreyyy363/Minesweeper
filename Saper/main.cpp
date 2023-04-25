#include "libraries.h"
#include "print_functions.h"
#include "field.h"
#include "actions.h"
#include "check_array.h"
#include "clean.h"
#include "restartr.h"

using namespace std;

//Хід гри
int main()
{
    parameters game_parameters;
    bools bool_parameters;
    Field f;
    Print p;
    Action a;
    Check ch;
    Clean c;
    int length_x_width;
    
    cout << "Saper v.1.5 (alpha)" << endl;

    //ГРА
    while (true)
    {
        f.size(game_parameters, length_x_width);
        system("cls");
        cout << "New game" << endl << endl;
        //Генерація поля
        int** arr = f.create_field(game_parameters);
        int** check = ch.arrcheck(game_parameters);
        bool_parameters.checker = false, bool_parameters.win = false;
        bool_parameters.lose = false, bool_parameters.mistake = false, bool_parameters.choice = false;
        while (!bool_parameters.checker)
        {
            //Перевірка на відкриття усього поля
            p.print_board(arr, check, game_parameters, bool_parameters);

            ch.check_field(arr, check, game_parameters, bool_parameters);
            if (bool_parameters.checker)
                break;

            bool_parameters.choice = a.action_choice(arr, game_parameters, check, bool_parameters);
            if (bool_parameters.choice)
                continue;
            else
                break;
        }

        p.winner(bool_parameters, game_parameters, arr, check);
        c.clean_ram(arr, check, game_parameters);

        //Рестарт гри (за бажанням гравця)
        
        if (restart())
            break;
    }
    return 0;
}