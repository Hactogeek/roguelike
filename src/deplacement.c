/**
*	\file deplacement.c
*	\brief  Deplacement du joueur
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/

#include "../inc/general.h"

/** \fn int DeplacementMarcher(int cmd_move, t_carte * map)
*   \brief Deplace le personnage et retourne l'id du monstre si il y a un combat a effectuer
*   \param cmd_move Le déplacement à effectuer
*   \param carte La carte du jeu
*   \return integer L'id du mob / -1 / -2
*/
int DeplacementMarcher(int cmd_move, t_carte * map){

    switch(cmd_move) {
		case 1:	if(CheckMonstre(map->cord.x+1,map->cord.y,*map)==1){
		    			return MonstreIdParPosition(map,map->cord.x+1,map->cord.y);
		    		} else if (CheckSalle(map->cord.x+1,map->cord.y,*map)==1||CheckChemin(map->cord.x+1,map->cord.y,*map)||CheckEscalier(map->cord.x+1,map->cord.y,*map)){
		    			map->cord.x +=1;
					}
					break;

		case 2:	if(CheckMonstre(map->cord.x,map->cord.y-1,*map)==1){
				    	return MonstreIdParPosition(map,map->cord.x,map->cord.y-1);
				    }else if(CheckSalle(map->cord.x,map->cord.y-1,*map)==1||CheckChemin(map->cord.x,map->cord.y-1,*map)||CheckEscalier(map->cord.x,map->cord.y-1,*map)){
				    	map->cord.y -=1;
				    }
					break;
		case 3:	if(CheckMonstre(map->cord.x-1,map->cord.y,*map)==1){
				    	return MonstreIdParPosition(map,map->cord.x-1,map->cord.y);
				    }else if(CheckSalle(map->cord.x-1,map->cord.y,*map)==1||CheckChemin(map->cord.x-1,map->cord.y,*map)||CheckEscalier(map->cord.x-1,map->cord.y,*map)){
				    	map->cord.x -=1;
				    }
				    break;
		case 4:	if(CheckMonstre(map->cord.x,map->cord.y+1,*map)==1){
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
