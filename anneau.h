#ifndef ANNEAU_H_INCLUDED
#define ANNEAU_H_INCLUDED

#include "Objet.h"


typedef Objet anneau[16] ;

//la fonction qui initialise l'anneau
void initialisation_anneau(anneau a);

// fonction qui gère la rotation d'un anneau
void rotation (anneau a);

// fonction qui depose un objet sur l'anneau
int deposer_objet_anneau(anneau a , int position, Objet o);

// fonction qui controle l'état de l'anneau en determinant sont nombre de case vide
int state_anneau(anneau a);

// permettant au thread consommateur_piece de recuperer une piece de la rampe
Objet consommateur_rampe(Objet *r,int *nbre_piece);

//fonction permettant au thread consommateur_piece de savoir s'il la section devant la rampe est vide
int regarde_devant_conso(anneau a , int position); // revoie vide ou rempli

// fonction thread pour l'anneau
void *lanneau(void *arg);

// fonction thread pour le consommateur de piece
void *consommateur_piece(void *arg);

/*le thread  anneau  comporte "creer deux"
    l'anneau comporte deux threads l'un pour la rotation de l'anneau
    l'autre pour deposer les pieces sur l'anneau
*/
#endif // ANNEAU_H_INCLUDED
