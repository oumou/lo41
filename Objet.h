#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

/* structure representant les objets mamipulés dans la chaine de montage
    elle est générique, va permetttre de representer un produit et son état(fini - sémi fini
    ou un composant*/


#define vide 999 // les objets seront sur l'anneau qui est un tableau d'objet. un objet vide indique une case vide
#define composant 0
#define produit 1
#define fini 1
#define semi_fini 0

typedef struct{
    int nature; // produit  ou composant ou vide
    int type; // type du produit ou du composant
    int state; // etat du produit
    int op_suivi[5]; // Les operations déja effectuée sur le prosuit
} Objet;


// les fonctions liées aux objets;

int getNature(Objet o);
int getType(Objet o);
int getState(Objet o);

void setNature(Objet *o, int n);
void setType(Objet *o, int n);
void setState(Objet *o, int n);

// fonction permettant d'initialiser un objet
void initialisationObjet(Objet *o,int n, int t, int s);
//fonction determinant si une operation a deja été effectuée sur un produit
int  operation_suivi(Objet *o, int operation);
//fonction realisant une operation sur un produit
void  operation_realise(Objet *o, int operation);
//fonction verifiant si un produit  fini ou pas en fonction des operation effectué
int etat_produit(Objet *o);

// copier un objet
void copy_objet(Objet *o , Objet b);
void message(int i,char *s);
#endif // OBJET_H_INCLUDED
