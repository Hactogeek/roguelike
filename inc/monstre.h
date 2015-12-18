/**
*	\file monstre.h
*	\brief  Prototype fonction monstre
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/
void MonstreAmorcer();
/** \brief Vérification de la vie de tout les monstres, si mort ils sont placés en (0,0)
*   \param carte La structure de la carte
*/
void MonstreMort(t_carte * carte);
/** \brief Déplacement des monstres
*   \param carte La structure de la carte
*   \param perso La structure personnage
*/
void MonstreDeplacement(t_carte * carte, t_personnage * perso);
/** \brief Position du monstre par son id
*   \param carte La structure de la carte
*   \param i L'id du monstre
*   \param x Pointeur retour position x
*   \param y Pointeur retour position y
*/
void MonstrePositionParId(t_carte * carte, int i, int * x, int * y);
/** \brief Retourne l'id s'il y a un monstre en position (x,y)
*   \param carte La structure de la carte
*   \param x Pointeur retour position x
*   \param y Pointeur retour position y
*   \return -1 si pas de monstre, sinon retourne l'id du monstre
*/
int MonstreIdParPosition(t_carte * carte, int x, int y);
/** \brief Positionnement des monstres aléatoirement sur la carte
*   \param carte La structure de la carte
*   \param monstrePuissance Puissance des monstres placés
*/
void MonstrePositionner(t_carte * carte, int monstrePuissance);
void MonstreTester();
