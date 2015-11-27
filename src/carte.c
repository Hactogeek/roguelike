#define TAILLE_SALLE 10

#include "../inc/general.h"

void CarteCharger() {
	FILE * carteFichier;
	char carte[TAILLE_SALLE][TAILLE_SALLE];
	char carteCase = ' ';
	
	char salleDebutX;
	char salleDebutY;
	
	carteFichier = fopen("./map/test_map.txt", "r");
	
	if(carte != NULL) {
		while(!feof(carteFichier)) {
			fscanf(carteFichier, "%c %c", &salleDebutX, &salleDebutY);
			while(carteCase != '-') {
				fscanf(carteFichier, "%c", &carteCase);
				switch(carteCase) {
					case '1' : printf("#"); break;
					case '2' : printf(" "); break;
					case '3' : printf("="); break;
					case '4' : printf("@"); break;
					
					case '\n' : printf("\n");
				}
			}
			printf("\n \n");
		}
		fclose(carteFichier);
	} else {
		printf("Erreur lors du chargement de la carte");
	}
}

void CarteTester(int test) {
	switch(test) {
		case 1 : CarteCharger(); break;
	}
}
