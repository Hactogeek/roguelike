#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 20

/** \fn tri
* \brief place l'entier x dans le bonne ordre du tableau tab
*/
void tri(int *tab,int x, int taille){
	
	int i;
	
	for(i = taille -1;i>=0;i--){
		if(tab[i] > x ){
			tab[i+1]=tab[i];
			tab[i]=x;
		}
	}
	
}

/** \fn affichage
* \brief Affiche une tableau
*/
void affiche(int *tab, int taille){
	int i;
	
	for(i=0;i<taille;i++){
		
		printf("%i ",tab[i]);
		
	}
	printf("\n");
}

int main(void){
	int tab[N],saisie=0,i=0;
	
	do{
		printf("Saisir un entier : ");
		scanf("%i",&saisie);
		if(saisie != -1){
			tab[i]=saisie;
			i++;
			tri(tab,saisie,i);
			affiche(tab,i);
		}
	}while(saisie != -1);
	
	return 0;
}
