#include "../inc/general.h"

void DeplacementAmorcer(){
}

void DeplacementTester(int t){
    t_carte map;
    switch(t){case 1 :DeplacementMarcher(&map); break;}
}

/* Deplace le personnage qui est au position entré */
void DeplacementMarcher(t_carte * map){
	
	char cmd_move;
    Appel0("DeplacementMarcher");
    printf("Position du personnage avant : %i %i\n",map->cord.x,map->cord.y);
    printf("Saisir un deplacement : ");
	scanf(" %c",&cmd_move);
     switch(cmd_move){
        case 'd': map->cord.x += (map->grille[map->cord.x+1][map->cord.y]!=1);break;
	case 's': map->cord.y -= (map->grille[map->cord.x][map->cord.y-1]!=1);break;
        case 'q': map->cord.x -= (map->grille[map->cord.x-1][map->cord.y]!=1);break;
	case 'z': map->cord.y += (map->grille[map->cord.x][map->cord.y+1]!=1);break;
        case 't': break;
        default: break;
	}// Effectue le deplacement et la verification de la position, le personnage ne peut pas etre dans un mur.
    printf("Position du personnage après : %i %i\n",map->cord.x,map->cord.y);
    Appel1("DeplacementMarcher");
    
}

