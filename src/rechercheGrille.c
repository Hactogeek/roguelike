

#include "../includes/general.h"


int find_letter(char c/*, coord * coordonnee*/)
{
    int i, j;
    
    bool trouve = false;
    
    for(i=-1;i<=1 && !trouve; i++)
    {
        for(j=-1; j<=1 && !trouve; j++)
        {
            if(coordonnee.x + i >=0 && coordonnee.x + i <N && coordonnee.y + j >=0 && coordonnee.y + j <N )
            {
                if(c == grille[coordonnee.x + i][coordonnee.y + j].lettre && grille[coordonnee.x + i][coordonnee.y + j].visited == 0)
                {
                    trouve = true;
                    coordonnee.x += i;
                    coordonnee.y += j;
                    grille[i][j].visited=1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int chercheMotGrille(char mot[])
{
    int i, j;
    
    bool possible = false;
    bool trouve = false;
    
    //coord coordonnee;
    
    for(i=0; i<N && !trouve; i++)
    {
        for(j=0; j<N && !trouve; j++)
        {
            if(mot[0]==grille[i][j].lettre)
            {
                coordonnee.x=i;
                coordonnee.y=j;
                trouve=true;
                possible=true;
                grille[coordonnee.x][coordonnee.y].visited=1;
            }
        }
    }
    
    for(i=1; i<strlen(mot) && possible; i++)
    {
        if(!find_letter(mot[i]/*,&coordonnee*/))
        {
            possible = false;
        }
    }
    
    for(i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            grille[i][j].visited=0;
        }
    }
    
    if(possible)
    {
        printf("%s\n", mot);
        return 1;
    }
    
    return 0;
}

void chercheMot()
{
    int i,j;
    int k=0;
    
    char lettre;
    
    for(i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            grille[i][j].visited=0;
        }
    }
    
    t_valeurMot mot;
    
    FILE * dictionnaire;
    
    dictionnaire=fopen("dico_opti.txt", "r");
    
    if(dictionnaire!=NULL)
    {
        do{
            lettre=fgetc(dictionnaire);
            if(lettre=='\n')
            {
                mot.mot[k]='\0';
            
                if(chercheMotGrille(mot.mot))
                {
                    //printf("OK");
                }
            
                k=0;
            }
            else
            {
                mot.mot[k]=lettre;
                k++;
            }
        }while (!feof(dictionnaire));
        fclose(dictionnaire);
    }
    else
    {
        printf("Erreur dans l'ouverture du dictionnaire");
    }
    
    
}
