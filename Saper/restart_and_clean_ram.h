#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//Функція для рестарту гри
bool restart()
{
    string restart;
    bool stop;
    cout << "Do you want to play again? (Y/N): ";
    while (true)
    {
        cin >> restart;
        system("cls");
        if (restart == "y" || restart == "Y")
        {
            cout << endl;
            cout << "Good choice! :)";
            cout << endl;
            stop = false;
            break;
        }
        if (restart == "n" || restart == "N")
        {
            cout << endl;
            cout << "Okay, thanks for playing!";
            cout << endl;
            stop = true;
            break;
        }
        else
        {
            cout << endl << "Can you repeat?" << endl << "Do you want to play again? (Y/N): ";
            continue;
        }
    }
    return stop;
}

//Функція для очищення пам'яті
void cleanram(int** arr, int** check, int length)
{
    for (int i = 0; i < length; ++i)
        delete[] arr[i];
    delete[] arr;

    for (int i = 0; i < length; ++i)
        delete[] check[i];
    delete[] check;
}
