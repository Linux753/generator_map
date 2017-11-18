#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Generateur_chemin.h"
#include "Generateur_carte_alea.h"
#include "Generateur_salle_alea.h"
#include "structure.h"

void initialiserCarte(Carte *carte){
    //printf("initialiserCarte");
    int i=0;
    int compteur = 0;
    for(i=0;i<=((carte->largeur*carte->hauteur)-1);i++){
        if(compteur==(carte->largeur-1)){
            carte->terrain[i].type=MUR;
            carte->terrain[i].numeroSalle=0;
            compteur++;
        }
        else if(compteur==carte->largeur){
            carte->terrain[i].type=MUR;
            carte->terrain[i].numeroSalle=0;
            compteur=1;
        }
        else if(i>=0 && i<=(carte->largeur-1)){
            carte->terrain[i].type=MUR;
            carte->terrain[i].numeroSalle=0;
            compteur++;
        }
        else if(i>=(((carte->largeur*carte->hauteur)-1)-carte->largeur)&&i<=((carte->largeur*carte->hauteur)-1)){
            carte->terrain[i].type=MUR;
            carte->terrain[i].numeroSalle=0;
            compteur++;
        }
        else{
            compteur++;
            carte->terrain[i].type=VIDE;
            carte->terrain[i].numeroSalle=0;
        }
    }
    for(i=0; i<carte->largeur*carte->hauteur; i++){
        carte->terrain[i].numeroSalle=0;
    }
}

void afficherCarte(Carte *carte){
   // printf("afficherCarte");
    int i=0 , compteur=0;
    for(i=0; i<=(carte->hauteur*carte->largeur)-1; i++){
        switch(carte->terrain[i].type){
            case VIDE :
                printf("  ");
                break;
            case CHEMIN :
                printf("@ " );
                break;
            case MUR:
                printf("[]" );
                break;
            case ESCALIER:
                printf("E ");
                break;
            case MUR_SALLE :
                printf("##");
                break;
            case SOL_SALLE :
                printf("..");
                break;
            case PORTE :
//                if(carte->terrain[i].orientation==HORIZONTALE){
//                    printf("__");
//                }
//                else if(carte->terrain[i].orientation==VERTICALE){
//                    printf("| ");
//                }
                printf("P ");
                break;
            case MUR_CHEMIN :
                printf("+ ");
                break;
        }
        if(compteur==(carte->largeur-1)){
            compteur=0;
            printf("\n");
        }else{
            compteur++;
        }
    }
}
Carte generateurCarteAlea(int largeur , int hauteur ){
        //printf("generateurcarteAlea");
        Carte carte;
        carte.terrain = malloc(sizeof(Terrain)*(largeur*hauteur));
        if(carte.terrain==NULL){
            printf("Erreur d'allouage de mémoire");
            exit(1);
        }
        carte.largeur=largeur;
        carte.hauteur = hauteur;
        initialiserCarte(&carte);
        genererSalleAlea(&carte);
        fermerSalle(&carte);
        dessinerPorte(&carte);
        return carte;
}
void quitterGenerateur(Carte *carte){
    //printf("quitterGenerateur");
    free(carte->terrain);
    carte->terrain=NULL;
}
