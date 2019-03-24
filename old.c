//move loop
while(loop == 1){
  //player 1
  printf("\n Player 1's turn. Pick a row\n");
  scanf("%d", &playerMove);
  j = playerMove-1;
  int move = 0;
  while(move == 0){
  if(board[0][j] == 'X' || board[0][j] == 'O' || j < 0 || j > rows){
    //reprint
    printBoard(board, rows, columns);
    printf("\n Cannot Choose This Row, Pick another\n");
    scanf("%d", &playerMove);
    j = playerMove-1;
  }
  else{
    move = 1;
  }
}
move = 0;
  for(i=0;i<rows;i++) {
     if(board[i][j] != ' '){
       board[i-1][j] = 'X';
       lastj = j;
       lasti = i-1;
       i = rows + 1;
    }
    else if(i == rows){
       board[i][j] = 'X';
       lastj = j;
       lasti = i;
       i = rows + 1;
    }
  }
  //reprint
  for(i=0; i<rows; i++) {
     for(j=0;j<columns;j++) {
       if (i == 0){
         printf("|%d", j + 1);
       }
       else {
        printf("|%c", board[i][j]);
      }
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
        if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
        if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
        if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
        if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
  if(board[0][j] == 'X' || board[0][j] == 'O' || j < 0 || j > rows){
    //reprint
    for(i=0; i<rows; i++) {
       for(j=0;j<columns;j++) {
         if (i == 0){
           printf("|%d", j + 1);
         }
         else {
          printf("|%c", board[i][j]);
        }
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
  for(i=0;i<rows;i++) {
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
  for(i=0; i<rows; i++) {
     for(j=0;j<columns;j++) {
       if (i == 0){
         printf("|%d", j + 1);
       }
       else {
        printf("|%c", board[i][j]);
      }
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
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
         if(icheck < 0 || icheck > rows || jcheck < 0 || jcheck > columns){
            break;
         }
      }
      if(wincount == 4){
        break;
      }
    }
