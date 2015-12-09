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
    
    Appel1("MonstreAttaque");
}

void MonstreDeplacement(t_carte * carte, t_personnage * perso)
// Déplacement monstre en fonction du joueur
{
    int i;
    
    Appel0("MonstreDeplacement");
    
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
                        carte->monstre[i].monstrePos.x++;
                     }
                    else
                     {
                        // Si le monstre est en dessous
                        carte->monstre[i].monstrePos.y++;
                     }
                 }
                else
                 {
                    // Si le monstre est au dessus ou a gauche du joueur
                    if(carte->cord.x<carte->monstre[i].monstrePos.x)
                     {
                        // Si le monstre est a gauche du joueur
                        carte->monstre[i].monstrePos.x--;
                     }
                    else
                     {
                         // Si le monstre est au dessus du joueur
                         carte->monstre[i].monstrePos.y--;
                     }
                 }
             }
         }
     }
    
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
        
        printf("%i %i\n",hasardX, hasardY);
    }
}


void MonstreTester(){
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
