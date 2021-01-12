#include "rock_paper_scissors.cpp"
#include "tic_tac_toe.cpp"
#include "menu.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
 int decision;
 do
 {
    int decision = printMenu();
    string choice;

    if (decision == 0) //Quit button
    {
      cout << "Thanks for playing!!" << endl;

      return 0;
    }
    else if(decision == 1) //Rock Paper Scissors
    {
      RockPaperScissors();
    }
    else if(decision == 2)   //Tic Tac Toe
    {
      char cpuPlayer;
      cout << "Would you like to play against a player or a cpu?" << endl;
      cout << "Please choose p or c?" << endl;
      cin >> cpuPlayer;

        if (cpuPlayer == 'c')
        {
          tictactoe();
        }
        else if (cpuPlayer == 'p')
        {
          tictactoeplayer();
        }
        else
        {
          cout << "Please choose p or c!" << endl;
        }
    }

  }while (decision != 0);
}
  



