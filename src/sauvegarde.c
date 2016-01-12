/**
*	\file sauvegarde.c
*	\brief  Fichier gérant la sauvegarde et le chargement d'une partie
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/

#include "../inc/general.h"

void Sauvegarde(t_carte carte, t_personnage personnage) {
	FILE * sauvegarde;
	int i,j;
	
	sauvegarde = fopen("./save/save.txt", "w");
	
	if(sauvegarde != NULL) {
		//Sauvegarde de la carte
		for(i = 0; i < TAILLE_CARTE_X; i++) {
			for(j = 0; j < TAILLE_CARTE_Y; j++) {
				fprintf(sauvegarde, "%i", carte.grille[i][j]);
			}
			fprintf(sauvegarde, "\n");
		}

		fprintf(sauvegarde, "%i %i\n", carte.cord.x, carte.cord.y);
		fprintf(sauvegarde, "%i\n", carte.etage);
		fprintf(sauvegarde, "%i\n", carte.escalierVu);
		fprintf(sauvegarde, "%i\n", carte.monstrePuissance);
		fprintf(sauvegarde, "\n");
		
		//Sauvegarde des monstres
		fprintf(sauvegarde, "%i\n", carte.nbMonstreCarte);
		for(i = 0; i < carte.nbMonstreCarte; i++) {
			fprintf(sauvegarde, "%i %i\n", carte.monstre[i].monstrePos.x, carte.monstre[i].monstrePos.y);
			fprintf(sauvegarde, "%i\n", carte.monstre[i].monstreVie);
			fprintf(sauvegarde, "%i\n", carte.monstre[i].puissance);
			fprintf(sauvegarde, "\n");
		}

		//Sauvegarde du personnage
		fprintf(sauvegarde, "%s %i %i %i %i %i %i %i %i", personnage.nom, personnage.experience.niveau, personnage.experience.xpRequis, personnage.experience.xp, personnage.stats.vie, personnage.stats.score, personnage.caract.vitalite, personnage.caract.force, personnage.caract.agilite);
		//fprintf(sauvegarde
		
		fclose(sauvegarde);
	} else {
		printf("Erreur lors de la création de la sauvegarde");
	}
}

void Charger(t_carte * carte, t_personnage * personnage, FILE * sauvegarde) {
	if(sauvegarde != NULL) {
		int i,j;
		int nb;
		char carac;
		char nom[20];
		
		int carteChargee = 0;
		
		while(!carteChargee && !feof(sauvegarde)) {
			//Chargement de la carte
			if(!carteChargee) {
				for(i = 0; i < TAILLE_CARTE_X; i++) {
					for(j = 0; j < TAILLE_CARTE_Y; j++) {
						fscanf(sauvegarde, " %c", &carac);
						if(carac >= '0' && carac <= '9') {
							nb = carac - '0';
							carte->grille[i][j] = nb;
						}
					}
				}
				
				fscanf(sauvegarde, "%i", &nb);
				carte->cord.x = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->cord.y = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->etage = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->escalierVu = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->monstrePuissance = nb;
				
				strcpy(carte->dernierEvenement, "");
				
				carteChargee = 1;
			}
			
			//Chargement des monstres
			fscanf(sauvegarde, "%i", &carte->nbMonstreCarte);
			for(i = 0; i < carte->nbMonstreCarte; i++) {
				fscanf(sauvegarde, "%i", &nb);
				carte->monstre[i].monstrePos.x = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->monstre[i].monstrePos.y = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->monstre[i].monstreVie = nb;
				
				fscanf(sauvegarde, "%i", &nb);
				carte->monstre[i].puissance = nb;
			}
			
			//Chargement du personnage
			fscanf(sauvegarde, "%s", nom);
			strcpy(personnage->nom, nom);
			//personnage->nom = nom;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->experience.niveau = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->experience.xpRequis = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->experience.xp = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->stats.vie = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->stats.score = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->caract.vitalite = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->caract.force = nb;
			
			fscanf(sauvegarde, "%i", &nb);
			personnage->caract.agilite = nb;
			/*fscanf(sauvegarde, "%s %i %i %i %i %i %i %i %i", personnage->nom, personnage->experience.niveau, personnage->experience.xpRequis, personnage->experience.xp, personnage->stats.vie, personnage->stats.score, personnage->caract.vitalite, personnage->caract.force, personnage->caract.agilite);*/
		}
	} else {
		printf("Erreur lors du chargement de la sauvegarde");
	}
}
