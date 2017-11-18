#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generateur_chemin.h"
#include "Generateur_carte_alea.h"
#define LARGEUR 100
#define HAUTEUR 100
int main()
{
    int recomencer=0 , temps=0;
    temps=time(NULL);
    srand(temps);
    printf("Met un 1 si tu veux générer une carte , un 0 pour quitter. Attention agrandi la fenetre avant de générer une carte pour un bonne affichage de celle-ci\n\nNb time= %d" , temps);
    scanf("%d" , &recomencer);
    while(recomencer){
    int dimension = rand_a_b(100 , 120);
    Carte carte =generateurCarteAlea(dimension , dimension );
    afficherCarte(&carte);
    printf("Dimension carte : \nHauteur = %d\nLargeur = %d\n\nMet un 1 si tu veux générer une autre carte , un 0 pour quitter", carte.hauteur , carte.largeur);
    scanf("%d" , &recomencer);
    quitterGenerateur(&carte);
    }

    return 0;
}

