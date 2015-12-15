#include "../inc/general.h"

void CarteInitialiser(t_carte *carteGrille) {
	int i,j;
	
	for(i = 0; i < TAILLE_CARTE_X; i++) {
		for(j = 0; j < TAILLE_CARTE_Y; j++) {
			carteGrille->grille[i][j] = 0;
		}
	}
}

int SallesPossiblesCompter(FILE *carteFichier) {
	int nb_salles = 0;
	char carteCase;
	
	while(!feof(carteFichier)) {
		fscanf(carteFichier, "%c", &carteCase);
		if(carteCase == '-') {
			nb_salles++;
		}
	}
	
	return nb_salles;
}

void PorteInitialiser(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]) {
	int x,y;
	
	for(x = 0; x < SALLES_MAX_X; x++) {
		for(y = 0; y < SALLES_MAX_Y; y++) {
			porte[x][y].droite = 0;
			porte[x][y].gauche = 0;
			porte[x][y].bas = 0;
			porte[x][y].haut = 0;
		}
	}
}

void PortePlacer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]) {
	int x,y;
	
	for(x = 0; x < SALLES_MAX_X; x++) {
		for(y = 0; y < SALLES_MAX_Y; y++) {
			if(y < SALLES_MAX_Y - 1) {
				porte[x][y].droite = 1;
				porte[x][y+1].gauche = 1;
			}
			if(y > 0) {
				porte[x][y].gauche = 1;
				porte[x][y-1].droite = 1;
			}
		
			if(x < SALLES_MAX_X - 1) {
				porte[x][y].bas = 1;
				porte[x+1][y].haut = 1;
			}
		
			if(x > 0) {
				porte[x][y].haut = 1;
				porte[x-1][y].bas = 1;
			}
		}
	}
}

void PorteRetirer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]) {
	int x,y;
	int cheminBas = SALLES_MAX_Y-1;
	
	for(x = 0; x < SALLES_MAX_X; x++) {
		for(y = 0; y < SALLES_MAX_Y; y++) {
			if(porte[x][y].haut && cheminBas > 0) {
				porte[x][y].haut -= nHasard(2);
				cheminBas--;
			}
			
			if(!porte[x][y].haut) {
				porte[x-1][y].bas = 0;
			}
			
			/*if(carte.porte[x][y].gauche) {
				carte.porte[x][y].gauche -= nHasard(2);
			}
			
			if(!carte.porte[x][y].gauche) {
				carte.porte[x][y-1].droite = 0;
			}*/
		}
	}
}

