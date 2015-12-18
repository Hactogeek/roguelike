/**
*	\file deplacement.h
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/

void DeplacementAmorcer();
void DeplacementTester(int t);
int DeplacementMarcher(int cmd_move, t_carte * map);/**<Deplace le personnage et retourne l'id du monstre si il y a un combat a effectué*/
