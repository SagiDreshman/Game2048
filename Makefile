CC=gcc
OBJS=main.o board.o game.o Steps.o
EXEC=game
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


board.o: board.c board.h
game.o: game.c game.h board.h Steps.h
main.o: main.c game.h
Steps.o: Steps.c Steps.h board.h



clean: 
	rm -f $(EXEC) $(OBJS)
	
