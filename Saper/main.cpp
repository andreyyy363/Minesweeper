#include "libraries.h"
#include "print_functions.h"
#include "field.h"
#include "actions.h"
#include "check_array.h"
#include "restart.h"

using namespace std;

//Хід гри
int main()
{
    parameters game_parameters;
    bools bool_parameters;
    Field f = Field();
    Print p;
    Action a = Action();
    Check ch;
    
    cout << "Saper v.1.5 (pre-release)" << endl;

    //ГРА
    while (true)
    {
        f.size();
        system("cls");
        cout << "New game" << endl << endl;
        //Генерація поля
        f.create_field();
        game_parameters = f.getParams();
        ch = Check(game_parameters);
        int** check = ch.check_arr();
        bool_parameters.checker = false, bool_parameters.win = false;
        bool_parameters.lose = false, bool_parameters.mistake = false, bool_parameters.choice = false;
        while (!bool_parameters.checker)
        {
            //Перевірка на відкриття усього поля
            p.print_board(f.getArray(), check, game_parameters, bool_parameters);

            ch.check_field(f.getArray(), check, bool_parameters);
            if (bool_parameters.checker)
                break;

            a.set_fields(game_parameters, f.getArray(), check);
            bool_parameters.choice = a.action_choice(bool_parameters);
            if (bool_parameters.choice)
                continue;
            break;
        }

        ch.check_win(bool_parameters, f.getArray(), check);
        p.print_win(bool_parameters);
        f.clean_ram(f.getArray(), check, game_parameters);

        //Рестарт гри (за бажанням гравця)
        
        if (restart())
            break;
    }
    return 0;
}