#include "../inc/general.h"

void CombatRemporter(t_personnage * player,t_carte * carte,int idMob){
	
	player->experience.xp +=carte->monstre[idMob].puissance;// Gain d'exp en fonction de la puissance du mob
	player->stats.score += 100;
	
	if(CheckUpNiveau(*player)){// Verifie que le personnage a assez d'exp pour passe de level
		PersonnageLevelUp(player);
	}
}

void CombatTaper(t_personnage * player,t_carte * carte,int idMob){
	int vita;
	carte->monstre[idMob].monstreVie = carte->monstre[idMob].monstreVie-player->caract.force;
	
	printf("Le joueur a infligé %i dégats au monstre, ",player->caract.force);
	
	vita=carte->monstre[idMob].monstreVie;
	if(vita > 0){
	printf("il lui en reste %i.\n",vita);
	}else{
	printf("il est mort.\n");
	}
	
	if(!CheckMonstreVie(idMob,*carte)){//Verifie que le monstre est mort
		CombatRemporter(player,carte,idMob);
	}
}
