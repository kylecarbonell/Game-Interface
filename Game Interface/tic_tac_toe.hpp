#include <iostream>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;
const char SPACE = ' ';
const char X = 'x';
const char O = 'o';

const string noDone = "not done";
const string not_done = "No";
const string done = "done";
const string finished = "done";

char board[ROWS][COLUMNS] =  
{
    {SPACE, SPACE, SPACE},
    {SPACE, SPACE, SPACE},
    {SPACE, SPACE, SPACE}
};

void printBoard(char board[ROWS][COLUMNS]);
void playerMove(char board[ROWS][COLUMNS], char piece);
void computerMove (char board[ROWS][COLUMNS], char piece);
void playerMove2(char board[ROWS][COLUMNS], char piece);
void Again();

bool checkRows(char board[ROWS][COLUMNS], char piece);
bool checkColumns(char board[ROWS][COLUMNS], char piece);
bool checkDiagonals(char board[ROWS][COLUMNS], char piece);
bool Winner(char board[ROWS][COLUMNS], char piece);
bool fullBoard(char board[ROWS][COLUMNS]);

string DetermineBoardStatePvP(char board[ROWS][COLUMNS]);
string DetermineBoardStatePvC(char board[ROWS][COLUMNS]);


void tictactoe();
void tictactoeplayer();
void resetBoard(char board[ROWS][COLUMNS]);



