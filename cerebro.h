#ifndef CEREBRO_H_INCLUDED
#define CEREBRO_H_INCLUDED
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>


#include "Objet.h"
// la fonction de production des composants prend en parametre le nombre de produit à fabriquer

void produire_composant (int nbre_pdt1 , int nbre_pdt2 , int nbre_pdt3 ,int nbre_pdt4, Objet *r);

//deposer un objet sur la rampe
void deposer_objet_rampe(Objet o, Objet *r);

//thread gérant la production de piece
//arg ici est un tableau d'entier qui nous permet de passer les paramètres de produire_composant

void* producteur_piece(void *arg);

// controler les robots activer ou desactiver un robot cette action entrainera l'activation du degrade mode
void activation_sennin_mode();

void *cerebro (void *arg);

// thread  realisant le compte des produits finis

// faire  le compte des produits deja fabriqués
void compte_produit_fabrique();
#endif // CEREBRO_H_INCLUDED
