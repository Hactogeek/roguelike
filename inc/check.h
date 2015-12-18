/**
*	\file check.h
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 d�cembre 2015
*/
void CheckAmorcer();
void CheckTester();
int EstContenuDans(int nb1, int nb2, int nb_a_chercher);
int CheckTestPersonnage(t_personnage perso);
int CheckTestEtage(t_carte pos);
int CheckMonstre(int x, int y, t_carte carte);
int CheckMur(int x, int y, t_carte carte);
int CheckMonstreVie(int idMob,t_carte carte);
int CheckMonstreEnVieIci(int x, int y, t_carte carte);
int CheckChemin(int x, int y, t_carte carte);
int CheckUpNiveau(t_personnage player);
int CheckSalle(int x, int y, t_carte carte);
int CheckEscalier(int x, int y, t_carte carte);
int CheckSalleVide(int salleX, int salleY, t_carte carte);
int CheckVide(int x, int y, t_carte carte);
int CheckSalleJoueur(int x, int y, t_carte carte);