void EscalierChoix(t_carte * carte) {
	int caseX;
	int caseY;
	
	do {
		caseX = nHasard(TAILLE_CARTE_X);
		caseY = nHasard(TAILLE_CARTE_Y);
	} while(!CheckSalle(caseX, caseY, *carte)/* && !CheckChemin(caseX+1, caseY, *carte) && !CheckChemin(caseX-1, caseY, *carte) && !CheckChemin(caseX, caseY+1, *carte) && !CheckChemin(caseX, caseY-1, *carte)*/);
	carte->grille[caseX][caseY] = 4;
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
				color(6,"@");
            } else if (CheckMonstreEnVieIci(i,j,carte)){
				color(1,"£");
			} else {
				switch(carte.grille[i][j]) {
					case 0 : printf(" "); break;
					case 1 : 	if(CheckMur(i+1,j,carte) && CheckMur(i,j+1,carte)) {
									printf("┌");
								} else if(CheckMur(i-1,j,carte) == 1 && CheckMur(i,j+1,carte)) {
									printf("└");
								} else if(CheckMur(i+1,j,carte) == 1 && CheckMur(i,j-1,carte)) {
									printf("┐");
								} else if(CheckMur(i-1,j,carte) == 1 && CheckMur(i,j-1,carte)) {
									printf("┘");
								} else if((CheckMur(i,j-1,carte) || CheckChemin(i,j-1,carte)) && (CheckMur(i,j+1,carte) || CheckChemin(i,j+1,carte))) {
									printf("—");
								} else if((CheckMur(i-1,j,carte) || CheckChemin(i-1,j,carte)) && (CheckMur(i+1,j,carte) || CheckChemin(i+1,j,carte))) {
									printf("|");
								} else {
									printf("#");
								}
							break;
					case 2 : printf(" "); break;
					case 3 : printf("░"); break;
					case 4 : printf(">"); break;
				
					default : printf(" "); break;
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
	int salleX;
	int salleY;
	int salleDebutX;
	int salleDebutY;
	int tailleSalleX;
	int tailleSalleY;
	int caseX;
	int caseY;
	int i,j;
	int x,y;
	int salleId;
	int nb_salles_diff = 0;
	int nb_salles_x;
	int nb_salles_y;
	int nb_salles = 0;
	int salleCompteur;
	int nb_portes;
	
	carteFichier = fopen("./map/test_map.txt", "r");
	
	if(carteFichier != NULL) {
		srand(time(NULL));
		
		CarteInitialiser(&carte);
		
		nb_salles_diff = SallesPossiblesCompter(carteFichier);
		
		PorteInitialiser(carte.porte);
		
		PortePlacer(carte.porte);
		
		PorteRetirer(carte.porte);
		
		
		//Création des salles
		while(nb_salles < SALLES_MAX) {
			//Séparation de la carte en plusieurs salles
			for(nb_salles_x = 0; nb_salles_x < SALLES_MAX_X; nb_salles_x++) {
				for(nb_salles_y = 0; nb_salles_y < SALLES_MAX_Y; nb_salles_y++) {
					//On se remet au début du fichier à chaque tour
					if(nb_salles_x < SALLES_MAX_X) {
						fseek(carteFichier, 0, SEEK_SET);
					}
					
					//Détermination de la salle qui sera mise
					//salleId = rand()/RAND_MAX * nb_salles_diff;
					salleId = nHasard(nb_salles_diff);
					
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
					//Afin de garder un espacement suffisant entre les salles pour placer les chemins, on s'assure que les salles ne pourront pas être placées sur les bords de l'espace qui leur est réservé
					salleDebutX = nHasard(TAILLE_SALLE_X - tailleSalleX);
					salleDebutX += salleDebutX == 0;
					if(salleDebutX > tailleSalleX - 2) {
						salleDebutX = tailleSalleX-2;
					}
					salleDebutY = nHasard(TAILLE_SALLE_Y - tailleSalleY);
					salleDebutY += salleDebutY == 0;
					if(salleDebutY > tailleSalleY - 2) {
						salleDebutY = tailleSalleY-2;
					}
					
					//Placement de la salle et remplissage
					for(i = salleDebutX + nb_salles_x * TAILLE_SALLE_X; i < salleDebutX + tailleSalleX + nb_salles_x * TAILLE_SALLE_X; i++) {
						for(j = salleDebutY + nb_salles_y * TAILLE_SALLE_Y-1; j <= salleDebutY + tailleSalleY + nb_salles_y * TAILLE_SALLE_Y-1; j++) {
							//Récupération du contenu de la case
							fscanf(carteFichier, "%c", &carteCase);
							if(carteCase != 0) {
								switch(carteCase) {
									case '1' : carte.grille[i][j] = 1; break;
									case '2' : carte.grille[i][j] = 2; break;
									case '3' :
										if(carte.porte[nb_salles_x][nb_salles_y].haut && carte.grille[i-1][j] == 0) {
											carte.grille[i][j] = 3;
										} else if(carte.porte[nb_salles_x][nb_salles_y].bas && carte.grille[i-1][j] == 2) {
											carte.grille[i][j] = 3;
										} else if(carte.porte[nb_salles_x][nb_salles_y].gauche && carte.grille[i][j-1] == 0) {
											carte.grille[i][j] = 3;
										} else if(carte.porte[nb_salles_x][nb_salles_y].droite && carte.grille[i][j-1] == 2) {
											carte.grille[i][j] = 3;
										} else {
											carte.grille[i][j] = 1;
										}
										
										break;

									default : carte.grille[i][j] = 0; break;
								}
							}
						}
					}
					nb_salles++;
				}
			}
		}
		
		EscalierChoix(&carte);
		
		
		
		//Création des chemins
		/*
		 * Lors de la création de la carte, des portes ont été atribuées
		 * On repasse sur la carte en cherchant les portes
		 * Si on en trouve, on regarde autour (en haut et à gauche) pour voir dans quel sens est le chemin à créer
		 * Dans tous les cas, on créé un chemin jusqu'à l'extrémité de la salle
		 * Ensuite, les salles étendent leurs chemins vers les autres salles situées au dessus et à gauche, afin de combler le vide qu'il y a
		 */
		for(nb_salles_x = 0; nb_salles_x < SALLES_MAX_X; nb_salles_x++) {
			for(nb_salles_y = 0; nb_salles_y < SALLES_MAX_Y; nb_salles_y++) {
				for(i = nb_salles_x * TAILLE_SALLE_X; i < (nb_salles_x + 1) * TAILLE_SALLE_X; i++) {
					for(j = nb_salles_y * TAILLE_SALLE_Y; j < (nb_salles_y + 1) * TAILLE_SALLE_Y; j++) {
						if(carte.grille[i][j] == 3) {
							//Chemin à faire vers le haut
							if(carte.grille[i-1][j] == 0 && carte.grille[i][j-1] == 1 && nb_salles_x > 0) {
								for(x = i-1; x >= nb_salles_x * TAILLE_SALLE_X; x--) {
									carte.grille[x][j] = 3;
								}
							}
							
							//Chemin à faire vers le bas
							if(carte.grille[i-1][j] == 2 && carte.grille[i][j-1] == 1 && nb_salles_x < SALLES_MAX_X) {
								for(x = i+1; x <= (nb_salles_x + 1) * TAILLE_SALLE_X; x++) {
									carte.grille[x][j] = 3;
								}
							}
							
							//Chemin à faire vers la droite
							if(carte.grille[i-1][j] == 1 && carte.grille[i][j-1] == 0 && nb_salles_y > 0) {
								for(y = j-1; y >= nb_salles_y * TAILLE_SALLE_Y; y--) {
									carte.grille[i][y] = 3;
								}
							}
							
							//Chemin à faire vers la gauche
							if(carte.grille[i-1][j] == 1 && carte.grille[i][j+1] == 0 && nb_salles_y < SALLES_MAX_Y) {
								for(y = j+1; y <= (nb_salles_y + 1) * TAILLE_SALLE_Y; y++) {
									carte.grille[i][y] = 3;
								}
							}
						}
					}
				}
			}
		}
		
		for(nb_salles_x = 0; nb_salles_x < SALLES_MAX_X; nb_salles_x++) {
			for(nb_salles_y = 0; nb_salles_y < SALLES_MAX_Y; nb_salles_y++) {
				for(i = nb_salles_x * TAILLE_SALLE_X; i < (nb_salles_x + 1) * TAILLE_SALLE_X; i++) {
					for(j = nb_salles_y * TAILLE_SALLE_Y; j < (nb_salles_y + 1) * TAILLE_SALLE_Y; j++) {
						if(carte.grille[i][j] == 3) {
							if(carte.grille[i-1][j] == 0 && carte.grille[i+1][j] == 0) {
								//Chemin à compléter vers la droite
								if((carte.grille[i][j-1] == 3 || carte.grille[i][j+1] == 3) && !(carte.grille[i][j-1] == 3 && carte.grille[i][j+1] == 3)) { 
									while(carte.grille[i+1][j] != 3 && (carte.grille[i][j-1] != 3 || carte.grille[i][j+1] != 3)) {
										carte.grille[i+1][j] = 3;
										i++;
									}
								}
							}
							
							if(carte.grille[i][j-1] == 0 && carte.grille[i][j+1] == 0) {
								//Chemin à compléter vers le bas
								if((carte.grille[i-1][j] == 3 || carte.grille[i+1][j] == 3) && !(carte.grille[i-1][j] == 3 && carte.grille[i+1][j] == 3)) { 
									while(carte.grille[i][j+1] != 3 && (carte.grille[i-1][j] != 3 || carte.grille[i+1][j] != 3)) {
										carte.grille[i][j+1] = 3;
										j++;
									}
								}
							}
						}
					}
				}
			}
		}
		fclose(carteFichier);
		
	} else {
		printf("Erreur lors du chargement de la carte");
	}
	return carte;
}


void CarteTester(int test) {
	t_carte carte;
	switch(test) {
		case 1 : 	carte = CarteCharger();
					//MatriceAfficher(carte.grille);
					CarteAfficher(carte);
					break;
	}
}

