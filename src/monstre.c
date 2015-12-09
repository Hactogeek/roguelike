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
    carte->monstre[i].monstreVie--;
    
    printf("Joueur Vie : %i\n", perso->stats.vie);
    printf("Monstre Vie : %i\n", carte->monstre[i].monstreVie);
    
    Appel1("MonstreAttaque");
}

void MonstreDeplacement(t_carte * carte, t_personnage * perso)
// Déplacement monstre en fonction du joueur
{
    int i;
    
    Appel0("MonstreDeplacement");
    
    CarteAfficher(*carte);
    
    for(i=0; i<NB_MAX_MONSTRE; i++)
     {
        // Si le monstre et le joueur sont cote a cote, attaque
        if(((carte->cord.x == carte->monstre[i].monstrePos.x-1) && (carte->cord.y == carte->monstre[i].monstrePos.y)) ||
           ((carte->cord.x == carte->monstre[i].monstrePos.x+1) && (carte->cord.y == carte->monstre[i].monstrePos.y)) ||
           ((carte->cord.y == carte->monstre[i].monstrePos.y-1) && (carte->cord.x == carte->monstre[i].monstrePos.x)) ||
           ((carte->cord.y == carte->monstre[i].monstrePos.y+1) && (carte->cord.x == carte->monstre[i].monstrePos.x)))
         {
            MonstreAttaque(perso, carte, i);
         }
        else
         {
            // Verification si le joueur et le mob sont dans la même salle
            if((carte->cord.x/TAILLE_CARTE_X==carte->monstre[i].monstrePos.x/TAILLE_CARTE_X) &&
               (carte->cord.y/TAILLE_CARTE_Y==carte->monstre[i].monstrePos.y/TAILLE_CARTE_Y))
             {
                if(((carte->cord.x>carte->monstre[i].monstrePos.x) || (carte->cord.y>carte->monstre[i].monstrePos.y)))
                 {
                     // Si le monstre est en dessous ou a droite du joueur
                    if(carte->cord.x>carte->monstre[i].monstrePos.x)
                     {
                         // Si le monstre est a droite du joueur
                         if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y]!=1)
                         {
                             // Si la case a gauche n'est pas un mur, deplacement a gauche
                             carte->monstre[i].monstrePos.x++;
                         }
                         else
                         {
                             // Si la case a gauche est un mur
                             if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y-1]!=1)
                             {
                                 // Si la case au dessus a gauche est libre, deplacement vers le haut
                                 carte->monstre[i].monstrePos.y--;
                             }
                             else
                             {
                                 // Sinon déplacement vers le bas
                                 carte->monstre[i].monstrePos.y++;
                             }
                         }
                     }
                    else
                     {
                         // Si le monstre est en dessous
                         if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y+1]!=1)
                         {
                             // Si la case au dessus n'est pas un mur, deplacement vers le haut
                             carte->monstre[i].monstrePos.y++;
                             
                         }
                         else
                         {
                             // Si la case au dessus est un mur
                             if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y-1]!=1)
                             {
                                 // Si la case en haut a droite n'est pas un mur, deplacement a droite
                                 carte->monstre[i].monstrePos.x++;
                             }
                             else
                             {
                                 // Sinon deplacement a gauche
                                 carte->monstre[i].monstrePos.x--;
                             }
                         }
                     }
                 }
                else
                 {
                     // Si le monstre est au dessus ou a gauche du joueur
                    if(carte->cord.x<carte->monstre[i].monstrePos.x)
                     {
                         // Si le monstre est a gauche du joueur
                         if(carte->grille[carte->monstre[i].monstrePos.x-1][carte->monstre[i].monstrePos.y]!=1)
                         {
                             // Si la case droite n'est pas un mur, deplacement a droite
                             carte->monstre[i].monstrePos.x--;
                         }
                         else
                         {
                             // Si la case a droite est un mur
                             if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y-1]!=1)
                             {
                                 // Si la case en haut a droite n'est pas un mur, deplacement vers le haut
                                 carte->monstre[i].monstrePos.y--;
                             }
                             else
                             {
                                 // Sinon déplacement vers le bas
                                 carte->monstre[i].monstrePos.y++;
                             }
                         }
                     }
                    else
                     {
                         // Si le monstre est au dessus du joueur
                         if(carte->grille[carte->monstre[i].monstrePos.x][carte->monstre[i].monstrePos.y-1]!=1)
                         {
                             // Si la case en dessous n'est pas un mur, deplacement vers le bas
                             carte->monstre[i].monstrePos.y--;
                         }
                         else
                         {
                             // Si la case en dessous est un mur
                             if(carte->grille[carte->monstre[i].monstrePos.x+1][carte->monstre[i].monstrePos.y-1]!=1)
                             {
                                 // Si la case en bas a droite n'est pas un mur, deplacement a droite
                                 carte->monstre[i].monstrePos.x++;
                             }
                             else
                             {
                                 // Sinon deplacement a gauche
                                 carte->monstre[i].monstrePos.x--;
                             }
                         }
                     }
                 }
             }
         }
     }
    
    //printf(" Joueur : %i / %i\n", carte->cord.x, carte->cord.y);
    
    Appel1("MonstreDeplacement");
    
}

void MonstrePositionParId(t_carte * carte, int i, int * x, int * y)
{
    *x=carte->monstre[i].monstrePos.x;
    *y=carte->monstre[i].monstrePos.y;
}

int MonstreIdParPosition(t_carte * carte, int x, int y)
{
    int i;
    for(i=0; i<NB_MAX_MONSTRE; i++)
    {
        if((carte->monstre[i].monstrePos.x==x) && (carte->monstre[i].monstrePos.y==y))
        {
            return i;
        }
    }
    return 0;
}

void MonstrePositionner(t_carte * carte)
// Positionnement du monstre dans les salles
{
    int i, hasardX, hasardY, hasardMonstre;
    
    srand(time(NULL));
    
    //hasardMonstre=uHasard(NB_MAX_MONSTRE);
    
    for(i=0; i<NB_MAX_MONSTRE; i++)
    {
        do{
            hasardX=uHasard(TAILLE_CARTE_X);
            hasardY=uHasard(TAILLE_CARTE_Y);
        }while((carte->grille[hasardX][hasardY]!=2) && ((carte->cord.x!=hasardX) && (carte->cord.y!=hasardY)));
        
        carte->monstre[i].monstrePos.x=hasardX;
        carte->monstre[i].monstrePos.y=hasardY;
        carte->monstre[i].monstreVie=5;
    }
}


void MonstreTester(){
	int test;
    
    Appel0("MonstreTester");
    
    t_personnage perso;
    t_carte carte;
    
    carte=CarteCharger();
    
    //PersonnagePositionner(&carte);
    
    carte.cord.x=25;
    carte.cord.y=18;
    
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
            case 1: MonstreDeplacement(&carte, &perso); break;
            case 2: CarteAfficher(carte); break;
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
    
    Appel1("MonstreTester");
	
}
