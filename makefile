SRC=./src/
INCLUDE=./includes/

prog : $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheDico.o $(SRC)rechercheGrille.o $(INCLUDE)general.h -stdc99
	gcc -Wall $(SRC)main.c $(SRC)matrice.o $(SRC)rechercheDico.o $(SRC)rechercheGrille.o -o prog

matrice : $(SRC)matrice.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)matrice.c

rechercheDico : $(SRC)rechercheDico.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)rechercheDico.c

rechercheGrille : $(SRC)rechercheGrille.c $(INCLUDE)general.h
	gcc -g -Wall $(SRC)rechercheGrille.c
