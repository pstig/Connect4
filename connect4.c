/*****************
**Peter Stiglitz**
******CS201*******
****Connect 4*****
*****************/

#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/***Notes to Self***
 p1 is 0, p2 is 1
p_win->starty = (LINES - (p_win->height * rows)+1)/2;
p_win->startx = (COLS - (p_win->width * columns) +1 )/2;
0,0 is top left corner of screen
all coords in curses are (y,x)
LINES, COLS is bottom right of screen
WINDOW * win = newwin(height, width, starty, startx)
refresh() -- updates screen to whats in memory
wrefresh(win) -- only refreshes specific window
box(win, 0, 0) -- creates a box around WINDOW
wborder(win, ls, rs, ts, bs, tl, tr, bl br) -- creates border with specified chars for left side, right side etc
******************/



/*Temp Hardcoded Testing Values*/
#define w1 3
#define h1 2
#define rows 6      //actual number of rows
#define columns 7   //actual number of columns

/*Game Logic Function Definitions*/

void player_move(int *player, char c, int (*board)[columns]);
void refreshBoard(int board[rows][columns], int yMax, int xMax);
void drawGame(WINDOW * screen, WINDOW * inputbox, WINDOW * scorebox);
void drawMoveI(WINDOW * inputbox, int cnum, char input);
void drawBoard(WINDOW * gameboard);
void drawMove();

/*Main*/

int main(int argc, char *argv[]){

	char input;       //input character
	int activeGame = 1;


/*initialize curses and color*/
	initscr();
	start_color();
	cbreak();
	noecho();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

/*Get Max Window Values*/
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);


/*Create Game Windows*/
	WINDOW * screen = newwin(yMax, xMax, 0, 0);
	WINDOW * inputbox = newwin(3, xMax, yMax - 3, 0);
	WINDOW * scorebox = newwin(4, 13, 0, (xMax / 2) - 7);
	WINDOW * gameboard = newwin(2 * rows + 1, 3 * columns + 1, (yMax - (2 * rows)+1)/2, (xMax - (3 * columns) + 1)/2);
	refresh();
	drawGame(screen, inputbox, scorebox);
	drawBoard(gameboard);

	/* Initialize the game parameters and initial states */
	// int boardsx = (COLS - (w1 * columns) + 1 ) / 2;
	// int boardsy = (LINES - (h1 * rows) + 1) / 2;
  int playerCounter = 0;             //tracks which players move it is
	int boardArray[rows][columns] = {0};


//Main Game loop
  while(activeGame == 1) {
		input = getch();
		switch(playerCounter) {
	    case 0:
				drawMoveI(inputbox, 1, input);
				if (input == '.'){
					goto end;
				}
				if( (input > 96) && (input < columns + 123)){
					player_move(&playerCounter, input, &boardArray[columns]);
					// refreshBoard(boardArray, yMax, xMax);
				}
				break;

	    case 1:
				drawMoveI(inputbox, 2, input);
				if (input == '.'){
					goto end;
				}
				if( (input > 96) && (input < columns + 123)){
					player_move(&playerCounter, input, &boardArray[columns]);
					// refreshBoard(boardArray, yMax, xMax);
				}
				break;
			end:
				endwin();
				return 0;
		}
  }
}

void drawBoard(WINDOW * gameboard){

	for(int i = 0; i < 2 * rows; i = i + 2){
			mvwhline(gameboard, i, 0, 0, 3 * columns + 1);
	}
	mvwhline(gameboard, 2 * rows, 0, 0, 3 * columns +1);

	for(int i = 0; i < 3 * columns; i = i + 3){
		mvwvline(gameboard, 0, i, 0, 2 * rows + 1);
	}
	mvwvline(gameboard, 0, 3 * columns, 0, 2 * rows + 1);

	for(int i = 0; i < columns; i++){
		mvwprintw(gameboard, 2 * rows + 1, 3 * i + 1, "a");
	}

	box(gameboard, 0,0);
	wrefresh(gameboard);
}

void drawMove(){




}

void player_move(int *player, char ch, int (*board)[columns]){
	int j = (int)ch - '1';
	for(int i = rows-1; i >= 0 ; i--){
		if (board[i][j] == 0){
			board[i][j] = *player + 1;
			break;
		}
	}

  *player = !(*player);

}

void refreshBoard(int board[rows][columns], int yMax, int xMax){
	int ystart = ((yMax - (h1 * rows) + 1) / 2);
	int xstart = ((xMax - (w1 * columns) + 1 ) / 2);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(board[i][j] == 0){
				mvaddch(ystart + (i * 2) + 1, xstart + (j * 3) + 1, ' ');
			}
			if (board[i][j] == 1){
				init_pair(1, COLOR_YELLOW, COLOR_BLACK);
				attron(COLOR_PAIR(1));
				mvaddch(ystart + (i * 2) + 1, xstart + (j * 3) + 1, 'O');
				attroff(COLOR_PAIR(1));
			}

			if (board[i][j] == 2){
				init_pair(2, COLOR_RED, COLOR_BLACK);
				attron(COLOR_PAIR(2));
				mvaddch(ystart + (i * 2) + 1, xstart + (j * 3) + 1, 'O');
				attroff(COLOR_PAIR(2));
			}
		}
	}
}

void drawGame(WINDOW * screen, WINDOW * inputbox, WINDOW * scorebox){

	box(screen,0,0);
	box(inputbox, 0,0);
	box(scorebox, 0, 0);
	mvwprintw(scorebox, 1,4, "SCORE");
	wattron(scorebox, COLOR_PAIR(1));
	mvwprintw(scorebox, 2,1, "P1");
	wattroff(scorebox, COLOR_PAIR(1));
	mvwprintw(scorebox, 2, 6, "-");
	wattron(scorebox, COLOR_PAIR(2));
	mvwprintw(scorebox, 2, 10, "P2");
	wattroff(scorebox, COLOR_PAIR(2));


	wattron(inputbox, COLOR_PAIR(1));
	mvwprintw(inputbox, 1, 2 ,"Player 1 Move: ");
	wattroff(inputbox, COLOR_PAIR(1));

	wrefresh(screen);
	wrefresh(inputbox);
	wrefresh(scorebox);

}

void drawMoveI(WINDOW * inputbox, int cnum, char input){

	char * mesg;
	if (cnum == 1)
		mesg = "Player 1 Move: ";
	if (cnum == 2)
		mesg = "Player 2 Move: ";

	wattron(inputbox, COLOR_PAIR(cnum));
	mvwprintw(inputbox, 1, 2 ,"%s",mesg);
	mvwprintw(inputbox, 1, 17, "%c", input);
	wattroff(inputbox, COLOR_PAIR(cnum));
	wrefresh(inputbox);

}
