#include "capteur.h"
#include "anneau.h"
#include "robot.h"


int regarde_devant_capteur (anneau a , int position){
    if (a[position].nature == vide ){
        return vide;
    }
    else{
        return REMPLI ;
    }
}

void prendre_objet_capteur(anneau a, int position){
    Objet temp , objet_vide;
    message_capteur m;

    temp = a[position];
    initialisationObjet(&objet_vide,vide,0,0);
    a[position] = objet_vide;

    m.type = 1;
    m.pdt = temp;

    //ecriture dans la file de message
    //msg_snd()
}

int scan_capteur(Objet o){
    if (o.state == fini){
        return bon;
    }
    else{
        return pas_bon;
    }
}

anneau ano;
void * capteur (void *arg){
    while (1){
        int position_capteur = 5;

        if ( regarde_devant_capteur(ano , position_capteur ) == REMPLI){
             if(scan_capteur(ano[position_capteur]) == bon ){
                prendre_objet_capteur(ano, position_capteur);
             }
        }
    }
}
