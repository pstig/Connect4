#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>



/*DFS on board states to find best move*/
int minimax(int depth, char **board, bool isMax, int rows, int columns);
/*Used to evaulate the score for a given move*/
int positionScore(char **board, int rows, int columns, int player);
//Prints Board after Each Move
void printBoard(char **board, int rows, int columns);
//Handles adding player move to the board
void playerMove(char **board, int playerC, int j, int rows, int columns, bool isComp);
//Checks if move is valid
int isValidMove(char **board, int rows, int columns, int c);
//Checks to see if a player won in 2 player
int checkWin(char **board, int rows, int columns);

int calcBestMove(char **board, int rows, int columns);

//char ** boardCopy(char **old, int c, char p, int rows);
//Simple functions to find min and max
int max(int a, int b ) { return a > b ? a : b; }
int min(int a, int b ) { return a < b ? a : b; }

int main() {

  /*variable initialization*/
  int rows;
  int columns;
  char **board;
  char **boardCopy;
  int i,j;
  int playerC = 0;
  int playerM;
  char temp[100];
  int p1score = 0;
  int p2score = 0;
  int comp;
  int playAgain;
  int movesLeft;

  /*Get board size*/
  /*All user inputs are scanned in as a string then converted to an int with atoi()
  **that int value is then compared to the conditions nessicary for that variable*
  **if the value is not valid it will keep asking for a valid input until one is given*/
  printf("Connect 4\n \n");
  printf("Enter 1 to play against the computer or 2 to play against a friend: ");
  scanf("%s", temp);
  comp = atoi(temp);
  while (comp != 1 && comp != 2){
    printf("Please Enter 1 or 2: ");
    scanf("%s", temp);
    comp = atoi(temp);
  }
  printf("Enter Board height (rows) (6 is recommended): ");
  scanf("%s", temp);
  rows = atoi(temp);
  while (rows <= 4){
    printf("Please Enter a Number greater than 3: ");
    scanf("%s", temp);
    rows = atoi(temp);
  }
  printf("Enter Board width (columns) (7 is recommended): ");
  scanf("%s", temp);
  columns = atoi(temp);
  while (columns <= 4){
    printf("Please Enter a Number greater than 3: ");
    scanf("%s", temp);
    columns = atoi(temp);
  }


  /*Allocate Board array*/
  board = malloc(rows * sizeof(char*));
  for (i = 0; i < rows; i++ ) {
    board[i] = malloc(columns * sizeof(char));
  }

  /*set array to empty*/
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      board[i][j] = ' ';
    }
  }

  boardCopy = malloc(rows * sizeof(char*));
  for (i = 0; i < rows; i++ ) {
    boardCopy[i] = malloc(columns * sizeof(char));
  }

  /*set array to empty*/
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      boardCopy[i][j] = ' ';
    }
  }

  /*Game Start*/
  movesLeft = rows * columns;
  //1 Player
  if (comp == 1) {
    int win = -1;
    printf("Connect 4\n \n");
    printBoard(board, rows, columns);
    while(win == -1){
      if (playerC == 0){
        printf("\nYour turn. Pick a row: \n");
        scanf("%s", temp);
        playerM = atoi(temp);
        while (playerM < 1 || playerM > columns){
          printf("Invalid Move\n");
          printf("Please choose another move: ");
          scanf("%s", temp);
          playerM = atoi(temp);
        }
        playerMove(board, playerC, playerM, rows, columns, false);
        for (i = 0; i < rows; i++) {
          for (j = 0; j < columns; j++) {
            boardCopy[i][j] = board[i][j];
          }
        }
        printBoard(board, rows, columns);
        playerC = !(playerC);
        movesLeft--;
    }
      else if (playerC == 1){
        printf("\nComputer is playing\n");
        playerM = calcBestMove(boardCopy, rows, columns);
        for (i = 0; i < rows; i++) {
          for (j = 0; j < columns; j++) {
            boardCopy[i][j] = ' ';
          }
        }
        playerMove(board, playerC, playerM, rows, columns, true);
        printBoard(board, rows, columns);
        playerC = !(playerC);
        movesLeft--;
      }

      win = checkWin(board, rows, columns);

      if (win == 1000) {
        printf("Player 1 Won!\n");
        p1score++;
      }
      if (win == -1000){
        printf("The Computer Won!\n");
        p2score++;
      }
      if (movesLeft == 0){
        printf("It was a Tie!");
        win = -2;
      }
      if (win == -1000 || win == 1000 || win == -2 ) {
          printf("Score\n");
          printf("P1 %d -- %d P2\n", p1score, p2score);
          printf("Would you like to play again? (1 for Yes - 2 for No): ");
          scanf("%s", temp);
          playAgain = atoi(temp);
          while (playAgain != 1 && playAgain != 2){
            printf("Please Enter 1 or 2: ");
            scanf("%s", temp);
            playAgain = atoi(temp);
          }
          if (playAgain == 1){
            for (i = 0; i < rows; i++) {
              for (j = 0; j < columns; j++) {
                board[i][j] = ' ';
              }
            }
            win = -1;
            playerC = 0;
            printf("Connect 4\n \n");
            printBoard(board, rows, columns);
          }
        }
    }

  }

