typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_stats;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;

typedef struct {char nom[20]; int niveau; t_stats statistique; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

void PersonnageAmorcer();
void PersonnageInitialiser(t_personnage perso);
void PersonnageAfficher(t_personnage perso);
void PersonnageTester(/*int test*/);
