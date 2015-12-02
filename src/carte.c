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

void CarteAfficher(t_carte * carte) {
    int i,j;
    printf("\n");
    
    for(i = 0; i < TAILLE_CARTE_X; i++) {
        for(j = 0; j < TAILLE_CARTE_Y; j++) {
            if(carte->cord.x==i && carte->cord.y==j){
                printf("@");
            }else{
                switch(carte->grille[i][j]){
                    case 0 : printf("~");break;
                    case 1 : printf("#");break;
                    case 2 : printf(" ");break;
                    case 3 : printf("=");break;
                    case 4 : printf(">");break;
                    //default: printf("A");
                }
            }
            
        }
        printf("\n");
    }
}
	
t_carte CarteCharger() {
	FILE * carteFichier;
	t_carte carte;
	char carteCase;
	int salleDebutX = 1;
	int salleDebutY = 1;
	int tailleSalleX;
	int tailleSalleY;
	int i,j;
	int nb_salles_x;
	int nb_salles_y;
	int nb_salles = 0;
	int salleId;
	int salleCompteur;
	
	carteFichier = fopen("./map/test_map.txt", "r");
	
	if(carteFichier != NULL) {
		CarteInitialiser(&carte);
		salleId = 2;
		
		while(nb_salles < SALLES_MAX) {
			//Séparation de la carte en plusieurs salles
			for(nb_salles_x = 0; nb_salles_x < SALLES_MAX_X; nb_salles_x++) {
				//On se remet au début du fichier à chaque tour
				if(nb_salles_x < SALLES_MAX_X) {
					fseek(carteFichier, 0, SEEK_SET);
				}
				
				for(nb_salles_y = 0; nb_salles_y < SALLES_MAX_Y; nb_salles_y++) {
					if(nb_salles_x < SALLES_MAX_X) {
						fseek(carteFichier, 0, SEEK_SET);
					}
					salleCompteur = 0;
					//Récupération de la salle au bon id
					//printf("salleId : %i\n", salleId);
					//printf("salleCompteur : %i\n", salleCompteur);
					while(salleCompteur != salleId) {
						fscanf(carteFichier, "%c", &carteCase);
						if(carteCase == '-') {
							salleCompteur++;
							//printf("salleCompteur : %i\n", salleCompteur);
						}
					}
					
					//Récupération de la taille de la salle
					fscanf(carteFichier, "%i %i", &tailleSalleX, &tailleSalleY);
					//printf("Taille de la salle : %i, %i\n\n", tailleSalleX, tailleSalleY);
					printf("ID de la salle : %i\nNombre de salles faites : %i", salleCompteur, nb_salles_y);
					
					//Placement de la salle et remplissage
					for(i = salleDebutX + nb_salles_x * TAILLE_SALLE_X; i < salleDebutX + tailleSalleX + nb_salles_x * TAILLE_SALLE_X; i++) {
						//e(salleDebutY + tailleSalleY + nb_salles_y * TAILLE_SALLE_Y-(salleDebutY + nb_salles_y * TAILLE_SALLE_Y));
						for(j = salleDebutY + nb_salles_y * TAILLE_SALLE_Y-1; j <= salleDebutY + tailleSalleY + nb_salles_y * TAILLE_SALLE_Y-1; j++) {
							//Récupération du contenu de la case
							fscanf(carteFichier, "%c", &carteCase);
							//printf("%c", carteCase);
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
					salleId = (salleId+1)%3;
				}
			}
		}

		printf("Matrice :\n");
		MatriceAfficher(carte.grille);
		printf("Carte :\n");
		CarteAfficher(&carte);
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
