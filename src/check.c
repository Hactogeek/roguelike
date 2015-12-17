#include "../inc/general.h"

void CheckAmorcer(){
    
}

void CheckTester(){
    
}

//Retourne 1 si le nombre donné en troisième paramètre est compris entre les deux autres nombres (inclus)
int EstContenuDans(int nb1, int nb2, int nb_a_chercher) {
	if(nb1 >= nb2)
		return nb_a_chercher <= nb1 && nb_a_chercher >= nb2;
	else
		return nb_a_chercher >= nb1 && nb_a_chercher <= nb2;
}

//Retourne 1 si la vie du personnage est a 0 ou moins cela retourne 1
int CheckTestPersonnage(t_personnage perso){
    return (perso.stats.vie<=0);
}

//Retourne 1 si le joueur est sur une case de changement d'etage
int CheckTestEtage(t_carte carte){
    return (carte.grille[carte.cord.x][carte.cord.y]==4);
}


//Retourne 1 si il y a un monstre aux coordonnées indiqué
int CheckMonstre(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) { 
		int i;
		for(i=0;i<carte.nbMonstreCarte;i++){
			if((carte.monstre[i].monstrePos.x==x) && (carte.monstre[i].monstrePos.y==y))
			{
				return 1;
			}
		}
		return 0;
	} else {
		return 0;
	}
}

//Retourne 1 s'il y a un mostre en vie aux coordonénes indiquées
int CheckMonstreEnVieIci(int x,int y, t_carte carte) {
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) { 
		int i;
		for(i=0;i<carte.nbMonstreCarte;i++){
			if((carte.monstre[i].monstrePos.x == x) && (carte.monstre[i].monstrePos.y == y) && CheckMonstreVie(i, carte)) {
				return 1;
			}
		}
		return 0;
	} else {
		return 0;
	}
}

//Retourne 1 si il y a un mur au coordonné saisie
int CheckMur(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) { 
		return (carte.grille[x][y]==1);
	} else {
		return 0;
	}
}

//Retourne 1 si le monstre est en vie
int CheckMonstreVie(int idMob,t_carte carte){
	return (carte.monstre[idMob].monstreVie>0);
}

//Retourne 1 si il y a un chemin au coordonné saisie
int CheckChemin(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
		return (carte.grille[x][y]==3);
	} else {
		return 0;
	}
}

//retourne 1 si le joueur merite d'up
int CheckUpNiveau(t_personnage player){
	return (player.experience.xpRequis<= player.experience.xp);
}

//Retourne 1 si il y a une salle au coordonné saisie
int CheckSalle(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) { 
		return (carte.grille[x][y]==2);
	} else {
		return 0;
	}
}

//Retourne 1 si le joueur est sur un escalier
int CheckEscalier(int x, int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) { 
    	return (carte.grille[x][y]==4);
    } else {
    	return 0;
    }
}

//Retourne 1 si la salle est vide (uniquement composée de vide, sans mur ni rien)
int CheckSalleVide(int salleX, int salleY, t_carte carte) {
	if(EstContenuDans(0, TAILLE_SALLE_X-1, salleX) && EstContenuDans(0, TAILLE_SALLE_Y, salleY)) { 
		int i,j;
	
		for(i = salleX * TAILLE_SALLE_X; i < (salleX+1) * TAILLE_SALLE_X; i++) {
			for(j = salleY * TAILLE_SALLE_Y; j < (salleY+1) * TAILLE_SALLE_Y; j++) {
				if(carte.grille[i][j] != 0) {
					return 0;
				}
			}
		}
		
		return 1;
	} else {
		return 0;
	}
}

//Retourne 1 si la case envoyée en paramètre est vide
int CheckVide(int x, int y, t_carte carte) {
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
		return (carte.grille[x][y]==0);
	} else {
		return 0;
	}
}

//
int CheckSalleJoueur(int x, int y, t_carte carte) {
    if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
        int xJoueur = carte.cord.x;
        int yJoueur = carte.cord.y;
        if(x/TAILLE_SALLE_X == xJoueur/TAILLE_SALLE_X && y/TAILLE_SALLE_Y == yJoueur/TAILLE_SALLE_Y) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}