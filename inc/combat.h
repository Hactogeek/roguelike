/**
*	\file combat.h
*	\brief  Prototype fonction combat joueur->monstre
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/
void CombatRemporter(t_personnage * player,t_carte * carte,int idMob);/**<Distribue l'xp et augmente le score au joueur et test si il doit le faire passer de niveau*/
void CombatTaper(t_personnage * player,t_carte * carte,int idMob);/**<Retire des pdv au monstre passer en id*/
