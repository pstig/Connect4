/*****************
**Peter Stiglitz**
******CS201*******
****Connect 4*****
*****************/

#include <curses.h>
#include <stdio.h>
#include <string.h>
//NTS yellow is p1, red is p2
// p1 is 0, p2 is 1

//p_win->starty = (LINES - (p_win->height * rows)+1)/2;
//p_win->startx = (COLS - (p_win->width * columns) +1 )/2;

/*Struct for creating borders around windows*/
typedef struct _win_border_struct {
	chtype 	ls, rs, ts, bs,           //ts = top side, rs = right side...etc
	 	tl, tr, bl, br;                 //tl = top left, tr = top right...etc
}WIN_BORDER;

/*Struct for creating windows*/
typedef struct _WIN_struct {

  int initialx, initialy;      //coords for initial x and y, does not change
	int startx, starty;         //coords for start of window, top left corner, this value changes
  int height, width;          //dimensions of window
	WIN_BORDER border;          //border struct with info on border of window (above struct)
}WIN;

/*Function definitions for window and border creation*/
void init_win_params(WIN *p_win, int height, int width, int sx, int sy);
void create_box(WIN *win, bool flag);
void default_win(WIN *p_win);


/*Temp Hardcoded Testing Values*/
#define w1 3
#define h1 2
#define rows 6      //actual number of rows
#define columns 7   //actual number of columns

/*Game Logic Function Definitions*/
void create_game_board(WIN win);
void player_move(int *player, char c);

int main(int argc, char *argv[]){
  WIN screen;       //full window
  WIN board;        //game board window
	WIN nextmove;			//window for player input
	WIN score;				//window for scoreboard
	char input;       //input character


/*initialize curses stuff*/
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	/* Initialize the game parameters and initial states */
	int boardsx = (COLS - (w1 * columns) + 1 ) / 2;
	int boardsy = (LINES - (h1 * rows) + 1) / 2;
	init_win_params(&board, h1, w1, boardsx, boardsy);
  default_win(&screen);
	create_box(&screen, TRUE);         //creates border around whole window
  create_game_board(board);            //creates game board in window
  int playerCounter = 0;             //tracks which players move it is
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  char mesg0[] = "Player 1 Move: ";
  char mesg1[] = "Player 2 Move: ";


  attron(COLOR_PAIR(1));
  mvprintw(LINES - 2, 2 ,"%s",mesg0);
  attroff(COLOR_PAIR(1));

  while((input = getch()) != KEY_F(1)) {
		switch(playerCounter) {
	    case 0:
	      attron(COLOR_PAIR(1));
	      mvprintw(LINES - 2, 2 ,"%s",mesg0);
	      mvprintw(LINES - 2, 1 + 16, "%c", input);
	      attroff(COLOR_PAIR(1));
				player_move(&playerCounter, input);
				break;

	    case 1:
	      attron(COLOR_PAIR(2));
	      mvprintw(LINES - 2, 2 ,"%s",mesg1);
	      mvprintw(LINES - 2, 1 + 16, "%c", input);
	      attroff(COLOR_PAIR(2));
				player_move(&playerCounter, input);
				break;
		}


  }
  endwin();
  return 0;
}

void init_win_params(WIN *p_win, int height, int width, int sx, int sy) {
	p_win->height = height;
	p_win->width = width;
	p_win->starty = sy;
	p_win->startx = sx;
  p_win->initialy = p_win->starty;
  p_win->initialx = p_win->startx;

	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';

}

void default_win(WIN *p_win) {
  p_win->height = LINES-1;
	p_win->width = COLS -1;
	p_win->starty = 0;
	p_win->startx = 0;

	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';
}


void create_box(WIN *p_win, bool flag) {
  int i, j;
	int x, y, w, h;

	x = p_win->startx;
	y = p_win->starty;
	w = p_win->width;
	h = p_win->height;

	if(flag == TRUE)
	{	mvaddch(y, x, p_win->border.tl);
		mvaddch(y, x + w, p_win->border.tr);
		mvaddch(y + h, x, p_win->border.bl);
		mvaddch(y + h, x + w, p_win->border.br);
		mvhline(y, x + 1, p_win->border.ts, w - 1);
		mvhline(y + h, x + 1, p_win->border.bs, w - 1);
		mvvline(y + 1, x, p_win->border.ls, h - 1);
		mvvline(y + 1, x + w, p_win->border.rs, h - 1);

	}
	else
		for(j = y; j <= y + h; ++j)
			for(i = x; i <= x + w; ++i)
				mvaddch(j, i, ' ');

	refresh();

}

void create_game_board(WIN win){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns - 1; j ++){
      if ( i % 2 == 0){
        create_box(&win, TRUE);
				win.startx = win.startx + w1;
				create_box(&win, TRUE);
      }
      if ( i % 2 == 1){
        create_box(&win, TRUE);
			  win.startx = win.startx - w1;
				create_box(&win, TRUE);
      }
    }
    if (i != rows -1){
      create_box(&win, TRUE);
      win.starty = win.starty + h1;
      create_box(&win, TRUE);
    }

  }
}

void player_move(int *player, char c){
  if (*player == 0){
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(1));
		mvaddch(((LINES - (h1 * rows) + 1) / 2) + 11, ((COLS - (w1 * columns) + 1 ) / 2) + 1, c);
    attroff(COLOR_PAIR(1));
  }
  if (*player == 1){
    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(2));
		mvaddch(((LINES - (h1 * rows) + 1) / 2) + 11, ((COLS - (w1 * columns) + 1 ) / 2) + 4, c);
    attroff(COLOR_PAIR(2));
  }
  *player = !(*player);
}
