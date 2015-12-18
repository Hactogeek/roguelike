/**
 \file monstre.c
 \brief  Roguelike
 \author Tony Marteau, Dimitri Bernot, Marvin Jean
 \version 1.0.0
 \date 18 décembre 2015
 */

#include "../inc/general.h"

void MonstreAmorcer(){

}

void MonstreInitialiser(){
    
}

/** \brief Attaque du joueur par le monstre
*   \param perso La structure personnage
*   \param carte La structure de la carte
*   \param i L'id du monstre qui inflige les dégats
*/
void MonstreAttaque(t_personnage * perso, t_carte * carte, int i)
// Attaque du joueur par le monstre
{    
	srand(time(NULL)+42);
	int esquive = 0;
	
	esquive = nHasard(101);//Pren un nombre entre 0 et 100
	if(esquive <= perso->caract.agilite){
		printf("Le joueur a reussi a esquivé l'attaque.\n");
	}else{
		perso->stats.vie -= carte->monstre[i].puissance;
    
    	printf("Le joueur a %i pdv.\n", perso->stats.vie);
	}
}


/** \brief Vérification de la vie de tout les monstres, si mort ils sont placés en (0,0)
*   \param carte La structure de la carte
*/
void MonstreMort(t_carte * carte)
{
	int i;
	
	for(i=0; i<carte->nbMonstreCarte; i++)
     {
     	if(carte->monstre[i].monstreVie<=0)
     	{
     		carte->monstre[i].monstrePos.x=0;
     		carte->monstre[i].monstrePos.y=0;
     	}
     }
}


/** \brief Déplacement des monstres
*   \param carte La structure de la carte
*   \param perso La structure personnage
*/
void MonstreDeplacement(t_carte * carte, t_personnage * perso)
// Déplacement monstre en fonction du joueur
{
    int i;
    

    for(i=0; i<carte->nbMonstreCarte; i++)
     {
        // Si le monstre et le joueur sont cote a cote, attaque!
        if(((carte->cord.x == carte->monstre[i].monstrePos.x-1) && (carte->cord.y == carte->monstre[i].monstrePos.y)) ||
           ((carte->cord.x == carte->monstre[i].monstrePos.x+1) && (carte->cord.y == carte->monstre[i].monstrePos.y)) ||
           ((carte->cord.y == carte->monstre[i].monstrePos.y-1) && (carte->cord.x == carte->monstre[i].monstrePos.x)) ||
           ((carte->cord.y == carte->monstre[i].monstrePos.y+1) && (carte->cord.x == carte->monstre[i].monstrePos.x)))
         {
            MonstreAttaque(perso, carte, i);
         }
        else
         {
            if((carte->cord.x/TAILLE_CARTE_X==carte->monstre[i].monstrePos.x/TAILLE_CARTE_X) &&
               (carte->cord.y/TAILLE_CARTE_Y==carte->monstre[i].monstrePos.y/TAILLE_CARTE_Y) &&
               (carte->grille[carte->cord.x][carte->cord.y]==2))
             {
             	// Verification si le joueur et le mob sont dans la même salle
                if(((carte->cord.x>carte->monstre[i].monstrePos.x) || (carte->cord.y>carte->monstre[i].monstrePos.y)))
                 {
                    // Si le monstre est en dessous ou a droite du joueur
                    if(carte->cord.x>carte->monstre[i].monstrePos.x)
                     {
                        // Si le monstre est a droite du joueur
                        if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y]==1)
                        {
                        	// Mur a droite
                        	if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y-1]==2)
                        	{
                        		// Deplacement vers la haut
                        		if(CheckMonstre(carte->monstre[i].monstrePos.x,carte->monstre[i].monstrePos.y-1,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.y--;
                                }
                        	}
                        	else if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y+1]==2)
                        	{
                        		// Deplacement vers la bas
                                if(CheckMonstre(carte->monstre[i].monstrePos.x,carte->monstre[i].monstrePos.y+1,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.y++;
                                }
                        	}
                        }
                        else if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y]==2)
                        {
                        	// Pas mur a droite, deplacement a droite
                            if(CheckMonstre(carte->monstre[i].monstrePos.x+1,carte->monstre[i].monstrePos.y,*carte)==0)
                            {
                                carte->monstre[i].monstrePos.x++;
                            }
                        }
                     }
                    else
                     {
                     	if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y+1]==1)
                     	{
                     		// Mur en dessous
                     		if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y+1]==2)
                     		{
                     			// Deplacement a droite
                                if(CheckMonstre(carte->monstre[i].monstrePos.x+1,carte->monstre[i].monstrePos.y,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.x++;
                                }
                     		}
                     		else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y+1]==2)
                     		{
                     			// Deplacement a gauche
                                if(CheckMonstre(carte->monstre[i].monstrePos.x-1,carte->monstre[i].monstrePos.y,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.x--;
                                }
                     		}
                     	}
                     	else if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y+1]==2)
                     	{
                        	// Pas mur en dessous, deplacement vers le bas
                            if(CheckMonstre(carte->monstre[i].monstrePos.x,carte->monstre[i].monstrePos.y+1,*carte)==0)
                            {
                                carte->monstre[i].monstrePos.y++;
                            }
                        }
                     }
                 }
                else
                 {
                    // Si le monstre est au dessus ou a gauche du joueur
                    if(carte->cord.x<carte->monstre[i].monstrePos.x)
                     {
                        if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y]==1)
                        {
                        	// Mur a gauche
                        	if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y-1]==2)
                        	{
                        		// Deplacement vers le haut
                                if(CheckMonstre(carte->monstre[i].monstrePos.x,carte->monstre[i].monstrePos.y-1,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.y--;
                                }
                        	}
                        	else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y+1]==2)
                        	{
                        		// Deplacement vers le bas
                                if(CheckMonstre(carte->monstre[i].monstrePos.x,carte->monstre[i].monstrePos.y+1,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.y++;
                                }
                        	}
                        }
                        else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y]==2)
                        {
                        	// Pas mur a gauche, deplacement a gauche
                            if(CheckMonstre(carte->monstre[i].monstrePos.x-1,carte->monstre[i].monstrePos.y,*carte)==0)
                            {
                                carte->monstre[i].monstrePos.x--;
                            }
                        }
                     }
                    else
                     {
                     	if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y-1]==1)
                     	{
                     		// Mur au dessus
                     		if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y-1]==2)
                     		{
                     			// Deplacement a droite
                                if(CheckMonstre(carte->monstre[i].monstrePos.x+1,carte->monstre[i].monstrePos.y,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.x++;
                                }
                     		}
                     		else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y-1]==2)
                     		{
                     			// Deplacement a gauche
                                if(CheckMonstre(carte->monstre[i].monstrePos.x-1,carte->monstre[i].monstrePos.y,*carte)==0)
                                {
                                    carte->monstre[i].monstrePos.x--;
                                }
                     		}
                     	}
                     	else if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y-1]==2)
                     	{
                         	// Pas mur au dessus, deplacement vers le haut
                            if(CheckMonstre(carte->monstre[i].monstrePos.x,carte->monstre[i].monstrePos.y-1,*carte)==0)
                            {
                                carte->monstre[i].monstrePos.y--;
                            }
                        }
                     }
                 }
             }
         }
     }
}


