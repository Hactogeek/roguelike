#include <stdio.h>
#include <stdlib.h>

typedef struct element{int valeur; struct element* suivant;} t_element;
t_element* pile;

void initpile(void);
int pilevide(void);
void empiler(int val);
void depiler(int* val);
char sommetpile(void);
