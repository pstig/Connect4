#builds connect4.out from connect4.c
all: connect4.c
	gcc -g -Wall -o connect4 connect4.c -lmenu -lcurses
clean:
	$(RM) connect4
