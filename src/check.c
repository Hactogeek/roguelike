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