/** \brief Position du monstre par son id
*   \param carte La structure de la carte
*   \param i L'id du monstre
*   \param x Pointeur retour position x
*   \param y Pointeur retour position y
*/
void MonstrePositionParId(t_carte * carte, int i, int * x, int * y)
// Recupere l'adresse du monstre par ID
{
    *x=carte->monstre[i].monstrePos.x;
    *y=carte->monstre[i].monstrePos.y;
}


/** \brief Retourne l'id s'il y a un monstre en position (x,y)
*   \param carte La structure de la carte
*   \param x Pointeur retour position x
*   \param y Pointeur retour position y
*   \return -1 si pas de monstre, sinon retourne l'id du monstre
*/
int MonstreIdParPosition(t_carte * carte, int x, int y)
// Retourne l'ID du monstre s'il y en a un a la position
{
    int i;
    for(i=0; i<carte->nbMonstreCarte; i++)
    {
        if((carte->monstre[i].monstrePos.x==x) && (carte->monstre[i].monstrePos.y==y))
        {
            return i;
        }
    }
    return -1;
}

/** \brief Positionnement des monstres aléatoirement sur la carte
*   \param carte La structure de la carte
*   \param monstrePuissance Puissance des monstres placés
*/
void MonstrePositionner(t_carte * carte, int monstrePuissance)
// Positionnement du monstre dans les salles
{
    int i, hasardX, hasardY, hasardMonstre;
    
    srand(time(NULL)+10);
    
    hasardMonstre=uHasard(NB_MAX_MONSTRE);
    
    carte->nbMonstreCarte=hasardMonstre;
    
    
    for(i=0; i<carte->nbMonstreCarte; i++)
    {
        do{
            hasardX=uHasard(TAILLE_CARTE_X);
            hasardY=uHasard(TAILLE_CARTE_Y);
        }while((carte->grille[hasardX][hasardY]!=2) && (MonstreIdParPosition(carte, hasardX, hasardY)==-1));
        
        carte->monstre[i].monstrePos.x=hasardX;
        carte->monstre[i].monstrePos.y=hasardY;
        carte->monstre[i].monstreVie=carte->etage+3;
        
        carte->monstre[i].puissance=monstrePuissance;
        
    }
}


void MonstreTester()
// Fonction de test du monstre
{
    int test, monstrePuissance;
    
    Appel0("MonstreTester");
    
    t_personnage perso;
    t_carte carte;
    
    carte=CarteCharger();
    
    PersonnagePositionner(&carte);
    
    MonstrePositionner(&carte, monstrePuissance);
    
    printf("\n\n");
    CarteAfficher(&carte);
    
    perso.stats.vie=5;
    
    printf("MonstreTester : \n\n");
    
    do{
        printf("\nMenu :\n");
        printf(" 1 - Deplacement Monstre\n");
        printf(" 6 - Quitter\n\n");
        
        printf("Votre choix :");
        scanf("%i", &test);
        
        switch(test){
            case 1: MonstreDeplacement(&carte, &perso); CarteAfficher(&carte); break;
            case 2: CarteAfficher(&carte); break;
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
    
    Appel1("MonstreTester");
	
}
