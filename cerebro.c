#include "cerebro.h"
#include "global.h"
#include "anneau.h"


void produire_composant (int nbre_pdt1 , int nbre_pdt2 , int nbre_pdt3 ,int nbre_pdt4, Objet *r){
    int nbre_c1 = 0;
    int nbre_c2 = 0;
    int nbre_c3 = 0;
    int nbre_c4 = 0;
    char s[100];
    //printf("%d,%d,%d,%d\n",nbre_pdt1,nbre_pdt2,nbre_pdt3,nbre_pdt4);
    //int total = nbre_pdt1;
    srand(time(NULL));

    while ( (nbre_c1 < 3 *nbre_pdt1 ) || (nbre_c2 < 3 *nbre_pdt2) || (nbre_c1 < 2 *nbre_pdt3)  || (nbre_c1 < nbre_pdt4)  ){

        Objet comp;
        int c;

        c = (rand() % 4 + 1);
        switch(c)
        {
            case 1 : if (nbre_c1 < 3 *nbre_pdt1){
                         initialisationObjet(&comp,composant,1,0);
                         deposer_objet_rampe(comp, r);
                         nbre_c1++;
                         sprintf(s," Nbre de c1 produit = %d",nbre_c1);
                         //printf("%s\n",s);
                         }

                break;
            case 2 :if (nbre_c2 < 3 *nbre_pdt2){
                         initialisationObjet(&comp,composant,2,0);


                         deposer_objet_rampe(comp, r);


                         nbre_c2++;
                         sprintf(s," Nbre de c2 produit = %d",nbre_c2);
                         //printf("%s\n",s);
                         }
                break;
             case 3 :if (nbre_c3 < nbre_pdt3){
                         initialisationObjet(&comp,composant,3,0);
                         deposer_objet_rampe(comp, r);
                         nbre_c3++;
                         sprintf(s," Nbre de c3 produit = %d",nbre_c3);
                         //printf("%s\n",s);
                         }
                break;
             case 4 :if (nbre_c4 < 2 *nbre_pdt4){
                         initialisationObjet(&comp,composant,4,0);
                         deposer_objet_rampe(comp, r);
                         nbre_c4++;
                         sprintf(s," Nbre de c4 produit = %d",nbre_c4);
                         //printf("%s\n",s);
                         }
                break;
        }
        //printf("piece de type %d deposer dans rampe\n",c);
    }

}








