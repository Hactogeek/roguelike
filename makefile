CC=gcc
OBJ=Outil.o test.o
FLAGS=-g -Wall

prog: $(OBJ)
	$(CC) -o $@ $(OBJ) $(FLAGS)

test.o: test.c outil/Outil.h
	$(CC) -c test.c $(FLAGS)
	
Outil.o: outil/Outil.c outil/Outil.h
	$(CC) -c outil/Outil.c $(FLAGS)
	
clean:
	rm -i *.o
	
