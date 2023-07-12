#ifndef quadrupler_H
#define quadrupler_H

// la taille de la table des quadruplerruplets
#define t 100

//la structure d'un element de la table 
typedef struct 
{
    char*opr;
    char* op1;
    char* op2;
    char* res;
}quadruplerruplet;

// pile liste variable 
typedef struct element_pile{
	char *donnee;
	struct element_pile *prc;
}pile;
pile *sauv_var;

// pile update  qc position 
typedef struct element_pile_Qc{
	int donnee;
	struct element_pile_Qc *prc;
}pileQc;

pileQc *pile1;
pileQc *pile2;
pileQc *pileFOR;

//declaration de la table 
quadruplerruplet q[t];

//signature des fonctions de qud.c
void quadrupler(char*,char*,char*,char*);
void afficherquadrupler();
void createquadruplerCompare(int type, char *cond1, char *cond2, char *res);
char* ToSTR(int i);
void empiler_qc(pileQc **p, int pos);
int depiler_qc(pileQc **p);
#endif //quadrupler_H

