CC = gcc
SRC = src/
INC = inc/
HEADER = $(INC)%.h
OBJ = $(SRC)couleur.o $(SRC)carte.o $(SRC)personnage.o $(SRC)Outil.o $(SRC)monstre.o $(SRC)jeu.o $(SRC)deplacement.o $(SRC)combat.o $(SRC)check.o $(SRC)main.o
FLAGS = -g -Wall
EXEC = roguelike

$(EXEC): $(OBJ)
	$(CC) -o bin/$(EXEC) $(OBJ) $(FLAGS)

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -i $(SRC)*.o
