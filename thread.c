#include "cerebro_anneau.h"
#include "global.h"
#include "anneau.h"
#include "robot.h"
#include "cerebro.h"



/******* Fonction thread du consomateur de piece**********/

void* consommateur_piece(void * arg){
    int non_deposer ;
    int i;
    //int section;
    Objet piece;
    while (1){
        pthread_mutex_lock(&m1);
            while( nbre_produit_rampe == 0){
                printf("*******Rampe vide: arret du transfert entre rampe et anneau********\n");
                pthread_cond_signal(&peux_roter);
                pthread_cond_wait(&peux_consommer,&m1);
                printf("*******Reprise du transfert rampe-anneau********\n");
            }
            piece = consommateur_rampe(rampe, &nbre_produit_rampe);
            pthread_cond_signal(&peux_produire);
        pthread_mutex_unlock(&m1);

        //depot dans l'anneau
        non_deposer = 0;
        while ( non_deposer == 0){
            pthread_mutex_lock(&mutex_rotation);
               // printf("j'ai le mutex de rotation\n");

                if ( regarde_devant_conso(ano,ramp_ano) == vide ){
                        pthread_mutex_lock(&mutex_sur_nbe_section);
                        //section = nbe_section_occupe;
                        if(nbe_section_occupe <= nbre_max_section_occupe){
                            deposer_objet_anneau(ano,ramp_ano, piece);
                            printf("depot piece dans l'anneau\n");
                            non_deposer =1;
                            nbe_section_occupe++;
                        }
                        else{
                            printf("Anneau plein \n" );
                            pthread_cond_wait(&peux_deposer,&mutex_sur_nbe_section);
                            printf("Anneau plein \n" );
                            pthread_cond_signal(&peux_roter);
                        }
                    pthread_mutex_unlock(&mutex_sur_nbe_section);


                     /*for (i=0 ; i<16; i++){
                        printf("%d ",ano[i].nature );
                        }
                     printf("\n");*/
                }else{
                    //printf("pas pu deposer %d\n",regarde_devant_conso(ano,ramp_ano));
                }
                pthread_cond_signal(&peux_roter);
            pthread_mutex_unlock(&mutex_rotation);
        }
    }

}


/*********************** fonction thread du producteur de piece lier au cerebro c'est un sous thread du celui-ci*****************/
void * producteur_piece(void * arg){
    int *tab_arg;
    tab_arg = (void *)arg;
    //Objet *r;
    produire_composant ( *(tab_arg) , *(tab_arg + 1), *(tab_arg +2), *(tab_arg + 3) , rampe);

    printf(" \n*************Fin production composant*************\n");
    pthread_exit(NULL);
}
     /****** une sous fonction du producteur_composant()*********/
void deposer_objet_rampe(Objet o, Objet *r){
    pthread_mutex_lock(&m1);
        while ( nbre_produit_rampe == taille_rampe){
            printf("*******Production bloque : rampe pleine********\n");

            pthread_cond_wait(&peux_produire,&m1);
            printf("*******Reprise Production********\n");
        }
        copy_objet(&r[nbre_produit_rampe] ,o);
        nbre_produit_rampe++;
        pthread_cond_signal(&peux_consommer);
    pthread_mutex_unlock(&m1);
}




/***************** fonction thread du cerebro *************/
void *cerebro (void *arg){
    int *tab_arg;
    tab_arg = (void *)arg;
    printf("***************Demmarrage du cerebro*************\n");
    pthread_t prod;

    pthread_create(&prod,NULL, producteur_piece, (void*) tab_arg);

    pthread_join(prod,NULL);
    printf("fin cerebro\n");
    pthread_exit(NULL);

}


/*************** thread gérant la rotation de l'anneau ***********/
void *lanneau(void *arg){
    pthread_mutex_lock(&mutex_rotation);
    initialisation_anneau(ano);
    /*int i;
    for (i =0 ; i<16; i++){
        printf("%d ",ano[i].nature );
    }*/
    //pthread_mutex_unlock(&mutex_rotation);
    while (1){
        pthread_cond_wait(&peux_roter,&mutex_rotation);
        //pthread_mutex_wait(&mutex_rotation);
        rotation(ano);
        pthread_mutex_unlock(&mutex_rotation);
    }
}

void* robot1(void *arg){
    Objet memoire_composant[5];
    Objet memoire_pdt[5];
    int etat;
    int pointeur_pdt = 0;
    int pointeur_comp =0;
    int mode;
    //le robot regarde devant lui

    if ( regarde_devant(ano,r1) == REMPLI ){

        if (mode == normal ){
           etat = scan_robot1(ano[r1]);
        }
        else{
            etat = scan_robot1_degrade_mode(ano[r1]);
        }
        // le robot voici s'il peut prendre le produit devant lui
        if(etat == bon){
            // s'il y a de la place dans son espace de stockage il le prend
            if (pointeur_comp < 4 ){
                pthread_mutex_lock(&mutex_rotation);
                    copy_objet(&memoire_composant[pointeur_comp] , prendre_objet(ano, r1) );
                    pthread_mutex_lock(&mutex_sur_nbe_section);
                        nbe_section_occupe--;
                        pthread_cond_broadcast(&peux_deposer);
                    pthread_mutex_unlock(&mutex_rotation);
                pointeur_comp++;
                printf("Robot 1 prend Objet\n");
            }
        }
    }
    else{
        // s'il a des produits semi fini il les deposes
            if (pointeur_comp != 0){
                //depot sur anneau

                //mise à jour de la memoire
            }
    }
}
