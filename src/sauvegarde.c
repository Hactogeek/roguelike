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
		fprintf(sauvegarde, "Carte :\n");
	
		for(i = 0; i < TAILLE_CARTE_X; i++) {
			for(j = 0; j < TAILLE_CARTE_Y; j++) {
				fprintf(sauvegarde, "%i", carte.grille[i][j]);
			}
			fprintf(sauvegarde, "\n");
		}

		fprintf(sauvegarde, "%i, %i\n", carte.cord.x, carte.cord.y);
		fprintf(sauvegarde, "%i\n", carte.etage);
		fprintf(sauvegarde, "%i\n", carte.escalierVu);
		
		//Sauvegarde des monstres
		fprintf(sauvegarde, "Monstres :\n");
		for(i = 0; i < carte.nbMonstreCarte; i++) {
			fprintf(sauvegarde, "%i %i\n", carte.monstre[i].monstrePos.x, carte.monstre[i].monstrePos.y);
			fprintf(sauvegarde, "%i\n", carte.monstre[i].monstreVie);
			//fprintf(sauvegarde, "%i\n", carte.monstre[i].puissance);
			fprintf(sauvegarde, "\n");
		}

		//Sauvegarde du personnage
		fprintf(sauvegarde, "Personnage :\n");
		fprintf(sauvegarde, "%s, %i, %i, %i, %i, %i, %i, %i, %i", personnage.nom, personnage.experience.niveau, personnage.experience.xpRequis, personnage.experience.xp, personnage.stats.vie, personnage.stats.score, personnage.caract.vitalite, personnage.caract.force, personnage.caract.agilite);
		//fprintf(sauvegarde
		
		fclose(sauvegarde);
	} else {
		printf("Erreur lors de la sauvegarde");
	}
}
