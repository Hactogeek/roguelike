#include "../includes/general.h"

int chercheMotDico(char mot[])
{
    int taille;
    
    char chaine[N*N];
    
    FILE * dictionnaire;
    
    dictionnaire=fopen("../dico.txt","r");
    
    if(dictionnaire != NULL)
    {
        while(!feof(dictionnaire))
        {
            fgets(chaine, N*N+1, dictionnaire);
            
            taille=strlen(chaine);
            
            if(taille <=17 || taille >=3)
            {
                if(strcmp(mot, chaine)==0)
                {
                    return 1;
                }
            }
        }
    }
    else
        printf("Erreur dans l'ouverture du dictionnaire");
    
    return 0;
}