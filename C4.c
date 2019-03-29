#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


struct boardGraph{
  struct Move *head;
};

struct Move{
  int row;
  int column;
};

/*DFS on board states to find best move*/
int minimax(int depth, int move, bool isMax);
/*Used to evaulate the score for a given move*/
int positionScore(int **board);
//Prints Board after Each Move
void printBoard(char **board, int rows, int columns);
//Handles adding player move to the board
void playerMove(char **board, int *playerC, int j, int rows, int columns);

int main() {

  /*variable initialization*/
  int rows;
  int columns;
  char **board;
  int i,j;
  int playerC = 0;
  int playerM;
  char temp[100];

  /*Get board size*/
  /*All user inputs are scanned in as a string then converted to an int with atoi()
  **that int value is then compared to the conditions nessicary for that variable*
  **if the value is not valid it will keep asking for a valid input until one is given*/
  printf("Enter Board height (rows): ");
  scanf("%s", temp);
  rows = atoi(temp);
  while (rows <= 4){
    printf("Please Enter a Number greater than 3: ");
    scanf("%s", temp);
    rows = atoi(temp);
  }
  printf("Enter Board width (columns): ");
  scanf("%s", temp);
  columns = atoi(temp);
  while (columns <= 4){
    printf("Please Enter a Number greater than 3: ");
    scanf("%s", temp);
    columns = atoi(temp);
  }

  /*Allocate Board array*/
  board = malloc(rows * sizeof(char*));
  for ( i = 0; i < rows; i++ ) {
    board[i] = malloc(columns * sizeof(char));
  }

  /*set array to empty*/
  for(i=0; i<rows; i++) {
     for(j=0;j<columns;j++) {
       board[i][j] = ' ';
     }
  }

  /*Game Start*/
   printf("Connect 4\n \n");
   printBoard(board, rows, columns);
   while(1){
     if (playerC == 0)
      printf("\n Player 1's turn. Pick a row\n");
    if (playerC == 1)
      printf("\n Player 2's turn. Pick a row\n");
    scanf("%s", temp);
    playerM = atoi(temp);
    while (playerM < 1 || playerM > columns){
      printf("Invalid Move\n");
      printf("Please choose another move: ");
      scanf("%s", temp);
      playerM = atoi(temp);
    }
     playerMove(board, &playerC, playerM, rows, columns);
     printBoard(board, rows, columns);
     playerC = !(playerC);
   }


   return 0;
}

void printBoard(char** board, int rows, int columns){
  for(int q = 0; q < columns; q++){
    printf("|%d", q + 1);
  }
  printf("|\n");
  for(int i=0; i<rows; i++) {
     for(int j=0;j<columns;j++) {
      printf("|%c", board[i][j]);
     }
     printf("| \n");
  }
  return;
}

void playerMove(char **board, int *playerC, int j, int rows, int columns){

  int move = 0;
  while(move == 0){
    j = j - 1;
    for(int i = rows-1; i >= 0 ; i--){
      if (board[0][j] != ' ' || j >= columns || j < 0){  //Checks to make sure number is a valid move
        printf("\nInvalid Move");
        printf("\nChoose a new move: ");
        scanf("%d", &j);
        j = j -1;
        i = rows;
      }
      else if (board[i][j] == ' '){
        if (*playerC == 0)
          board[i][j] = 'X';
        if (*playerC == 1)
          board[i][j] = 'O';
        return;
      }
    }
  }
}

int minimax(int depth, int move, bool isMax){
  return 0;
}

int positionScore(int **board){
  return 0;
}
