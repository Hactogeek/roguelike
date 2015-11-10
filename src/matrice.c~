#include "../includes/general.h"

void afficherGrille()
{
    /* Affichage de la grille de jeu */
    
    int i, j;
    
    printf("\n");
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%c ", grille[i][j].lettre); 
        }
        
        printf("\n");
    }
    printf("\n");
}

void initGrille()
{
    /* Initialisation de la grille de jeu par le joueur */
    
    int i, j;
    
    /* Initialisation de la matrice a 0 */
    
    for(i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            grille[i][j].lettre='0';
        }
    }
    
    /* Initialisation de la matrice avec les valeurs de l'utilisateur */
    
    for(i=0; i<N; i++)
    {
        printf("Ligne : %i \n", i);
        for(j=0; j<N; j++)
        {
            printf("Colonne : %i \n", j);
            
            printf("Lettre de la case :");
            do {
		    scanf("%c", &grille[i][j].lettre);
	    }while(grille[i][j].lettre < 'a' || grille[i][j].lettre > 'z'); 
            
            printf("Point de la case :");
            do {
           	 scanf("%i", &grille[i][j].point);
            }while(grille[i][j].point < 0 || grille[i][j].point > 9); 
            
            printf("Bonus optionnel de la case :");
             scanf("%2c", grille[i][j].bonus);
            
            printf("\n\n");
        }
    }
    
    printf("Saisie de la grille de jeu terminé\n");
    
}
