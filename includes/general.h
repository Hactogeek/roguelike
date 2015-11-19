#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 4

#include "rechercheDico.h"
#include "rechercheGrille.h"
#include "matrice.h"

typedef struct {char lettre; int point; char bonus[2];int visited;} t_donnee;

t_donnee grille[N][N];