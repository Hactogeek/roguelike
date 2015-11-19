#include "pile_tab.h"




void initpile(void){
	pile = NULL;
}

int pilevide(void){
	return(pile==NULL);
}


void empiler(int val){
	
	t_element* nouveau;
	int u = sizeof(t_element);
	nouveau =(t_element*) malloc(u);
	
	nouveau->valeur = val;
	nouveau->suivant = pile;
	pile=nouveau;
	
}

void depiler(int* val){
	t_element* sommet;
	
	if(!pilevide()){
		*val=pile->valeur;
		sommet = pile;
		pile = sommet ->suivant;
		free(sommet);
	}
	
}

char sommetpile(void){
	
	if(!pilevide()){
		return(pile->valeur);
	}
	
}
		
