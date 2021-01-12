#include "tic_tac_toe.hpp"

using namespace std;

void printBoard (char board[ROWS][COLUMNS])
{
  for (int i = 0; i < 1; i++) 
  {
    for (int j = 0; j < 1; j++)
      {
        cout << endl;
        cout << board[0][0] << "  | " << board[0][1] << " |  " << board[0][2] << endl; 
                                  cout << "---+---+---" << endl;
        cout << board[1][0] << "  | " << board[1][1] << " |  " << board[1][2] << endl;
                                  cout << "---+---+---" << endl;
        cout << board[2][0] << "  | " << board[2][1] << " |  " << board[2][2] << endl;

        cout << endl;
      }
  }
}

bool Winner (char board[ROWS][COLUMNS], char piece)
{
  if (checkRows (board, piece) == true || checkColumns (board, piece) == true || checkDiagonals (board, piece) == true) 
  {
    return true;
  }

  return false;
}

bool checkRows (char board[ROWS][COLUMNS], char piece)
{
  for (int i = 0; i < ROWS; i++)
  {
    if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece)
    {
      return true;
    }
  }  

  return false;
}

bool checkColumns (char board[ROWS][COLUMNS], char piece)
{
  for (int j = 0; j < ROWS; j++)
  {
    if (board[0][j] == piece && board[1][j] == piece && board[2][j] == piece)
    {
      return true;
    }
  }
  
  return false;
}

bool checkDiagonals (char board[ROWS][COLUMNS], char piece)
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLUMNS; j++)
    {
      if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece)
      {
        return true;
      }
      else if (board[0][2] == piece && board[1][1] == piece && board[2][0] == piece)
      {
        return true;
      }
    }
  }

  return false;
}

bool fullBoard(char board[ROWS][COLUMNS])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j ++)
    {
      if(board[i][j] == SPACE)
      {
        return false;
      }
    }
  }

  return true;
}
 
void playerMove(char board[ROWS][COLUMNS], char piece)
{
  int i, j;

  do
  {
    cout << "Please choose a row!" << endl;
    cin  >> i;
    cout << "Please choose a column!" << endl;
    cin >> j;

    if (i < 0 || i > 2 || j < 0 || j > 2)
    {
      cout << "This is not a space!!" << endl;
      cout << "Please choose a valid space!" << endl;
      cout << endl;
    }
    else if (board[i][j] != SPACE)
    {
      cout << "This space is taken" << endl;
      cout << "Please choose another space!" << endl;
      cout << endl;
      printBoard(board);
    }
    else if (board[i][j] == SPACE)
    {
      board[i][j] = piece;
      printBoard(board);
      break;
    }
  } while(board[i][j] != SPACE);
}

void playerMove2(char board[ROWS][COLUMNS], char piece)
{
  int i, j;

  do
  {
    cout << "Please choose a row!" << endl;
    cin  >> i;
    cout << "Please choose a column!" << endl;
    cin >> j;

    if (i < 0 || i > 2 || j < 0 || j > 2)
    {
      cout << "This is not a space!!" << endl;
      cout << "Please choose a valid space!" << endl;
      cout << endl;
    }
    else if (board[i][j] != SPACE)
    {
      cout << "This space is taken" << endl;
      cout << "Please choose another space!" << endl;
      cout << endl;
      printBoard(board);
    }
    else if (board[i][j] == SPACE)
    {
      board[i][j] = piece;
      printBoard(board);
      break;
    }
  } while(board[i][j] != SPACE);
}

void computerMove(char board[ROWS][COLUMNS], char piece)
{
  int onechoice;
  int twochoice;
  srand(time(0));

  do
  {
    onechoice = rand() % 3;
    twochoice = rand() % 3;
  
    if (board[onechoice][twochoice] == SPACE)
    {
      board[onechoice][twochoice] = piece;

      break;
    }
  } while (board[onechoice][twochoice] != SPACE);

  printBoard(board);
}

string DetermineBoardStatePvP(char board[ROWS][COLUMNS])
{

  if(Winner(board, X) == true)
  {
    cout << "HAHAAH THE OTHER GUY SUCKS!! PLAYER WINS" << endl;
    cout << endl;

    return noDone;
  }
  else if (Winner(board, O) == true)
  {
    cout << "BRO YOU SUCK! PLAYER 2 WINS!!" << endl;
    cout << endl;

    return noDone;
  }
  else if (fullBoard(board) == true)
  {
    cout << "The board is full!!" << endl; 
    cout << "Its a draw" << endl;
    cout << endl;

    return noDone;
  }
  
  return finished;
}

string DetermineBoardStatePvC(char board[ROWS][COLUMNS])
{ 
  
  if(Winner(board, X) == true)
  {
    cout << "HAHAAH THE COMPUTER SUCKS!! PLAYER WINS" << endl;
    cout << endl;

    return done;
  }
  else if (Winner(board, O) == true)
  {
    cout << "BRO YOU SUCK! U LOST TO A BOT! YOU SUCK COMPUTER WINS!" << endl;
    cout << endl;

    return done;
  }
  else if (fullBoard(board) == true)
  {
    cout << "The board is full!!" << endl; 
    cout << "Its a draw" << endl;
    cout << endl;

    return done;
  }

  return not_done;
}

void tictactoe()
{
    string outcome;

    printBoard(board);
    do
    {
      playerMove(board, X);
      outcome = DetermineBoardStatePvC(board);
      computerMove(board, O);
      outcome = DetermineBoardStatePvC(board);

    }while(outcome == not_done);

   Again();
}

void tictactoeplayer()
{
    string out;

    printBoard(board);
    do
    {
      playerMove(board, X);
      out = DetermineBoardStatePvP(board);
      if (out == noDone)
      {
        break; 
      }
      playerMove2(board, O);
      out = DetermineBoardStatePvP(board);
      if (out == noDone)
      {
        break;
      }
    }while(out == done);  
    
    Again();
}

void Again()
{
    int decision = 0;
    char play_again;
    cout << endl;
    cout << "Would you like to play again?" << endl;
    cout << "Press c for computer option and p for player option!" << endl;
    cout << "Press 'm' if you would like to go back to the main menu" << endl;
    cin >> play_again;

    if(play_again == 'c')
    {
      resetBoard(board);
      tictactoe();
    }
    else if (play_again == 'p')
    {
      printBoard(board);
      tictactoeplayer();
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

void resetBoard(char board[ROWS][COLUMNS])
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    { 
      board[i][j] = SPACE;
    }
  }
}
