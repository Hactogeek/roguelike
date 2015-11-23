CC = gcc
SRC = src/
INC = inc/
HEADER = $(INC)%.h
OBJ = $(SRC)carte.o $(SRC)main.o $(SRC)deplacement.o
FLAGS = -g -Wall
EXEC = roguelike

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -i *.o
