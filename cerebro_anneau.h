#ifndef CEREBRO_ANNEAU_H_INCLUDED
#define CEREBRO_ANNEAU_H_INCLUDED
#include<pthread.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

pthread_mutex_t  m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t peux_produire = PTHREAD_COND_INITIALIZER;
pthread_cond_t peux_consommer = PTHREAD_COND_INITIALIZER;

pthread_mutex_t  mutex_rotation = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t peux_roter = PTHREAD_COND_INITIALIZER;

pthread_mutex_t mutex_sur_nbe_section = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t peux_deposer = PTHREAD_COND_INITIALIZER;
//pthread_cond_t peux_consommer = PTHREAD_COND_INITIALIZER;

int nbre_produit_rampe =0;

//nombre de case occupés dans l'anneau
int nbe_section_occupe =0;

#endif // CEREBRO_ANNEAU_H_INCLUDED
