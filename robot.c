#include "robot.h"

int operation(Objet *o, int numero_operation){
    (o->op_suivi[numero_operation-1])++;
    return 1;
}

// regarde si la case devant est vide ou rempli
int regarde_devant (anneau a , int position){
    if (a[position].nature == vide ){
        return vide;
    }
    else{
        return REMPLI ;
    }
}

Objet prendre_objet(anneau a, int position){
    Objet temp , objet_vide;
    temp = a[position];
    initialisationObjet(&objet_vide,vide,0,0);
    a[position] = objet_vide;
    return temp;
}

int deposer_objet(anneau a , int position, Objet o){
    a[position] = o;
    return 1;
}

int scan_robot1(Objet o){
    // si l'objet est un composant c1  on peut le prendre
    if ( (o.nature == composant) && (o.type == 1) ){
        return bon;
    }else{
        // sinon s'il s'agit d'un produit semi fini
        if ((o.nature == produit) && (o.state == semi_fini) ){
            // s'il s'agit d'un pdt2 ayant subit op2 et op4 on peut le prendre
             if ((o.op_suivi[1] == 1) && (o.op_suivi[3] == 1) && (o.type == 2)){
                return bon ;
             }
            //s'il s'agit d'un pd3 ayant subit juste op3  ou ayant subit op3 , op1, op5
            if ( ((o.op_suivi[2] == 1)&& (o.op_suivi[0] == 0) && (o.type == 3)) || ((o.op_suivi[2] == 1)&&(o.op_suivi[0] == 1) && (o.op_suivi[4] == 1) && (o.type == 3)) ){
                return bon;
            }
            // s'il s'agit d'un pd4 ayant subit op4 et op5
            if((o.op_suivi[3] == 1) && (o.op_suivi[4] == 1) && (o.type == 4)){
                return bon;
            }
        }
        else{
            return pas_bon;
        }
    }

}

int scan_robot2(Objet o){
    // si l'objet est un composant c2  on peut le prendre
    if ( (o.nature == composant) && (o.type == 2) ){
        return bon;
    }else{
         // sinon s'il s'agit d'un produit semi fini
        if ((o.nature == produit) && (o.state == semi_fini) ){
            // s'il s'agit d'un pdt1 ayant subit op1  on peut le prendre
             if ((o.op_suivi[0] == 1) && (o.type == 1) && (o.type == 1)){
                return bon ;
             }
        }
        else{
            return pas_bon;
        }
    }
}

int scan_robot3(Objet o){
    // si l'objet est un composant c3  on peut le prendre
    if ( (o.nature == composant) && (o.type == 3) ){
        return bon;
    }else{
         // sinon s'il s'agit d'un produit semi fini
        if ((o.nature == produit) && (o.state == semi_fini) ){
            // s'il s'agit d'un pdt1 ayant subit op1 , op2  on peut le prendre
             if ((o.op_suivi[0] == 1) && (o.op_suivi[1] == 1) && (o.type == 1)){
                return bon ;
             }
             // s'il s'agit d'un pdt3 ayant subit op3 , op1, op5 , op1  on peut le prendre
             if ((o.op_suivi[0] == 2) && (o.op_suivi[2] == 1)&& (o.op_suivi[4] == 1) && (o.type == 3)){
                return bon ;
             }
        }
        else{
            return pas_bon;
        }
    }

}

int scan_robot4(Objet o){
    // si l'objet est un composant c4  on peut le prendre
    if ( (o.nature == composant) && (o.type == 4) ){
        return bon;
    }
    else{
         // sinon s'il s'agit d'un produit semi fini
        if ((o.nature == produit) && (o.state == semi_fini) ){
            // s'il s'agit d'un pdt2 ayant subit  op2  on peut le prendre
             if ((o.op_suivi[1] == 1) && (o.type == 2)){
                return bon ;
             }
        }
        else{
            return pas_bon;
        }
    }
}

int scan_robot5(Objet o){
   // s'il s'agit d'un produit semi fini
    if ((o.nature == produit) && (o.state == semi_fini) ){
        // s'il s'agit d'un pdt1 ayant subit  op1 , op2 , op3 on peut le prendre
        if ((o.op_suivi[0] == 1) && (o.op_suivi[1] == 1) && (o.op_suivi[2] == 1) && (o.type == 1)){
                return bon ;
        }
        // s'il s'agit d'un pdt3 ayant subit  op3 , op1 on peut le prendre
        if ((o.op_suivi[0] == 1) && (o.op_suivi[2] == 1) && (o.type == 3)){
                return bon ;
        }
        else{
            return pas_bon;
        }
    }
    else{
        return pas_bon;
    }
}

int scan_robot6(Objet o){
   // s'il s'agit d'un produit semi fini
    if ((o.nature == produit) && (o.state == semi_fini) ){
        // s'il s'agit d'un pdt2 ayant subit  op1 , op2 , op4 on peut le prendre
        if ((o.op_suivi[0] == 1) && (o.op_suivi[3] == 1) && (o.op_suivi[1] == 1) && (o.type == 2)){
                return bon ;
        }
        // s'il s'agit d'un pdt4 ayant subit  op4 on peut le prendre
        if ((o.op_suivi[3] == 1) && (o.type == 4)){
                return bon ;
        }
        else{
            return pas_bon;
        }
    }else{
        return pas_bon;
    }
}


int  scan_robot1_degrade_mode(Objet o){
    // en degrade mode r1 fait op1 op2 op3 donc doit scanner coe les robots r1, r2, r3
    if ((scan_robot1(o)== bon ) || (scan_robot2(o) == bon) || (scan_robot3(o) == bon)  ){
        return bon;
    }
    else{
        return pas_bon;
    }
}

int scan_robot2_degrade_mode(Objet o){
    // le robot r2 fait op2 et op1, il doit scanner comme r2, et r1
    if ((scan_robot2(o)==bon) || (scan_robot1(o) == bon) ){
        return bon;
    }
    else{
        return pas_bon;
    }
}

int scan_robot3_degrade_mode(Objet o){
    // le robot r3 fait op3 op4 op5 , il doit scanner comme r3, r4 et r6
    if ((scan_robot3(o)==bon) || (scan_robot4(o) == bon) || (scan_robot6(o) == bon) ) {
        return bon;
    }
    else{
        return pas_bon;
    }
}

int scan_robot4_degrade_mode(Objet o){
    // le robot r4 fait op3 op4  , il doit scanner comme r3 et r4
    if ((scan_robot3(o)==bon) || (scan_robot4(o) == bon) ) {
        return bon;
    }
    else{
        return pas_bon;
    }
}


void update_etat_pdt(Objet *o){

    switch (o->type){
        case 1 : if ( (o->op_suivi[0] == 1) && (o->op_suivi[1] == 1) && (o->op_suivi[2] == 1) && (o->op_suivi[4] == 1) ){
                    o->state = fini;
                }
        break;
        case 2: if ( (o->op_suivi[1] == 1) && (o->op_suivi[3] == 1) && (o->op_suivi[0] == 1) && (o->op_suivi[5] == 1) ){
                    o->state = fini;
                }
        break;
        case 3:if ( (o->op_suivi[0] == 2) && (o->op_suivi[2] == 1) && (o->op_suivi[4] == 1) && (o->op_suivi[2] == 1) ) {
                    o->state = fini;
                }
        break;

        case 4:if ( (o->op_suivi[3] == 1) && (o->op_suivi[5] == 1) && (o->op_suivi[0] == 1)  ){
                    o->state = fini;
                }
        break ;
    }
}


