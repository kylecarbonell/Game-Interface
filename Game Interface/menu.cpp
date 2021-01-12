#include <iostream>

using namespace std;

int printMenu()
{
    int test;
    cout << " " << endl;
    cout << "Main Menu" << endl;
    cout << "-------------- " << endl;
    cout << "0. QUIT" << endl;
    cout << "1. Rock Paper Scissors" << endl;
    cout << "2. Tic Tac Toe" << endl; 
    cout << endl;
    cout << "Choose your game (1-5)" << endl;
    cout << endl;

    cin >> test;
    return test;
}

void backToMenu()
{
    char ToMenu;
    cout << "Would you like to play again?" << endl;
    cin >> ToMenu;

    if (ToMenu == 'y')
    {
        printMenu();
    }
    else if(ToMenu == 'n')
    {
        cout << "Thanks for playing!!" << endl;
    }
    else
    {
        cout << "Please choose y or n" << endl;
    }
}

