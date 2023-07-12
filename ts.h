#ifndef TS_H
#define TS_H


#define taille 100

//table de symboles
typedef struct elt {
    char* nom;
    int type;
    int taille_tab;
    int isconst;
    struct elt* svt;
    float valeur ;
}elem;

elem* tess[taille];

void init();

int recherche (char* ,int* ,elem**);

int fhach (char* e);

void inserer(char* e1,int type, int taill , int valc );

// fonction affichage de TS 

void afficherTS();
void printHachTable();
void printList(elem* l);
char* switchType(int type);

//************************************************************


void doubleDeclaration(char *entite);
void dec (char * entite);
int returntype(char* entite);
void veriftailletab(char* tab , int taill);

void inser_val(char* antite , float val );
void test_retun_typ();

// table  mots clés
typedef struct
{ 
   int state; 
   char name[20];
   char type[20];
} et;
et tabs[40],tabm[40];

void initialisation();
void ins (char entite[], char code[],char type[],float val,int i, int y);
void rechercher (char entite[], char code[],char type[],float val,int y);
void afficher();
int nb_ligne_comment(char entite[]);
#endif //TS_H
