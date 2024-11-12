#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
using namespace std;

const int SIZE = 4;
char board[SIZE][SIZE];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
   char winner = ' ';
   char response = ' ';

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();

      while (winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();
         winner = checkWinner();
         if (winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();
         winner = checkWinner();
         if (winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (Y/N): ");
      scanf(" %c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("Thanks for playing!\n");
   return 0;
}

void resetBoard()
{
   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         board[i][j] = ' ';
      }
   }
}

void printBoard()
{
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         cout << " " << board[i][j] << " ";
         if (j < SIZE - 1) cout << "|";
      }
      cout << "\n";
      if (i < SIZE - 1) {
         for (int j = 0; j < SIZE; j++) {
            cout << "---";
            if (j < SIZE - 1) cout << "+";
         }
         cout << "\n";
      }
   }
   cout << "\n";
}

int checkFreeSpaces()
{
   int freeSpaces = SIZE * SIZE;

   for (int i = 0; i < SIZE; i++)
   {
      for (int j = 0; j < SIZE; j++)
      {
         if (board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}

void playerMove()
{
   int x, y;

   do
   {
      printf("Enter row #(1-4): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-4): ");
      scanf("%d", &y);
      y--;

      if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (true);
}

void computerMove()
{
   srand(time(0));
   int x, y;

   if (checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % SIZE;
         y = rand() % SIZE;
      } while (board[x][y] != ' ');

      board[x][y] = COMPUTER;
   }
}

char checkWinner()
{
   // Check rows
   for (int i = 0; i < SIZE; i++) {
      if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] != ' ') {
         return board[i][0];
      }
   }
   // Check columns
   for (int i = 0; i < SIZE; i++) {
      if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] != ' ') {
         return board[0][i];
      }
   }
   // Check diagonals
   if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] != ' ') {
      return board[0][0];
   }
   if (board[0][3] == board[1][2] && board[0][3] == board[2][1] && board[0][3] == board[3][0] && board[0][3] != ' ') {
      return board[0][3];
   }
   return ' ';
}

void printWinner(char winner)
{
   if (winner == PLAYER)
   {
      printf("YOU WIN!\n");
   }
   else if (winner == COMPUTER)
   {
      printf("YOU LOSE!\n");
   }
   else
   {
      printf("IT'S A TIE!\n");
   }
}