//2 player
  if (comp == 2) {

    int win = -1;
    printf("Connect 4\n \n");
    printBoard(board, rows, columns);
    while(win == -1){

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
      playerMove(board, playerC, playerM, rows, columns, false);
      printBoard(board, rows, columns);
      playerC = !(playerC);


      win = checkWin(board, rows, columns);

      if (win == 1000) {
        printf("Player 1 Won!\n");
        p1score++;
      }
      if (win == -1000){
        printf("Player 2 Won!\n");
        p2score++;
      }
      if (movesLeft == 0){
        printf("It was a Tie!");
        win = -2;
      }
      if (win == -1000 || win == 1000 || win == -2 ) {
          printf("Score\n");
          printf("P1 %d -- %d P2\n", p1score, p2score);
          printf("Would you like to play again? (1 for Yes - 2 for No): ");
          scanf("%s", temp);
          playAgain = atoi(temp);
          while (playAgain != 1 && playAgain != 2){
            printf("Please Enter 1 or 2: ");
            scanf("%s", temp);
            playAgain = atoi(temp);
          }
          if (playAgain == 1){
            for (i = 0; i < rows; i++) {
              for (j = 0; j < columns; j++) {
                board[i][j] = ' ';
              }
            }
            win = -1;
            playerC = 0;
            printf("Connect 4\n \n");
            printBoard(board, rows, columns);
          }
        }
    }

  }
  free(board);
  return 0;
}

void printBoard(char** board, int rows, int columns){
  for (int q = 0; q < columns; q++){
    printf("|%d", q + 1);
  }
  printf("|\n");
  for (int i = 0; i < rows; i++) {
     for (int j = 0; j < columns; j++) {
      printf("|%c", board[i][j]);
     }
     printf("| \n");
  }
  return;
}

void playerMove(char **board, int playerC, int j, int rows, int columns, bool isComp){

  int move = 0;
  while(move == 0){
    j = j - 1;
    if (isComp == false){
      for(int i = rows - 1; i >= 0 ; i--){
        if (board[0][j] != ' ' || j >= columns || j < 0){  //Checks to make sure number is a valid move
          printf("\nInvalid Move");
          printf("\nChoose a new move: ");
          scanf("%d", &j);
          j = j -1;
          i = rows;
        }
        else if (board[i][j] == ' '){
          if (playerC == 0)
            board[i][j] = 'X';
          if (playerC == 1)
            board[i][j] = 'O';
          return;
        }
      }
    }
    if (isComp == true){
      for(int i = rows - 1; i >= 0 ; i--){
        if (board[i][j] == ' '){
          if (playerC == 0){
            board[i][j] = 'X';
            move = 1;
          }
          if (playerC == 1){
            board[i][j] = 'O';
            move = 1;
          }
          return;
        }
      }
    }
  }
  return;
}

/*Minimax function handles score comparison while positionScore handles the score for an individual move*/

/*Player 1 is always maximizing player
**Player 2 is always minimizing player
**Depth is the number of moves ahead to look
**move is the column number of the move*/
int minimax(int depth, char **boardCopy, bool isMax, int rows, int columns){
  int player;
  if (isMax == true) player = 0;
  if (isMax == false) player = 1;
  if (depth == 0)
    return checkWin(boardCopy, rows, columns);

  if (isMax == true) {
    int maxEval = -1000;
    for (int i = 1; i <= columns; i++){
      if (isValidMove(boardCopy, rows, columns, i) == 1){
        playerMove(boardCopy, player, i, rows, columns, true);
        int eval = minimax(depth - 1, boardCopy, false, rows, columns);
        maxEval = max(maxEval, eval);
      }
    }
    return maxEval;
  }

  if(isMax == false) {
    int minEval = 1000;
    for (int i = 1; i <= columns; i++){
      if (isValidMove(boardCopy, rows, columns, i) == 1){
        playerMove(boardCopy, player, i, rows, columns, true);
        int eval = minimax(depth -1, boardCopy, true, rows, columns);
        minEval = min(minEval, eval);
      }
    }
    return minEval;
  }

}

