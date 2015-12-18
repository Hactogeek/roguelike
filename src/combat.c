/**
*	\file combat.c
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/

#include "../inc/general.h"

/** 
*	\brief Distribue l'xp et augmente le score au joueur et test si il doit le faire passer de niveau
*   \param player le joueur
*   \param carte La carte du jeu
*   \param idMob L'id du monstre battu
*   \return Rien
*/
void CombatRemporter(t_personnage * player,t_carte * carte,int idMob){

	player->experience.xp +=carte->monstre[idMob].puissance;// Gain d'exp en fonction de la puissance du mob
	player->stats.score += 100;

	if(CheckUpNiveau(*player)){// Verifie que le personnage a assez d'exp pour passe de level
		PersonnageLevelUp(player);
	}
}

/** \brief Retire des pdv au monstre passer en id
*   \param player Le joueur
*   \param carte La carte du jeu
*   \param idMob L'id du monstre battu
*   \return Rien
*/
void CombatTaper(t_personnage * player,t_carte * carte,int idMob){
	int vita;
	char temp[5];
	carte->monstre[idMob].monstreVie = carte->monstre[idMob].monstreVie-player->caract.force;

	vita=carte->monstre[idMob].monstreVie;
	if(vita > 0) {
		//strcpy(carte->dernierEvenement, "Le joueur a inflige %i degats au monstre, il lui en reste %i", player->caract.force, vita);
		strcpy(carte->dernierEvenement, "Le joueur a inflige ");
		sprintf(temp, "%i", player->caract.force);
		strcat(carte->dernierEvenement, temp);
		strcat(carte->dernierEvenement, " degats au monstre, a qui il reste ");
		sprintf(temp, "%i", vita);
		strcat(carte->dernierEvenement, temp);
		strcat(carte->dernierEvenement, " points de vie.");
	} else {
		strcpy(carte->dernierEvenement, "Le joueur a acheve le monstre");
	}

	//printf("Le joueur a infligé %i dégats au monstre, ",player->caract.force);

	/*vita=carte->monstre[idMob].monstreVie;
	if(vita > 0){
	printf("il lui en reste %i.\n",vita);
	}else{
	printf("il est mort.\n");
	}*/

	if(!CheckMonstreVie(idMob,*carte)){//Verifie que le monstre est mort
		CombatRemporter(player,carte,idMob);
	}
}
