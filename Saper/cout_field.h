#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//Функція для coutа поля
void coutfield(int** arr, int** check, int length, int width, bool lose, bool& mistake)
{
    int i, j;
    if (mistake == true)
    {
        mistake = false;
        return;
    }
    else
    {
        //Cout поля
        for (j = 0; j <= width; j++)
            cout << j << setw(5);
        cout << endl;

        for (j = 0; j <= (5 * width) - 3; j++)
            cout << "_";
        cout << endl;

        for (i = 0; i < length; i++)
        {
            if (i <= 8)
                cout << setw(0) << i + 1 << setw(2) << "|" << setw(3);
            else
                cout << setw(0) << i + 1 << setw(1) << "|" << setw(3);
            for (j = 0; j < width; j++)
            {
                if (check[i][j] == 1)
                {
                    if (arr[i][j] != MINE && arr[i][j] != 0)
                        cout << arr[i][j] << setw(5);
                    if (arr[i][j] != MINE && arr[i][j] == 0)
                        cout << "." << setw(5);
                }
                if (check[i][j] == FLAG)
                {
                    cout << "<|" << setw(5);
                }
                if (check[i][j] == NOTHING)
                {
                    if (arr[i][j] == MINE && lose == true)
                        cout << "*" << setw(5);
                    else
                        cout << "-" << setw(5);
                }
            }
            cout << " " << endl;
        }
    }
}