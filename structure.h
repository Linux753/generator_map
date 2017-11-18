#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#define VIDE 0
#define CHEMIN 1
#define MUR 2
#define ESCALIER 3
#define SOL_SALLE 4
#define MUR_SALLE 5

typedef struct Terrain Terrain;
struct Terrain{
    int type;
    int numeroSalle;
};
typedef struct Salle Salle;
struct Salle{
    int position;
    int hauteur;
    int largeur;
    int *occupeAvecMur;
    int *occupeSansMur;
    int numeroSalle;
};
typedef struct Carte Carte;
struct Carte{
    Terrain *terrain;
    int largeur;
    int hauteur;
    int nbSalle;
};

#endif // STRUCTURE_H_INCLUDED
