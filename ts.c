#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ts.h"
          
void init ()
{
    int i;
    for ( i = 0; i < taille ; i++)
    {
            tess[i]=NULL;
    }
}

/* la fonction de hashage*/
int fhach (char* e)
{
    int i=0, count=0;
    while (e[i]!='\0')
    {
        count+=e[i]*i*(10*(i+1));
        i++;
    }
    return (count%taille);
}

/* inserer les idfs dans la table des symboles*/
void inserer(char* e1,int type, int taill , int valc )
{  
    int index;
    elem* p;
    elem* adr;
    int b=recherche(e1,&index,&adr);
    if(b==0)
    p=malloc(sizeof(elem));
    p->nom=e1;
    p->type=type;
    p->taille_tab = taill; 
    p->isconst=valc; 
    p->valeur=0;
    if(tess[index]==NULL){
        p->svt=NULL;
        tess[index]=p;
        }else {p->svt =tess[index];
        tess[index]=p;
    }
}


/* fonction rechercher pour savoir si deja declare*/
int recherche(char* e1,int* index,elem** adr)
{
    elem* p;
    *index =fhach(e1);
    p=tess[*index];
    *adr=p; 
    if(p==NULL) return 0;
    
    while (p!=NULL && strcmp(p->nom,e1)!=0) 
    {
        p=p->svt;
        *adr=p;
    }
    if(p==NULL) return 0;
    return 1;
}

/* Afficher la table des idfs*/
void printHachTable(){
int i;

printf("----------------------------TABLE DES IDF-------------------------- \n");
printf("___________________________________________________________________\n ");
printf("   IDF      |  CodeEntite |    Type     |  taille_tab   | valeur  | \n");
printf("___________________________________________________________________ \n");


for ( i = 0; i <=taille; i++)
  {
    if (tess[i]!=NULL)
    { 
       printList(tess[i]);
    }
  }
}

void printList(elem* l){ 
	char str[15];
for ( l ; l!=NULL; l=l->svt)
    {  strcpy(str,l->nom); 
		printf("  %s   |",str);
		printf("  %s   |",l->isconst == 1?"CONST   ":"VARIABLE");
		printf("  %s  %d |",switchType(l->type),l->type);
		printf("  %d   |",l->taille_tab);
		printf("  %f \n",l->valeur);
    }
}


/* pour afficher les types*/
char* switchType(int type){

	switch (type)
	{
	case 1:
         return "INTEGER ";
		break;
	
		case 2:
         return "FLOAT   ";

		break;
		
	default:
		break;
	}
	return "NON INIT";
}


/* fonction Double declaration */
void doubleDeclaration(char *entite)
{
    int index;
    elem *adr;
    if(recherche(entite,&index,&adr))
    {
        yyerror("erreur semantique double declaration d'un idf \n");
    
    }
    
    
}

/* Fonction idf non declare */
void dec (char * entite)
{
    int index ;
    elem* adr;
    if (!recherche(entite,&index,&adr))
    {
        yyerror("\n\nerreur semantique idf non declarer");
     }
}

/*  fonction qui recupere le type */
int returntype(char* antite )
{  int index;
   elem *adr;
   int b = recherche(antite, &index, &adr);
   if(b==1) { 
      return adr->type;
   }
}
/* fonction qui verifie la taille du tableau si il ne depasse pas */
void veriftailletab(char* tab , int taill)
{
int index;
   elem *adr;
   int b = recherche(tab, &index, &adr);
    if(b==1) {

      if((taill < 0) || (taill > adr->taille_tab)) { yyerror("taille  du tableau  depasse la capacite"); }
   }
}

/* inserer la valeur dans la ts*/
void inser_val(char* antite , float val )
{
    int index;
   elem *adr;
   int b = recherche(antite, &index, &adr);
   if(b==1) { 
       adr->valeur = val;
   }
}

/* initialisation de la table des mots cles et de la table des separateurs*/
void initialisation()
{   int i;
     for (i=0;i<40;i++)
  {tabs[i].state=0;
    tabm[i].state=0;}
}

/* insertion des mots cles et des separateurs*/
void ins (char entite[], char code[],char type[],float val,int i, int y)
{
  switch (y)
 { 
   
   case 1:/*insertion dans la table des mots clés*/
       tabm[i].state=1;
       strcpy(tabm[i].name,entite);
       strcpy(tabm[i].type,code);
       break; 
    
   case 2:/*insertion dans la table des séparateurs*/
      tabs[i].state=1;
      strcpy(tabs[i].name,entite);
      strcpy(tabs[i].type,code);
      break;
 }

}


/* La fonction Rechercher permet de verifier  si l'entité existe dèja dans la table des symboles */
void rechercher (char entite[], char code[],char type[],float val,int y)	
{
int j,i;
switch(y) 
  {
   case 1:/*verifier la case dans la tables des mots clés */
       
       for (i=0;((i<40)&&(tabm[i].state==1))&&(strcmp(entite,tabm[i].name)!=0);i++); 
        if(i<40)
          ins(entite,code,type,val,i,1);
        else
          printf("entité existe déjà\n");
        break; 
    
   case 2:/*verifier la case dans la tables des séparateurs */
         for (i=0;((i<40)&&(tabs[i].state==1))&&(strcmp(entite,tabs[i].name)!=0);i++); 
        if(i<40)
         ins(entite,code,type,val,i,2);
        else
   	       printf("entité existe déjà\n");
        break;
  }
}

void afficher()
{int i;
 
printf("\n/***************Table des symboles mots cles*************/\n");

printf("_____________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________\n");
  
for(i=0;i<40;i++)
    if(tabm[i].state==1)
      { 
        printf("\t|%10s |%12s | \n",tabm[i].name, tabm[i].type);
               
      }

printf("\n/***************Table des symboles separateurs*************/\n");

printf("_____________________________\n");
printf("\t| NomEntite |  CodeEntite | \n");
printf("_____________________________\n");
  
for(i=0;i<40;i++)
    if(tabs[i].state==1)
      { 
        printf("\t|%10s |%12s | \n",tabs[i].name,tabs[i].type );
        
      }

}



