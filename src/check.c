#include "../inc/general.h"

void CheckAmorcer(){
    
}

void CheckTester(){
    
}

//Retourne 1 si la vie du personnage est a 0 ou moins cela retourne 1
int CheckTestPersonnage(t_personnage perso){
    return (perso.caract.vitalite<=0);
}

//Retourne 1 si le joueur est sur une case de changement d'etage
int CheckTestEtage(t_carte pos){
    return (pos.grille[pos.cord.x][pos.cord.y]==4);
}

//Retourne 1 si les coordonnés entré sont dans une salle
int CheckPositionSalle(int x,int y, t_carte carte){
	return (carte.grille[x][y]==2);
}

//Retourne 1 si il y a un monstre aux coordonnées indiqué
int CheckMonstre(int x,int y, t_carte carte){
	int i=0;
	for(i;i<NB_MAX_MONSTRE;i++){
		if(carte.monstre[i].monstrePos.x==x && carte.monstre[i].monstrePos.y==y)return 1;
	}
	return 0;
}

//Retourne 1 si il y a un mur au coordonné saisie
int CheckMur(int x,int y, t_carte carte){
	return (carte.grille[x][y]==1);
}

//Retourne 1 si le monstre est en vie
int CheckMonstreVie(int idMob,t_carte carte){
	return (carte.monstre[idMob].monstreVie>=0);
}

//Retourne 1 si il y a un chemin au coordonné saisie
int CheckChemin(int x,int y, t_carte carte){
	return (carte.grille[x][y]==3);
}

/*int CheckUpNiveau(t_personnage player){
	//return (player.xp
}*/

