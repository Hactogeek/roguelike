/**
*	\file personnage.h
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/
void PersonnageAmorcer();
void PersonnagePositionner(t_carte * carte);
void PersonnageInitialiser(t_personnage * perso);
void PersonnageAfficherPseudo(t_personnage player);
void PersonnageAfficherVie(t_personnage player);
void PersonnageAfficherNiveau(t_personnage player);
void PersonnageAfficherScore(t_personnage player);
void PersonnageAfficherXP(t_personnage player);
void PersonnageAfficherXpRequis(t_personnage player);
void PersonnageAfficher(t_personnage perso);
void PersonnageSauvegarder(t_personnage * perso);
void PersonnageTester();
void PersonnageLevelUp(t_personnage * player);
void PersonnageAfficherPseudo(t_personnage player);
