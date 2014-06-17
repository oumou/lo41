#include <stdio.h>
#include <stdlib.h>

#include "global.h"

#include "Objet.h"
#include "anneau.h"
#include "robot.h"
#include "cerebro.h"
#include "capteur.h"


//anneau ano;

int main()
{
    pthread_t  anno, conso,prod,ro1;
    int t[4];
    printf("************Usine*************** \n");
    printf("Nombre de produit à fabriquer\n");
    printf("          Prod1 : ");
    scanf("%d",&t[0]);
    printf("          Prod2 : ");
    scanf("%d",&t[1]);
    printf("          Prod3 : ");
    scanf("%d",&t[2]);
    printf("          Prod4 : ");
    scanf("%d",&t[3]);

    //initialisation_anneau(ano);


    if (pthread_create(&prod,NULL, producteur_piece, (void*) t) ){
        printf("Erreur lors du demarrage du producteur_composant\n");
        return -1;
    }

    /*if ( pthread_create(&cer,NULL, cerebro , (void*) t ) <0 ){
        printf("Erreur lors du demarrage du cerebro\n");
        return -1;
    }*/
    if ( pthread_create(&anno,NULL, lanneau , NULL) <0 ){
        printf("Erreur lors du demarrage du cerebro\n");
        return -1;
    }

    if  (pthread_create(&conso,NULL, consommateur_piece, NULL) <0 ){
        printf("erreur lors du lancement de la rampe\n");
        return -1;
    }

    if  (pthread_create(&ro1,NULL, robot1, NULL) <0 ){
        printf("erreur lors du lancement du robot\n");
        return -1;
    }


   // pthread_join(cer,NULL);
    pthread_join(anno,NULL);
    return 0;
}
