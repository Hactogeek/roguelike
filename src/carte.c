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
            } else if (CheckMonstre(i,j,carte)){
				printf("£");
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
								} else if((CheckMur(i,j-1,carte) || CheckChemin(i,j-1,carte) && (CheckMur(i,j+1,carte) || CheckChemin(i,j+1,carte)))) {
									printf("—");
								} else if((CheckMur(i-1,j,carte) || CheckChemin(i-1,j,carte) && (CheckMur(i+1,j,carte) || CheckChemin(i+1,j,carte)))) {
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
	int salleDebutX;
	int salleDebutY;
	int tailleSalleX;
	int tailleSalleY;
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
		
		//Comptage du nombre de salles possibles
		while(!feof(carteFichier)) {
			fscanf(carteFichier, "%c", &carteCase);
			if(carteCase == '-') {
				nb_salles_diff++;
			}
		}
		
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
							nb_portes = 0;
							//Récupération du contenu de la case
							fscanf(carteFichier, "%c", &carteCase);
							if(carteCase != 0) {
								switch(carteCase) {
									case '1' : carte.grille[i][j] = 1; break;
									case '2' : carte.grille[i][j] = 2; break;
									case '3' :
										if(nb_salles_y == 0 && carte.grille[i][j-1] == 0) { //Salle dans la rangée la plus à gauche
											carte.grille[i][j] = 1;
										} else if(nb_salles_x == 0 && carte.grille[i-1][j] == 0) { //Salle dans la rangée la plus haute
											carte.grille[i][j] = 1;
										} else if(nb_salles_y == SALLES_MAX_Y-1 && carte.grille[i][j-1] == 2) { //Salle dans la rangée la plus à droite
											carte.grille[i][j] = 1;
										} else if(nb_salles_x == SALLES_MAX_X-1 && carte.grille[i-1][j] == 2) { //Salle dans la rangée la plus basse
											carte.grille[i][j] = 1;
										} else { //Si une salle est éligible, on regarde maintenant si elle a déjà une porte - si oui, on peut éventuellement ne pas lui en mettre d'autre
											if(!nb_portes * uHasard(2)) {
												carte.grille[i][j] = 3;
												nb_portes++;
											} else {
												carte.grille[i][j] = 1;
											}
										}
										break;
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
				nb_portes = 0;
				for(i = nb_salles_x * TAILLE_SALLE_X; i < (nb_salles_x + 1) * TAILLE_SALLE_X; i++) {
					for(j = nb_salles_y * TAILLE_SALLE_Y; j < (nb_salles_y + 1) * TAILLE_SALLE_Y; j++) {
						if(carte.grille[i][j] == 3) {
							//Chemin à faire vers le haut
							if(carte.grille[i-1][j] == 0 && carte.grille[i][j-1] == 1 && nb_salles_x > 0) {
								printf("%i", nb_portes * nHasard(2));
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
					CarteAfficher(carte);
					break;
	}
}
