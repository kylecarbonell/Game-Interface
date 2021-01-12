#include "rock_paper_scissors.hpp"

#include <iostream>
#include <ctime>

using namespace std;

string changeToChoice(int ranNum) 
{
  string choiceName; 
  switch(ranNum)
  {
    case 0 : 
          choiceName = "Rock";
          break;
    case 1 : 
          choiceName = "Paper";
          break;
    case 2 : 
          choiceName = "Scissors";
          break;

  }

  return choiceName;
}

void RockPaperScissors()
{
   //Rock Paper Scissors game
   string choice = "";

    cout << "Please choose rock, paper, or scissors" << endl;
    cout << " " << endl;

    cin >> choice;

    cout << " " << endl;

    if(choice == ROCK || choice == PAPER || choice == SCISSORS)
    {
        cout << "You chose " << choice << endl;
        cout << " " << endl;
    }
    else
    {
        cout << "Invalid response" << endl;
    }

    cout << "Computer is now choosing..." << endl; 

    srand(time(0));
    int ranNum = rand() % 3;

    if(ranNum == 0 || ranNum == 1 || ranNum == 2)
    {
        cout << "Computer chose " << changeToChoice(ranNum) << endl;
        cout << " " << endl;
    }
    
    if (choice == ROCK)
    {
        if(ranNum == 0)
        {
            cout << "You both chose rock" << endl;
            cout << " " << endl;
            cout << "It is a tie!" << endl;
            cout << " " << endl;
        } 
        else if(ranNum == 1)
        {
            cout << "You chose rock and the computer chose paper" << endl;
            cout << "Paper beats rock! You lose!" << endl;
        }
        else 
        {
            cout << "You chose rock and the computer chose scissors" << endl;
            cout << "Rock beats scissors! You win!" << endl;
        }

        PlayAgain();
    }
    else if (choice == PAPER)
    {
        if(ranNum == 0)
        {
            cout << "You chose paper and the computer chose Rock" << endl;
            cout << "Paper beats rock! You Win!" << endl;
        }
        else if (ranNum == 1)
        {
            cout << "You chose paper and the Computer chose paper." << endl;
            cout << "Its a tie!" << endl;
        }
        else 
        {
            cout << "You chose paper and the Computer chose Scissors" << endl;
            cout << "Scissors beats paper! You lose!" << endl;
        }

        PlayAgain();
    }
    else
    {
        if(ranNum == 0)
        {
            cout << "You chose Scissors and the Computer chose Rock" << endl;
            cout << "Rock beats scissors! You lose!" << endl;
        }
        else if(ranNum == 1)
        {
            cout << "You chose Scissors and the computer chose paper" << endl;
            cout << "Scissors beats paper! You win!" << endl;
        }
        else 
        {
            cout << "You chose Scissors and the computer chose Scissors" << endl;
            cout << "It's a tie!" << endl;
        }

        PlayAgain();
    }      
}

void PlayAgain()
{
    char play_again;
    cout << endl;
    cout << "Would you like to play again?" << endl;
    cout << "Press 'm' if you would like to go back to the main menu" << endl;
    cin >> play_again;

    if(play_again == 'y')
    {
        RockPaperScissors();
    }
    else if (play_again == 'n')
    {
        cout << "Thanks for playing!" << endl;
    }
    else if (play_again == 'm')
    {
        cout << "Going back to the main menu...." << endl;
        cout << endl;
    }
    else
    {
        cout << "Please choose y or n or m" << endl;
    }
}
