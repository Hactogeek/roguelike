#include "../inc/general.h"

void DeplacementAmorcer(){
}

void DeplacementTester(int t){
    t_carte map;
    switch(t){case 1 :DeplacementMarcher(&map); break;}
}


/** \fn int DeplacementMarcher(t_carte * map)
*   \brief Deplace le personnage et retourne l'id du monstre si il y a un combat a effectué
*   \param carte La carte du jeu
*   \return integer L'id du mob / -1 / -2
*/
int DeplacementMarcher(t_carte * map){
    char cmd_move;

	printf("Saisir un deplacement : ");
    scanf(" %1c",&cmd_move);
    printf("\n");

    switch(cmd_move) {
		case 's':	if(CheckMonstre(map->cord.x+1,map->cord.y,*map)==1){
		    			return MonstreIdParPosition(map,map->cord.x+1,map->cord.y);
		    		} else if (CheckSalle(map->cord.x+1,map->cord.y,*map)==1||CheckChemin(map->cord.x+1,map->cord.y,*map)||CheckEscalier(map->cord.x+1,map->cord.y,*map)){
		    			map->cord.x +=1;
					}
					break;

		case 'q':	if(CheckMonstre(map->cord.x,map->cord.y-1,*map)==1){
				    	return MonstreIdParPosition(map,map->cord.x,map->cord.y-1);
				    }else if(CheckSalle(map->cord.x,map->cord.y-1,*map)==1||CheckChemin(map->cord.x,map->cord.y-1,*map)||CheckEscalier(map->cord.x,map->cord.y-1,*map)){
				    	map->cord.y -=1;
				    }
					break;
		case 'z':	if(CheckMonstre(map->cord.x-1,map->cord.y,*map)==1){
				    	return MonstreIdParPosition(map,map->cord.x-1,map->cord.y);
				    }else if(CheckSalle(map->cord.x-1,map->cord.y,*map)==1||CheckChemin(map->cord.x-1,map->cord.y,*map)||CheckEscalier(map->cord.x-1,map->cord.y,*map)){
				    	map->cord.x -=1;
				    }
				    break;
		case 'd':	if(CheckMonstre(map->cord.x,map->cord.y+1,*map)==1){
				    	return MonstreIdParPosition(map,map->cord.x,map->cord.y+1);
				    }else if(CheckSalle(map->cord.x,map->cord.y+1,*map)==1||CheckChemin(map->cord.x,map->cord.y+1,*map)||CheckEscalier(map->cord.x,map->cord.y+1,*map)){
				    	map->cord.y +=1;
				    }
					break;
		default:/*printf("Les deplacement se font avec les touches zqsd, veuillez saisir un deplacment valide.\n");*/
					return -2;
					break;
	} // Effectue le deplacement et la verification de la position, le personnage ne peut pas etre dans un mur.
	return -1;
}
