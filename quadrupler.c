#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "quadrupler.h"

int indq=0;

//structure d'un quadruplerruplet
void quadrupler (char* o,char*o1,char*o2,char*r)
{   // Opération
    q[indq].opr=o; 	
	// Opérande 1
    q[indq].op1=o1; 
	// Opérande 2
    q[indq].op2=o2;
	// Resultat
    q[indq].res=r;  
    indq++;
}

//afficher les quadruplerruplets
void afficherquadrupler()
{
    int i;
    for ( i = 0; i < indq; i++)
    {
        printf("%d-(%s ,%s ,%s ,%s )\n",i,q[i].opr,q[i].op1,q[i].op2,q[i].res);
    }
    
}

// convertir un entier en chaîne de caractères
char* ToSTR(int i){
	char s[15];
	sprintf(s,"%d",i);
	return strdup(s);
}

//creation d'un quadruplerruplet de comparaison
void createquadruplerCompare(int type, char *cond1, char *cond2, char *res){
	char *TypeBR;
	switch(type){
		case 1 :{//1==> "!="
			TypeBR=strdup("BNE");
		}
		break;
		case 2 :{//2==> "==" 
			TypeBR=strdup("BE");
		}
		break;
		case 3 :{//3==> "<" 
			TypeBR=strdup("BL");
		}
		break;
		case 4 :{//4==> ">"  
			TypeBR=strdup("BG");
		}
		break;
		case 5 :{//5==>  ">=" 
			TypeBR=strdup("BGE");
		}
		break;
		case 6 :{//6==> "<=" 
			TypeBR=strdup("BLE");
		}
		break;
	}
	quadrupler(TypeBR,ToSTR(indq+3),cond1,cond2);
	quadrupler("=","1","",res);
	quadrupler("BR",ToSTR(indq+2),"","");
	quadrupler("=","0","",res);
}

//creation d'un quadruplerruplet logique
void createquadruplerLogic(int type, char *cond1, char *cond2, char *res){
	switch(type){
		case 1 :{//1==> not
			quadrupler("BNZ",ToSTR(indq+3),cond1,"");
			quadrupler("=","1","",res);
			quadrupler("BR",ToSTR(indq+2),"","");
			quadrupler("=","0","",res);
		}
		break;
		case 2 :{//2==> or
			quadrupler("BNZ",ToSTR(indq+4),cond1,"");
			quadrupler("BNZ",ToSTR(indq+3),cond2,"");
			quadrupler("=","0","",res);
			quadrupler("BR",ToSTR(indq+2),"","");
			quadrupler("=","1","",res);
		}
		break;
		case 3 :{//3==> and
			quadrupler("BZ",ToSTR(indq+4),cond1,"");
			quadrupler("BZ",ToSTR(indq+3),cond2,"");
			quadrupler("=","1","",res);
			quadrupler("BR",ToSTR(indq+2),"","");
			quadrupler("=","0","",res);
		}
		break;
	}
}  

// Empiler une chaîne de caractères dans la pile
void empiler_Str(pile **p,char *donne){

	pile *new;

	new=(pile*)malloc(sizeof(pile));
	new->donnee=strdup(donne);

	//mise à jour chainage
	new->prc=*p;
	*p=new;
}

//depiler un caractere
char* depiler(pile**p){
	char *res;
	pile *H;
	H=*p;
	res=strdup(H->donnee);
	*p=H->prc;
	free(H);
	return res;
}


// empiler quadruplerruplet
void empiler_qc(pileQc **p, int pos){
     pileQc *new;
	 new=(pileQc*)malloc(sizeof(pileQc));
	  new->donnee = pos;

	//mise à jour chainage
	new->prc=*p;
	*p=new;
}

// depiler quadruplerruplet
int depiler_qc(pileQc **p){
	int position;
	pileQc *H;
	H=*p;
	position = H->donnee;
	*p= H->prc;
	free(H);
	return position;
}
