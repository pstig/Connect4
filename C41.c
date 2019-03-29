#include <stdio.h>
#include <math.h>
#include <string.h>


int main()
{
  char board[6][7];
  int i, j;
  int winner;
  int playerMove;
  int loop = 1;
  int lasti, lastj;
  char piece;
  for(i=0; i<6; i++) {
     for(j=0;j<7;j++) {
        board[i][j] = ' ';
     }
  }
   printf("Tristan's Super Epic Connect 4!\n \n");
   printf("|1|2|3|4|5|6|7|\n");
   for(i=0; i<6; i++) {
      for(j=0;j<7;j++) {
         piece = board[i][j];
         printf("|%c", piece);
      }
      printf("| \n");
   }


   //move loop
   while(loop == 1){
     //player 1
     printf("\n Player 1's turn. Pick a row\n");
     scanf("%d", &playerMove);
     j = playerMove-1;
     int move = 0;
     while(move == 0){
     if(board[0][j] == 'X' || board[0][j] == 'O' || j < 0 || j > 6){
       //reprint
       printf("|1|2|3|4|5|6|7|\n");
       for(i=0; i<6; i++) {
          for(j=0;j<7;j++) {
             piece = board[i][j];
             printf("|%c", piece);
          }
          printf("| \n");
       }
       printf("\n Cannot Choose This Row, Pick another\n");
       scanf("%d", &playerMove);
       j = playerMove-1;
     }else{
       move = 1;
     }
   }
   move = 0;
     for(i=0;i<6;i++) {
        if(board[i][j] != ' '){
          board[i-1][j] = 'X';
          lastj = j;
          lasti = i-1;
          i = 7;
       }else if(i == 5){
          board[i][j] = 'X';
          lastj = j;
          lasti = i;
          i = 7;
       }
     }
     //reprint
     printf("|1|2|3|4|5|6|7|\n");
     for(i=0; i<6; i++) {
        for(j=0;j<7;j++) {
           piece = board[i][j];
           printf("|%c", piece);
        }
        printf("| \n");
     }
     //win check
         int jcheck, icheck, wincount;
        //check left right
         wincount = 1;
         winner = 1;
         icheck = lasti;
         jcheck = lastj + 1;
         while (board[icheck][jcheck] == 'X'){
            wincount++;
            jcheck++;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         jcheck = lastj - 1;
         while (board[icheck][jcheck] == 'X'){
            wincount++;
            jcheck--;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         //check updown
         wincount = 1;
         jcheck = lastj;
         icheck = lasti + 1;
         while (board[icheck][jcheck] == 'X'){
            wincount++;
            icheck++;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         icheck = lasti - 1;
         while (board[icheck][jcheck] == 'X'){
            wincount++;
            icheck--;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
        //check /
        wincount = 1;
        jcheck = lastj + 1;
        icheck = lasti + 1;
        while (board[icheck][jcheck] == 'X'){
           wincount++;
           icheck++;
           jcheck++;
           if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
              break;
           }
        }
        if(wincount == 4){
          break;
        }
        jcheck = lastj - 1;
        icheck = lasti - 1;
        while (board[icheck][jcheck] == 'X'){
           wincount++;
           icheck--;
           jcheck--;
           if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
              break;
           }
        }
        if(wincount == 4){
          break;
        }
        //check \
        wincount = 1;
        jcheck = lastj + 1;
        icheck = lasti - 1;
        while (board[icheck][jcheck] == 'X'){
           wincount++;
           icheck--;
           jcheck++;
           if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
              break;
           }
        }
        if(wincount == 4){
          break;
        }
        jcheck = lastj - 1;
        icheck = lasti + 1;
        while (board[icheck][jcheck] == 'X'){
           wincount++;
           icheck++;
           jcheck--;
           if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
              break;
           }
        }
        if(wincount == 4){
          break;
        }



     //player 2
     printf("\n Player 2's turn. Pick a row\n");
     scanf("%d", &playerMove);
     j = playerMove-1;
     while(move == 0){
     if(board[0][j] == 'X' || board[0][j] == 'O' || j < 0 || j > 6){
       //reprint
       printf("|1|2|3|4|5|6|7|\n");
       for(i=0; i<6; i++) {
          for(j=0;j<7;j++) {
             piece = board[i][j];
             printf("|%c", piece);
          }
          printf("| \n");
       }
       printf("\n Cannot Choose This Row, Pick another\n");
       scanf("%d", &playerMove);
       j = playerMove-1;
     }else{
       move = 1;
     }
   }
   move = 0;
     for(i=0;i<6;i++) {
        if(board[i][j] != ' '){
          board[i-1][j] = 'O';
          lasti = i-1;
          lastj = j;
          i = 7;
       }else if(i == 5){
          board[i][j] = 'O';
          lasti = i;
          lastj = j;
          i = 7;
       }
     }
     //reprint
     printf("|1|2|3|4|5|6|7|\n");
     for(i=0; i<6; i++) {
        for(j=0;j<7;j++) {
           piece = board[i][j];
           printf("|%c", piece);
        }
        printf("| \n");
     }
     //win check
        //check left right
         wincount = 1;
         winner = 2;
         icheck = lasti;
         jcheck = lastj + 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            jcheck++;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         jcheck = lastj - 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            jcheck--;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         //check updown
         wincount = 1;
         jcheck = lastj;
         icheck = lasti + 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            icheck++;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         icheck = lasti - 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            icheck--;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         //check /
         wincount = 1;
         jcheck = lastj + 1;
         icheck = lasti + 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            icheck++;
            jcheck++;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         jcheck = lastj - 1;
         icheck = lasti - 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            icheck--;
            jcheck--;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         //check \
         wincount = 1;
         jcheck = lastj + 1;
         icheck = lasti - 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            icheck--;
            jcheck++;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
         jcheck = lastj - 1;
         icheck = lasti + 1;
         while (board[icheck][jcheck] == 'O'){
            wincount++;
            icheck++;
            jcheck--;
            if(icheck < 0 || icheck > 6 || jcheck < 0 || jcheck > 7){
               break;
            }
         }
         if(wincount == 4){
           break;
         }
       }

   printf("Player %d is the winner!!!!", winner);



   return 0;
}
