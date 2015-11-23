#define N
#define M

typedef struct {int contenuCase;}t_case;
typedef struct {t_case grille[N][M];}t_carte;

typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_stats;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;
typedef struct {char nom[20]; int niveau; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;
