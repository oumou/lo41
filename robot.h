#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "anneau.h"

#define REMPLI 869
#define bon 16
#define pas_bon 14

/*typedef struct {
    int type; // 1 à 6
    int mode; // 0 = normal 1= degradé
} Robot;*/

/* fonction réaliser par les robots */


// chaque operation consite a incrementer la casse du tableau op_suivi a la position de l'operation
// op1 case 0 op2 case 1 ....
int operation(Objet *o, int numero_operation);

//fonction permettant au robot de scruter ce qui a devant lui
int regarde_devant (anneau a , int position); // revoie vide ou rempli

//fonction deposer un objet dans l'anneau
int deposer_objet(anneau a , int position, Objet o);

//fonction permettant de recuperer un objet dans l'anneau
// apres recuperation, la section doit etre vide
Objet prendre_objet(anneau a, int position);

//fonction permettant à un robot de determiner s'il peut prend un objet ou pas

/* en mode normal */
    int scan_robot1(Objet o);
    int scan_robot2(Objet o);
    int scan_robot3(Objet o);
    int scan_robot4(Objet o);
    int scan_robot5(Objet o);
    int scan_robot6(Objet o);

/*en mode dégradé */
    int  scan_robot1_degrade_mode(Objet o);
    int  scan_robot2_degrade_mode(Objet o);
    int  scan_robot3_degrade_mode(Objet o);
    int  scan_robot4_degrade_mode(Objet o);

//fonction thread de chaque robot

void* robot1(void *arg);
void* robot2(void *arg);
void* robot3(void *arg);
void* robot4(void *arg);
void* robot5(void *arg);
void* robot6(void *arg);


/* le robot regarde si le produit semi_fini a tout c'est operation effectuée
 si oui le met à l'état fini. realiser dans les les op5 op6 op3 op1 car elles sont
 celles qui cloiturent la frabrication des differents produits
 */

void update_etat_pdt(Objet *o);



#endif // ROBOT_H_INCLUDED
