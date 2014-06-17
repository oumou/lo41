#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED

#include "anneau.h"
typedef struct {
    int type;
    Objet pdt;
}message_capteur;



//fonction permettant au capteur de scruter ce qui a devant lui
int regarde_devant_capteur (anneau a , int position); // revoie vide ou rempli

/*fonction permettant de scanner l'objet devant lui. determine si ce dernier est fini
ou pas*/

int scan_capteur(Objet o);


/*fonction permettant de recuperer un objet dans l'anneau
 apres recuperation, la section doit etre vide
 une fois recuperer l'objet est stocké dans une file de message
 */
void prendre_objet_capteur(anneau a, int position);

//fonction du thread qui gera le capteur
void * capteur (void *arg);


/*/ regarde si l'objet devant est fini ou pas s'il oui il le retire
void check_objet_devant(anneau a, int position);*/



#endif // CAPTEUR_H_INCLUDED
