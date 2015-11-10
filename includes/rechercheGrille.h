typedef struct{char mot[N*N]; int score;}t_valeurMot;

typedef struct{int x; int y;}coord;

int find_letter(char c/*, coord * coordonnee*/);
int chercheMotGrille(char mot[N*N]);
void chercheMot();

coord coordonnee;


