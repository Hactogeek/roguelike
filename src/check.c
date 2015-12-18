/**
 \file check.c
 \brief  Fichier avec fonctions de vérifications
 \author Tony Marteau, Dimitri Bernot, Marvin Jean
 \version 1.0.0
 \date 18 décembre 2015
 */

#include "../inc/general.h"

void CheckAmorcer(){

}

void CheckTester(){

}
/** \fn int EstContenuDans(int nb1, int nb2, int nb_a_chercher)
*   \brief Retourne 1 si le nombre donné en troisième paramètre est compris entre les deux autres nombres (inclus)
*   \param nb1 La premiere borne
*   \param nb2 La seconde borne
*   \param nb_a_chercher Le nombre à vérifié
*   \return Vrai ou faux
*/
int EstContenuDans(int nb1, int nb2, int nb_a_chercher) {
	if(nb1 >= nb2)
		return nb_a_chercher <= nb1 && nb_a_chercher >= nb2;
	else
		return nb_a_chercher >= nb1 && nb_a_chercher <= nb2;
}

/** \fn int CheckTestPersonnage(t_personnage perso)
*   \brief Retourne 1 si la vie du personnage est a 0 ou moins cela retourne 1
*   \param perso Le personnage joué
*   \return Vrai ou faux
*/
int CheckTestPersonnage(t_personnage perso){
    return (perso.stats.vie<=0);
}

/** \fn int CheckTestEtage(t_carte carte)
*   \brief Retourne 1 si le joueur est sur une case de changement d'etage
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckTestEtage(t_carte carte){
    return (carte.grille[carte.cord.x][carte.cord.y]==4);
}


/** \fn int CheckMonstre(int x,int y, t_carte carte)
*   \brief Retourne 1 si il y a un monstre aux coordonnées indiqué
*   \param x La cordonnée en x du monstre
*   \param y La cordonnée en y du monstre
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
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

/** \fn int CheckMonstreEnVieIci(int x,int y, t_carte carte)
*   \brief Retourne 1 s'il y a un mostre en vie aux coordonénes indiquées
*   \param x La cordonnée en x du monstre
*   \param y La cordonnée en y du monstre
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
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

/** \fn int CheckMur(int x,int y, t_carte carte)
*   \brief Retourne 1 si il y a un mur au coordonné saisie
*   \param x La cordonnée en x de la cellule
*   \param y La cordonnée en y de la cellule
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckMur(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
		return (carte.grille[x][y]==1);
	} else {
		return 0;
	}
}

/** \fn int CheckMonstreVie(int idMob,t_carte carte)
*   \brief Retourne 1 si le monstre est en vie par rapport a son ID
*   \param idMob L'ID du monstre
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckMonstreVie(int idMob,t_carte carte){
	return (carte.monstre[idMob].monstreVie>0);
}

/** \fn int CheckChemin(int x,int y, t_carte carte)
*   \brief Retourne 1 si il y a un chemin au coordonné saisie
*   \param x La cordonnée en x de la cellule
*   \param y La cordonnée en y de la cellule
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckChemin(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
		return (carte.grille[x][y]==3);
	} else {
		return 0;
	}
}

/** \fn int CheckUpNiveau(t_personnage player)
*   \brief retourne 1 si le joueur merite d'up
*   \param player Le joueur du jeu
*   \return Vrai ou faux
*/
int CheckUpNiveau(t_personnage player){
	return (player.experience.xpRequis<= player.experience.xp);
}


/** \fn int CheckSalle(int x,int y, t_carte carte
*   \brief Retourne 1 si il y a une salle au coordonné saisie
*   \param x La cordonnée en x de la cellule
*   \param y La cordonnée en y de la cellule
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckSalle(int x,int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
		return (carte.grille[x][y]==2);
	} else {
		return 0;
	}
}


/** \fn int CheckEscalier(int x, int y, t_carte carte)
*   \brief Retourne 1 si le joueur est sur un escalier
*   \param x La cordonnée en x de la cellule
*   \param y La cordonnée en y de la cellule
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckEscalier(int x, int y, t_carte carte){
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
    	return (carte.grille[x][y]==4);
    } else {
    	return 0;
    }
}

/** \fn int CheckSalleVide(int salleX, int salleY, t_carte carte)
*   \brief Retourne 1 si la salle est vide (uniquement composée de vide, sans mur ni rien)
*   \param salleX La cordonnée en x de la salle
*   \param salleY La cordonnée en y de la salle
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
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


/** \fn int CheckVide(int x, int y, t_carte carte)
*   \brief Retourne 1 si la case envoyée en paramètre est vide
*   \param x La cordonnée en x de la cellule
*   \param y La cordonnée en y de la cellule
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
int CheckVide(int x, int y, t_carte carte) {
	if(EstContenuDans(0, TAILLE_CARTE_X-1, x) && EstContenuDans(0, TAILLE_CARTE_Y, y)) {
		return (carte.grille[x][y]==0);
	} else {
		return 0;
	}
}

/** \fn int CheckSalleJoueur(int x, int y, t_carte carte)
*   \brief Retourne 1 si le joueur est dans une salle
*   \param x La cordonnée en x de la cellule
*   \param y La cordonnée en y de la cellule
*   \param carte La carte du jeu
*   \return Vrai ou faux
*/
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