/*board is the current board state for the move you are looking at
**c gives the column number of the move to score
returns the score of the move to minimax function*/
// int positionScore(char **board, int rows, int columns, int player){
//    int score = 0;
//
//
//   return score;
// }

int checkWin(char **board, int rows, int columns){
  int nir = 1;

  //horizontal win checkWin
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = 0; j < columns; j++) {
      // printf("(1) (%d,%d) -> (%d,%d) ", i, j, i, j+1);
      // printf("%d == %d ", board[i][j], board[i][j+1]);
      // printf("nir = %d\n", nir);
      if (board[i][j] == board[i][j+1] && board[i][j] != ' ')
        nir++;
      else
        nir = 1;
      if (nir == 4 && board[i][j] == 'X')
        return 1000;
      if (nir == 4 && board[i][j] == 'O')
        return -1000;
    }
  }
  nir = 1;
  //vertical win check
  for (int j = 0; j < columns; j++) {
    for (int i = rows - 1; i > 0; i--) {
      // printf("(2) ");
      // printf("%d == %d ", board[i][j], board[i-1][j]);
      // printf("%d\n", nir);
      if (board[i][j] == board[i-1][j] && board[i][j] != ' ')
        nir++;
      else
        nir = 1;
      if (nir == 4 && board[i][j] == 'X')
        return 1000;
      if (nir == 4 && board[i][j] == 'O')
        return -1000;

    }
  }

  int d = min(rows, columns);
  int diag[d];
  memset(diag, 0, sizeof diag);
  int p = 0;

  //Positive diagonal win check
  for (int k = 0; k <= rows + columns - 2; k++){
    for (int j = 0; j <= k; j++){
      int i = k - j;
      if (i < rows && j < columns){
        diag[p] = board[i][j];
        p++;
      }
    }
    p = 0;
    for (int q = 0; q < rows; q++){
      // printf("%d-%d ", diag[q], nir);
      if (diag[q] == diag[q+1] && diag[q] != ' ' && diag[q] != 0)
        nir++;
      else
        nir = 1;
      if (nir == 4 && diag[q] == 'X')
        return 1000;
      if (nir == 4 && diag[q] == 'O')
        return -1000;

    }
    memset(diag, 0, sizeof diag);
    // printf("\n");
  }


  nir = 1;

  //Negative diagonal win check
  for (int i = rows - 1; i >= 0; i--){
    for (int j = 0; j < rows; j++){
      int k = i + j;
      if ((k < rows) && (j < columns)) {
        diag[p] = board[k][j];
        p++;
      }
  }
  p = 0;
  for (int q = 0; q < rows; q++){
    if (diag[q] == diag[q+1] && diag[q] != ' ' && diag[q] != 0)
      nir++;
    else
      nir = 1;
    if (nir == 4 && diag[q] == 'X')
      return 1000;
    if (nir == 4 && diag[q] == 'O')
      return -1000;
  }
    memset(diag, 0, sizeof diag);
  }


  for (int j = 1; j < columns; j ++){
    for (int i = 0; i < rows; i++){
      int k = j + i;
      if ((i < rows) && (k < columns)){
        diag[p] = board[i][k];
        p++;
      }
    }
    p = 0;
    for (int q = 0; q < rows; q++){
      if (diag[q] == diag[q+1] && diag[q] != ' ' && diag[q] != 0)
        nir++;
      else
        nir = 1;
      if (nir == 4 && diag[q] == 'X')
        return 1000;
      if (nir == 4 && diag[q] == 'O')
        return -1000;
    }
    memset(diag, 0, sizeof diag);
  }


  return -1;
}

int isValidMove(char **board, int rows, int columns, int c){
  c = c - 1;
  for(int i = rows - 1; i >= 0 ; i--){
    if (board[0][c] != ' ' || c >= columns || c < 0){  //Checks to make sure number is a valid move
      return 0;
    }
    else if (board[i][c] == ' '){

      return 1;
    }
  }
  return -1;
}

int calcBestMove(char **board, int rows, int columns){
  int bestMove = 0;
  int bestVal = -1000;
  for (int i = 0; i < columns; i++){
    if (isValidMove(board, rows, columns, i) == 1){
      int mVal = minimax(rows*columns, board, true, rows, columns);
      if (mVal > bestVal){
        bestMove = i;
        bestVal = mVal;
      }
    }
  }

  return bestMove + 1;
}
// char ** boardCopy(char **old, int c, char p, int rows){
//   char **new = old;
//   for(int i = rows-1; i >= 0 ; i--){
//     if (new[i][c] == ' ')
//       new[i][c] = p;
//   }
//     return new;
//
//
// }
