CC=gcc
OBJ=pile_tab.o
CFLAGS= -Wall -g
EXEC=prog

calcul: $(OBJ)
	$(CC) -o $(EXEC) calcul.c $(OBJ) $(CFLAGS)
	
pile_tab.o: pile_tab.c pile_tab.h
	$(CC) -c pile_tab.c $(CFLAGS)
	
clean:
	rm -i *.o
