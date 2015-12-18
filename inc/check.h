/**
*	\file check.h
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 d�cembre 2015
*/
void CheckAmorcer();
void CheckTester();

int EstContenuDans(int nb1, int nb2, int nb_a_chercher);/**<Retourne 1 si le nombre donn� en troisi�me param�tre est compris entre les deux autres nombres (inclus)*/

int CheckTestPersonnage(t_personnage perso);/**<Retourne 1 si la vie du personnage est a 0 ou moins cela retourne 1*/

int CheckTestEtage(t_carte pos);/**<Retourne 1 si le joueur est sur une case de changement d'etage*/

int CheckMonstre(int x, int y, t_carte carte);/**<Retourne 1 si il y a un monstre aux coordonn�es indiqu�*/

int CheckMur(int x, int y, t_carte carte);/**<Retourne 1 si il y a un mur au coordonn� saisie*/

int CheckMonstreVie(int idMob,t_carte carte);/**<Retourne 1 si le monstre est en vie par rapport a son ID*/

int CheckMonstreEnVieIci(int x, int y, t_carte carte);/**<Retourne 1 s'il y a un mostre en vie aux coordon�nes indiqu�es*/

int CheckChemin(int x, int y, t_carte carte);/**<Retourne 1 si il y a un chemin au coordonn� saisie*/

int CheckUpNiveau(t_personnage player);/**<retourne 1 si le joueur merite d'up*/

int CheckSalle(int x, int y, t_carte carte);/**<Retourne 1 si il y a une salle au coordonn� saisie*/

int CheckEscalier(int x, int y, t_carte carte);/**<Retourne 1 si le joueur est sur un escalier*/

int CheckSalleVide(int salleX, int salleY, t_carte carte);/**<Retourne 1 si la salle est vide (uniquement compos�e de vide, sans mur ni rien)*/

int CheckVide(int x, int y, t_carte carte);/**<etourne 1 si la case envoy�e en param�tre est vide*/
int CheckSalleJoueur(int x, int y, t_carte carte);/**<Retourne 1 si le joueur est dans une salle*/
