#include "Objet.h"
#include <stdio.h>
#include <stdlib.h>
#define COL 10
int getNature(Objet o){
    return o.nature;
}
int getType(Objet o){
    return o.type;
}
int getState(Objet o){
    return o.state;
}

void setNature(Objet *o, int n){
    o->nature = n;
}
void setType(Objet *o, int n){
    o->type = n;
}
void setState(Objet *o, int n){
    o->state = n;
}
void initialisationObjet(Objet *o,int n, int t, int s){
    int i;
    setNature(o,n);
    setType(o,t);
    setState(o,s);
    if (t == produit){
        for ( i=0; i<5 ; i++)
            o->op_suivi[i]=0;
    }
}
int  operation_suivi(Objet *o, int operation){
    return ((o->op_suivi[operation-1] == 1)?1:0 );
}
void  operation_realise(Objet *o, int operation){
    o->op_suivi[operation-1] = 1;
}
void copy_objet(Objet *o , Objet b){
    int i;
    setNature(o,b.nature);
    setType(o,b.type);
    setState(o,b.state);
    for ( i=0; i<5 ; i++)
            o->op_suivi[i]= b.op_suivi[i];

}
void message(int i,char *s)
{
    int  j;
    int nbr = (i-1)*COL;
    for(j=0;j<nbr;j++)putchar(' ');
    printf("%s\n",s);
    fflush(stdout);
}
