#include "../inc/general.h"

void DeplacementAmorcer(){
}

void DeplacementTester(int t){
    t_carte map;
    switch(t){case 1 :DeplacementMarcher(&map); break;}
}

/* Deplace le personnage et retourne l'id du monstre si il y a un combat a effectué*/
int DeplacementMarcher(t_carte * map){
	char cmd_move;
    printf("Position du personnage avant : %i %i\n",map->cord.x,map->cord.y);
    printf("Saisir un deplacement : ");
	scanf(" %c",&cmd_move);
	
    switch(cmd_move){
        case 's':{
        	if(CheckMonstre(map->cord.x+1,map->cord.y,*map)==1){
        		return MonstreIdParPosition(carte,map->cord.x+1,map->cord.y);
        		}else if(CheckSalle(map->cord.x+1,map->cord.y,*map)==0||CheckChemin(map->cord.x+1,map->cord.y,*map)){
        		map->cord.x +=1;
        	}
        	break;
        }
		case 'q':{
			if(CheckMonstre(map->cord.x,map->cord.y-1,*map)==1){
        		return MonstreIdParPosition(carte,map->cord.x,map->cord.y);
        	}else if(CheckSalle(map->cord.x,map->cord.y-1,*map)==0||CheckChemin(map->cord.x,map->cord.y-1,*map)){
        		map->cord.y -=1;
        	}
			break;
		}
        case 'z':{
        	if(CheckMonstre(map->cord.x-1,map->cord.y,*map)==1){
        		return MonstreIdParPosition(carte,map->cord.x-1,map->cord.y);
        	}else if(CheckSalle(map->cord.x-1,map->cord.y,*map)==0||CheckChemin(map->cord.x-1,map->cord.y,*map)){
        		map->cord.x -=1;
        	}
        	break;
        }
		case 'd':{
			if(CheckMonstre(map->cord.x,map->cord.y+1,*map)==1){
        		return MonstreIdParPosition(carte,map->cord.x,map->cord.y+1);
        	}else if(CheckSalle(map->cord.x,map->cord.y+1,*map)==0||CheckChemin(map->cord.x,map->cord.y+1,*map)){
        		map->cord.y +=1;
        	}
			break;
		}
        default:printf("Les deplacement se font avec les touches zqsd, veuillez saisir un deplacment valide");break;
	}// Effectue le deplacement et la verification de la position, le personnage ne peut pas etre dans un mur.
	
    return -1;
}

