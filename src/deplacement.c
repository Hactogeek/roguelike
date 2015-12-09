#include "../inc/general.h"

void DeplacementAmorcer(){
}

void DeplacementTester(int t){
    t_carte map;
    switch(t){case 1 :DeplacementMarcher(&map); break;}
}

void implementationPos(t_posMonstre * mob, int x,int y){
	mob->x=x;
	mob->y=y;
}

/* Deplace le personnage et retourne la position du monstre si il y a un combat a effectué*/
t_posMonstre DeplacementMarcher(t_carte * map){
	t_posMonstre combat;
	char cmd_move;
    printf("Position du personnage avant : %i %i\n",map->cord.x,map->cord.y);
    printf("Saisir un deplacement : ");
	scanf(" %c",&cmd_move);
     switch(cmd_move){
        case 's':{
        	if(CheckMonstre(map->cord.x+1,map->cord.y,*map)==1){
        		implementationPos(&combat,map->cord.x+1,map->cord.y);
        		return combat;
        	}else if(CheckMur(map->cord.x+1,map->cord.y,*map)==0){
        		map->cord.x +=1;
        	}
        	//map->cord.x += (map->grille[map->cord.x+1][map->cord.y]!=1);
        	break;
        }
		case 'q':{
			if(CheckMonstre(map->cord.x,map->cord.y-1,*map)==1){
        		implementationPos(&combat,map->cord.x,map->cord.y-1);
        		return combat;
        	}else if(CheckMur(map->cord.x,map->cord.y-1,*map)==0){
        		map->cord.y -=1;
        	}
			//map->cord.y -= (map->grille[map->cord.x][map->cord.y-1]!=1);
			break;
		}
        case 'z':{
        	if(CheckMonstre(map->cord.x-1,map->cord.y,*map)==1){
        		implementationPos(&combat,map->cord.x-1,map->cord.y);
        		return combat;
        	}else if(CheckMur(map->cord.x-1,map->cord.y,*map)==0){
        		map->cord.x -=1;
        	}
        	//map->cord.x -= (map->grille[map->cord.x-1][map->cord.y]!=1);
        	break;
        }
		case 'd':{
			if(CheckMonstre(map->cord.x,map->cord.y+1,*map)==1){
        		implementationPos(&combat,map->cord.x,map->cord.y+1);
        		return combat;
        	}else if(CheckMur(map->cord.x,map->cord.y+1,*map)==0){
        		map->cord.y +=1;
        	}
			//map->cord.y += (map->grille[map->cord.x][map->cord.y+1]!=1);
			break;
		}
        default:printf("Les deplacement se font avec les touches zqsd, veuillez saisir un deplacment valide");break;
	}// Effectue le deplacement et la verification de la position, le personnage ne peut pas etre dans un mur.
	implementationPos(&combat,-1,-1);
    return combat;
}

