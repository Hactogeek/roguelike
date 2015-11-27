#define TAILLE_SALLE 10

#include "../inc/general.h"

void CarteInitialiser(t_carte *carteGrille) {
    int i,j;
    
    for(i = 0; i < TAILLE_SALLE; i++) {
        for(j = 0; j < TAILLE_SALLE; j++) {
            carteGrille->grille[i][j] = 0;
        }
    }
}

void CarteAfficher(t_carte carte) {
    int i,j;
    
    for(i = 0; i < TAILLE_SALLE; i++) {
        for(j = 0; j < TAILLE_SALLE; j++) {
            printf("%i", carte.grille[i][j]);
        }
        printf("\n");
    }
}
    
void CarteCharger() {
	FILE * carteFichier;
	t_carte carte;
    char carteCase;
	int salleDebutX = 3;
	int salleDebutY = 3;
    int tailleSalleX;
    int tailleSalleY;
    int i,j;
	
	carteFichier = fopen("./map/test_map.txt", "r");
    
	if(carteFichier != NULL) {
        CarteInitialiser(&carte);
		while(!feof(carteFichier)) {
			fscanf(carteFichier, "%i %i", &tailleSalleX, &tailleSalleY);
            for(i = salleDebutX; i <= salleDebutX + tailleSalleX; i++) {
                for(j = salleDebutY; j <= salleDebutY + tailleSalleY; j++) {
                    fscanf(carteFichier, "%c", &carteCase);
                    //printf("i : %i , j : %i\n", i,j);
                    switch(carteCase) {
                        case '1' : carte.grille[i][j] = 1; break;
                        case '2' : carte.grille[i][j] = 2; break;
                        case '3' : carte.grille[i][j] = 3; break;
                        case '4' : carte.grille[i][j] = 4; break;
                    }
                }
            }
		}
        CarteAfficher(carte);
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
