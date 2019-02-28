//old window stuff

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

void create_game_board(WIN win);




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
