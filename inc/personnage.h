/**
*	\file personnage.h
*	\brief  Prototype des fonctions pour le personnage
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/

void PersonnagePositionner(t_carte * carte);/**<Cherche un endroit pour placer le personnage dans une salle*/

void PersonnageInitialiser(t_personnage * perso);/**<Initialise les parametres de la variable perso*/

void PersonnageAfficherPseudo(t_personnage player);/**<Affiche le pseudo en couleur du player */

void PersonnageAfficherVie(t_personnage player);/**<Affiche la vie en couleur du player*/

void PersonnageAfficherNiveau(t_personnage player);/**<Affiche le niveau en couleur du player*/

void PersonnageAfficherScore(t_personnage player);/**<Affiche le score en couleur du player*/

void PersonnageAfficherXP(t_personnage player);/**<Affiche l'xp en couleur du player*/

void PersonnageAfficherXpRequis(t_personnage player);/**<Affiche l'xp requis en couleur du player*/

void PersonnageAfficher(t_personnage perso);/**<Affiche les parametre du player*/

void PersonnageSauvegarder(t_personnage * perso);

void PersonnageLevelUp(t_personnage * player);/**<Fait passer le player d'un niveau et increment ses paramètres*/
void PersonnageAfficherPseudo(t_personnage player);/**<Affiche le pseudo en couleur du player */
