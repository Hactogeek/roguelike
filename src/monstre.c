#include "../inc/general.h"

void MonstreAmorcer(){

}

void MonstreInitialiser(){
    
}

void MonstreDeplacement(t_carte carte)
// Déplacement monstre en fonction du joueur
{
    int i;
    for(i=0; i<NB_MAX_MONSTRE; i++)
     {
        if((carte.cord.x == carte.monstre[i].x-1) || (carte.cord.x == carte.monstre[i].x+1) || (carte.cord.y == carte.monstre[i].y-1) || (carte.cord.y == carte.monstre[i].y+1))
         {
            MonstreAttaque()
         }
        else
         {
            if((carte.cord.x>carte.monstre[i].x) || (carte.cord.y>carte.monstre[i].y))
             {
                if(carte.cord.x>carte.monstre[i].x)
                 {
                    carte.monstre[i].x--;
                 }
                else
                 {
                    carte.monstre[i].y--;
                 }
             }
            else
             {
                if(carte.cord.x<carte.monstre[i].x)
                 {
                    carte.monstre[i].x++;
                 }
                else
                 {
                    carte.monstre[i].y++;
                 }
             }
         }
     }
}

void MonstreAttaque()
// Attaque du joueur par le monstre
{

}

void MonstreTester(){
	int test;
    
    printf("MonstreTester : \n\n");
    
    do{
        printf("\nMenu :\n");
        printf(" 6 - Quitter\n\n");
        
        printf("Votre choix :");
        scanf("%i", &test);
        
        switch(test){
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
	
}
