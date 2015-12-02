#include "../inc/general.h"

void MonstreAmorcer(){

}

void MonstreInitialiser(){
    
}

void MonstreAttaque(t_personnage * perso)
// Attaque du joueur par le monstre
{
    Appel0("MonstreAttaque");
    
    perso->stats.vie--;
    
    printf("Vie : %i\n", perso->stats.vie);
    
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
            MonstreAttaque(perso);
         }
        else
         {
            // Verification si le joueur et le mob sont dans la même salle
            if((carte->cord.x/TAILLE_CARTE_X==carte->monstre[i].monstrePos.x/TAILLE_CARTE_X) && (carte->cord.y/TAILLE_CARTE_Y==carte->monstre[i].monstrePos.y/TAILLE_CARTE_Y))
             {
                if(((carte->cord.x>carte->monstre[i].monstrePos.x) || (carte->cord.y>carte->monstre[i].monstrePos.y)))
                 {
                    if(carte->cord.x>carte->monstre[i].monstrePos.x)
                     {
                        carte->monstre[i].monstrePos.x++;
                     }
                    else
                     {
                        carte->monstre[i].monstrePos.y++;
                     }
                 }
                else
                 {
                    if(carte->cord.x<carte->monstre[i].monstrePos.x)
                     {
                        carte->monstre[i].monstrePos.x--;
                     }
                    else
                     {
                        carte->monstre[i].monstrePos.y--;
                     }
                 }
             }
         }
     }
    
    printf(" Joueur : %i / %i\n", carte->cord.x, carte->cord.y);
    printf(" Monstre : %i / %i\n", carte->monstre[0].monstrePos.x, carte->monstre[0].monstrePos.y);
    
    Appel1("MonstreDeplacement");
    
}

void MonstrePositionner(t_carte * carte)
// Positionnement du monstre dans les salles
{
    int i, hasardX, hasardY;
    
    
    for(i=0; i<NB_MAX_MONSTRE; i++)
    {
        do{
            hasardX=uHasard(TAILLE_CARTE_X);
            hasardY=uHasard(TAILLE_CARTE_Y);
        }while(carte->grille[hasardX][hasardY]!=2);
        
        carte->monstre[0].monstrePos.x=hasardX;
        carte->monstre[0].monstrePos.y=hasardY;
        
        printf("%i/%i\n", hasardX, hasardY);
    }
}

void MonstreTester(){
	int test;
    
    Appel0("MonstreTester");
    
    t_personnage perso;
    t_carte carte;
    
    carte=CarteCharger();
    
    carte.cord.x=1;
    carte.cord.y=1;
    
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
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
    
    Appel1("MonstreTester");
	
}
