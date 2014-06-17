#include "anneau.h"
#include "stdio.h"
#include "unistd.h"
#include "Objet.h"
#include "robot.h"

void initialisation_anneau(anneau a){
    int i;
    for (i =0 ; i<16; i++){
        a[i].nature = vide;
    }
}
void rotation (anneau a){
    int i;
    Objet temp;
    copy_objet(&temp ,a[16] );
    for (i = 16 ; i>=1; i--)
        copy_objet(&a[i] , a[i-1]);
    //a[0] = temp;
    copy_objet(&a[0],temp );
    printf("Rotation....\n");
    usleep(2000);
    sleep(2);

}

// cette fonction sera utilisée par le thread consommateur de piece;
int deposer_objet_anneau(anneau a , int position, Objet o){
    copy_objet(&a[position] , o);
    return 1;
}
// fonction permettant de retirer un objet de la rampe
// La rampe fonction sous forme FIFO
Objet consommateur_rampe(Objet *r,int *nbre_piece){
    Objet temp = r[0];
    int j ;
    for (j=0; j<*nbre_piece-1; j++)
        copy_objet(&r[j] ,r[j+1]);
    (*nbre_piece)--;
    return temp;
}
int regarde_devant_conso(anneau a , int position){
    if (a[position].nature == vide){
        return vide;
    }else
    {
        return REMPLI;
    }
}

