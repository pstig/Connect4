#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>




struct boardGraph{
  struct Move *head;
};

struct Move{
  int row;
  int column;
};

struct Edge{
  int srcRow, srcColumn;
  int destRow, destColumn;
};


// int minimax(int depth, int moveID, bool isP1, int scores[columns], int maxH);   /******Write This****************/
// int evaluateBoard(int board[rows][columns]);                                    /******Write This****************/
// int buildGraph(int board[rows][columns]);                                       /******Write This******Maybe?*****/

void printBoard(char **board, int rows, int columns);
void playerMove(char **board, int *playerC, int j, int rows, int columns);

int main() {

  /*variable initialization*/
  int rows;
  int columns;
  char *ptr;
  char **board;
  int count = 0,i,j;
  int playerC = 0;
  int playerM;
  int comp;

  /*Get board size*/
  printf("Enter Board height (rows)");
  scanf("%d", &rows);
  printf("Enter Board width (columns)");
  scanf("%d", &columns);

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
   printf("Tristan's Super Gay Connect 4! (Fixed by Peter)\n \n");
   printBoard(board, rows, columns);
   int scores[columns];
   while(1){
     if (playerC == 0)
      printf("\n Player 1's turn. Pick a row\n");
    if (playerC == 1)
      printf("\n Player 2's turn. Pick a row\n");
     scanf("%d", &playerM);
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
      if (board[i][j] == ' '){
        if (*playerC == 0)
          board[i][j] = 'X';
        if (*playerC == 1)
          board[i][j] = 'O';
        return;
      }
      else if (board[0][j] != ' '){
        printf("\nInvalid Move");
        printf("\nChoose a new move: ");
        scanf("%d", &j);
        j = j -1;
        i = rows;
      }
    }
  }

}
