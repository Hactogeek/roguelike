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
    
    Appel0("MonstreDeplacement");
    
    int i;
    for(i=0; i<NB_MAX_MONSTRE; i++)
     {
        // Si le monstre et le joueur sont cote a cote, attaque
        if(((carte->cord.x == carte->monstre[i].x-1) && (carte->cord.y == carte->monstre[i].y)) ||
           ((carte->cord.x == carte->monstre[i].x+1) && (carte->cord.y == carte->monstre[i].y)) ||
           ((carte->cord.y == carte->monstre[i].y-1) && (carte->cord.x == carte->monstre[i].x)) ||
           ((carte->cord.y == carte->monstre[i].y+1) && ((carte->cord.x == carte->monstre[i].x))))
         {
            MonstreAttaque(perso);
         }
        else
         {
            // Verification si le joueur et le mob sont dans la même salle
            if((carte->cord.x/TAILLE_CARTE_X==carte->monstre[i].x/TAILLE_CARTE_X) && (carte->cord.y/TAILLE_CARTE_Y==carte->monstre[i].y/TAILLE_CARTE_Y))
             {
                if(((carte->cord.x>carte->monstre[i].x) || (carte->cord.y>carte->monstre[i].y)))
                 {
                    if(carte->cord.x>carte->monstre[i].x)
                     {
                        carte->monstre[i].x++;
                     }
                    else
                     {
                        carte->monstre[i].y++;
                     }
                 }
                else
                 {
                    if(carte->cord.x<carte->monstre[i].x)
                     {
                        carte->monstre[i].x--;
                     }
                    else
                     {
                        carte->monstre[i].y--;
                     }
                 }
             }
         }
     }
    
    printf(" Joueur : %i / %i\n", carte->cord.x, carte->cord.y);
    printf(" Monstre : %i / %i\n", carte->monstre[0].x, carte->monstre[0].y);
    
    Appel1("MonstreDeplacement");
    
}

void MonstreTester(){
	int test;
    
    Appel0("MonstreTester");
    
    t_personnage perso;
    t_carte carte;
    
    carte.cord.x=1;
    carte.cord.y=1;
    
    carte.monstre[0].x=10;
    carte.monstre[0].y=5;
    
    perso.stats.vie=5;
    
    printf("MonstreTester : \n\n");
    
    do{
        printf("\nMenu :\n");
        printf(" 1 - Deplcement Monstre\n");
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
