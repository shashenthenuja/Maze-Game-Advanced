CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o fileIO.o terminal.o world.o control.o snake.o linkedlist.o
EXEC = maze

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c main.h fileIO.h terminal.h world.h control.h snake.h linkedlist.h
	$(CC) $(CFLAGS) main.c -c

fileIO.c : fileIO.c fileIO.h
	$(CC) $(CFLAGS) fileIO.c -c

terminal.c : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

world.c : world.c world.h
	$(CC) $(CFLAGS) world.c -c

control.c : control.c control.h
	$(CC) $(CFLAGS) control.c -c

snake.c : snake.c snake.h
	$(CC) $(CFLAGS) snake.c -c

linkedlist.c : linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c -c

clean :
	rm -f $(EXEC) $(OBJ)