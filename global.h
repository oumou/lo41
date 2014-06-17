#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "Objet.h"
#include "anneau.h"

#define taille_rampe  4

//Les positons de chaque entité
# define ramp_ano 5
# define r1  3
# define r2  5
# define r3  10
# define r4  12
# define r5  14
# define r6   6
# define c1  1

#define normal 125
#define degrade 250
#define nbre_max_section_occupe 12
//l'anneau
anneau ano;
// la rampe
Objet rampe[taille_rampe];



// fichiers contenant les variables globales
int cadence;








#endif // GLOBAL_H_INCLUDED
