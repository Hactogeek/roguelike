#include "../inc/general.h"

void CombatRemporter(t_personnage * player,t_carte * carte,int idMob){
	player->experience.xp +=carte->monstre[idMob].puissance;
	if(CheckUpNiveau(*player)){
		PersonnageLevelUp(player);
	}
}

void CombatTaper(t_personnage * player,t_carte * carte,int idMob){

	carte->monstre[idMob].monstreVie = carte->monstre[idMob].monstreVie-2;
	
	if(CheckUpNiveau(*player)){
		CombatRemporter(player,carte,idMob);
	
	}
	printf("Le joueur a infligé %i dégats au monstre, il lui en reste %i.\n",/*player->caract.force*/2,(carte->monstre[idMob].monstreVie));
}
