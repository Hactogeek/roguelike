CC = gcc
OBJ = src/carte.o
FLAGS = -g -Wall
EXEC = carte

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(FLAGS)

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	rm -i *.o
