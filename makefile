CC = gcc
SRC = src/
INC = inc/
HEADER = $(INC)%.h
OBJ = $(SRC)carte.o $(SRC)personnage.o $(SRC)Outil.o $(SRC)main.o 
FLAGS = -g -Wall
EXEC = roguelike

$(EXEC): $(OBJ)
	$(CC) -o bin/$(EXEC) $(OBJ) $(FLAGS)

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -i *.o
