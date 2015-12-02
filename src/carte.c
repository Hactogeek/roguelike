#include "../inc/general.h"

void CarteInitialiser(t_carte *carteGrille) {
	int i,j;
	
	for(i = 0; i < TAILLE_CARTE_X; i++) {
		for(j = 0; j < TAILLE_CARTE_Y; j++) {
			carteGrille->grille[i][j] = 0;
		}
	}
}

void MatriceAfficher(int matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y]) {
	int i,j;
	
	for(i = 0; i < TAILLE_CARTE_X; i++) {
		for(j = 0; j < TAILLE_CARTE_Y; j++) {
			printf("%i", matrice[i][j]);
		}
		printf("\n");
	}
}


void CarteAfficher(t_carte carte) {
	int i,j;
	
	for(i = 0; i < TAILLE_CARTE_X; i++) {
		for(j = 0; j < TAILLE_CARTE_Y; j++) {
		if(carte.cord.x==i && carte.cord.y==j){
			printf("@");
		}else{
			switch(carte.grille[i][j]) {
				case 0 : printf("~"); break;
				case 1 : printf("#"); break;
				case 2 : printf(" "); break;
				case 3 : printf("="); break;
				case 4 : printf(">"); break;
				
				default : printf(" "); break;
			}
		}
			/*if(carte.cord.x == i && carte.cord.y == j) {
				printf("@");
			}*/
		}
		printf("\n");
	}
}
	
t_carte CarteCharger() {
	FILE * carteFichier;
	t_carte carte;
	char carteCase;
	int salleDebutX;
	int salleDebutY;
	int tailleSalleX;
	int tailleSalleY;
	int i,j;
	int nb_salles_diff = 1;
	int nb_salles_x;
	int nb_salles_y;
	int nb_salles = 0;
	int salleId;
	int salleCompteur;
	
	carteFichier = fopen("./map/test_map.txt", "r");
	
	if(carteFichier != NULL) {
		CarteInitialiser(&carte);
		
		//Comptage du nombre de salles possibles
		do {
			fscanf(carteFichier, "%c", &carteCase);
			if(carteCase == '-') {
				nb_salles_diff++;
			}
		}while(!feof(carteFichier));
		
		while(nb_salles < SALLES_MAX) {
			//Séparation de la carte en plusieurs salles
			for(nb_salles_x = 0; nb_salles_x < SALLES_MAX_X; nb_salles_x++) {
				for(nb_salles_y = 0; nb_salles_y < SALLES_MAX_Y; nb_salles_y++) {
					//On se remet au début du fichier à chaque tour
					if(nb_salles_x < SALLES_MAX_X) {
						fseek(carteFichier, 0, SEEK_SET);
					}
					
					//Détermination de la salle qui sera mise
					salleId = (nHasard(nb_salles_diff)*nHasard(nb_salles_diff))%nb_salles_diff;
					
					//Récupération de la salle au bon id
					salleCompteur = 0;
					while(salleCompteur != salleId) {
						fscanf(carteFichier, "%c", &carteCase);
						if(carteCase == '-') {
							salleCompteur++;
						}
					}
					
					//Récupération de la taille de la salle
					fscanf(carteFichier, "%i %i", &tailleSalleX, &tailleSalleY);
					
					//Choix aléatoire des coordonnées de début de la salle
					salleDebutX = nHasard(TAILLE_SALLE_X - tailleSalleX);
					salleDebutY = nHasard(TAILLE_SALLE_Y - tailleSalleY);
							
					//Placement de la salle et remplissage
					for(i = salleDebutX + nb_salles_x * TAILLE_SALLE_X; i < salleDebutX + tailleSalleX + nb_salles_x * TAILLE_SALLE_X; i++) {
						for(j = salleDebutY + nb_salles_y * TAILLE_SALLE_Y-1; j <= salleDebutY + tailleSalleY + nb_salles_y * TAILLE_SALLE_Y-1; j++) {
							//Récupération du contenu de la case
							fscanf(carteFichier, "%c", &carteCase);
							if(carteCase != 0) {
								switch(carteCase) {
									case '1' : carte.grille[i][j] = 1; break;
									case '2' : carte.grille[i][j] = 2; break;
									case '3' : carte.grille[i][j] = 3; break;
									case '4' : carte.grille[i][j] = 4; break;

									default : carte.grille[i][j] = 0; break;
								}
							}
						}
					}
					
					nb_salles++;
				}
			}
		}

		printf("Carte :\n");
		carte.cord.x = 5;
        carte.cord.y = 5;
		CarteAfficher(carte);
		fclose(carteFichier);
        
	} else {
		printf("Erreur lors du chargement de la carte");
	}
    return carte;
}


void CarteTester(int test) {
	switch(test) {
		case 1 : CarteCharger(); break;
	}
}
