#include "../inc/general.h"

void MonstreAmorcer(){

}

void MonstreInitialiser(){
    
}

void MonstreAttaque(t_personnage * perso, t_carte * carte, int i)
// Attaque du joueur par le monstre
{
    Appel0("MonstreAttaque");
    
    perso->stats.vie--;
    
    printf("Joueur Vie : %i\n", perso->stats.vie);
    
    Appel1("MonstreAttaque");
}

void MonstreMort(t_carte * carte)
{
	int i;
	
	Appel0("MonstreMort");
	
	for(i=0; i<NB_MAX_MONSTRE; i++)
     {
     	if(carte->monstre[i].monstreVie<=0)
     	{
     		carte->monstre[i].monstrePos.x=0;
     		carte->monstre[i].monstrePos.y=0;
     	}
     }
	
	Appel1("MonstreMort");
}

void MonstreDeplacement(t_carte * carte, t_personnage * perso)
// Déplacement monstre en fonction du joueur
{
    int i;
    
    Appel0("MonstreDeplacement");
    
    for(i=0; i<NB_MAX_MONSTRE; i++)
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
               (carte->cord.y/TAILLE_CARTE_Y==carte->monstre[i].monstrePos.y/TAILLE_CARTE_Y))
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
                        		carte->monstre[i].monstrePos.y--;
                        		printf("HAUT");
                        	}
                        	else if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y+1]==2)
                        	{
                        		// Deplacement vers la bas
                        		carte->monstre[i].monstrePos.y++;
                        		printf("BAS");
                        	}
                        }
                        else if((carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y]==2))
                        {
                        	// Pas mur a droite, deplacement a droite
                        	carte->monstre[i].monstrePos.x++;
                        	printf("DROITE");
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
                     			carte->monstre[i].monstrePos.x++;
                     			printf("DROITE");
                     		}
                     		else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y+1]==2)
                     		{
                     			// Deplacement a gauche
                     			carte->monstre[i].monstrePos.x--;
                     			printf("GAUCHE");
                     		}
                     	}
                     	else if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y+1]==2)
                     	{
                        	// Pas mur en dessous, deplacement vers le bas
                        	carte->monstre[i].monstrePos.y++;
                        	printf("BAS");
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
                        		carte->monstre[i].monstrePos.y--;
                        		printf("HAUT");
                        	}
                        	else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y+1]==2)
                        	{
                        		// Deplacement vers le bas
                        		carte->monstre[i].monstrePos.y++;
                        		printf("BAS");
                        	}
                        }
                        else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y]==2)
                        {
                        	// Pas mur a gauche, deplacement a gauche
                        	carte->monstre[i].monstrePos.x--;
                        	printf("GAUCHE");
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
                     			carte->monstre[i].monstrePos.x++;
                     			printf("DROITE");
                     		}
                     		else if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y-1]==2)
                     		{
                     			// Deplacement a gauche
                     			carte->monstre[i].monstrePos.x--;
                     			printf("GAUCHE");
                     		}
                     	}
                     	else if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y-1]==2)
                     	{
                         	// Pas mur au dessus, deplacement vers le haut
                         	carte->monstre[i].monstrePos.y--;
                         	printf("HAUT");
                        }
                     }
                 }
             }
         }
     }
    
    Appel1("MonstreDeplacement");  
}

void MonstrePositionParId(t_carte * carte, int i, int * x, int * y)
// Recupere l'adresse du monstre par ID
{
    *x=carte->monstre[i].monstrePos.x;
    *y=carte->monstre[i].monstrePos.y;
}

int MonstreIdParPosition(t_carte * carte, int x, int y)
// Retourne l'ID du monstre s'il y en a un a la position
{
    int i;
    for(i=0; i<NB_MAX_MONSTRE; i++)
    {
        if((carte->monstre[i].monstrePos.x==x) && (carte->monstre[i].monstrePos.y==y))
        {
            return i;
        }
    }
    return -1;
}

void MonstrePositionner(t_carte * carte)
// Positionnement du monstre dans les salles
{
    int i, hasardX, hasardY, hasardMonstre;
    
    srand(time(NULL)+10);
    
    //hasardMonstre=uHasard(NB_MAX_MONSTRE);
    
    for(i=0; i<NB_MAX_MONSTRE; i++)
    {
        do{
            hasardX=uHasard(TAILLE_CARTE_X);
            hasardY=uHasard(TAILLE_CARTE_Y);
        }while((carte->grille[hasardX][hasardY]!=2) && (MonstreIdParPosition(carte, hasardX, hasardY)==-1));
        
        carte->monstre[i].monstrePos.x=hasardX;
        carte->monstre[i].monstrePos.y=hasardY;
        carte->monstre[i].monstreVie=5;
        
    }
}


void MonstreTester()
// Fonction de test du monstre
{
	int test;
    
    Appel0("MonstreTester");
    
    t_personnage perso;
    t_carte carte;
    
    carte=CarteCharger();
    
    PersonnagePositionner(&carte);
    
    MonstrePositionner(&carte);
    
    printf("\n\n");
    CarteAfficher(carte);
    
    perso.stats.vie=5;
    
    printf("MonstreTester : \n\n");
    
    do{
        printf("\nMenu :\n");
        printf(" 1 - Deplacement Monstre\n");
        printf(" 6 - Quitter\n\n");
        
        printf("Votre choix :");
        scanf("%i", &test);
        
        switch(test){
            case 1: MonstreDeplacement(&carte, &perso); CarteAfficher(carte); break;
            case 2: CarteAfficher(carte); break;
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
    
    Appel1("MonstreTester");
	
}
