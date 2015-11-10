//
//  factorielle.c
//  
//
//  Created by Claudine Piau-Toffolon on 19/10/2015.
//./
//

#include <stdio.h>
#include <stdlib.h>
long fact (short nb)
{
    short indice;
    long factorielle_nb =1;
    for (indice = nb; indice >0; indice --)
        factorielle_nb = factorielle_nb * indice;
    return factorielle_nb;
}

int main (int argc, char *argv[])
{
    short nb_lu;
    if (argc !=2)
        exit(1);
    nb_lu = (short)atoi(argv[1]);
    printf("factorielle de %2hd =%ld\n", nb_lu, fact(nb_lu));
    return 0;
}
