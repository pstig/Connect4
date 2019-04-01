#builds connect4.out from connect4.c
all: C4.c
	gcc -o connect4 C4.c
clean:
	$(RM) connect4
