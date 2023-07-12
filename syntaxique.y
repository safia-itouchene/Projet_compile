%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "quadrupler.h"
#include "quadrupler.c"
#include "optimisation.h"
#include "optimisation.c"
#include "cod_obg.c"
#include "cod_obg.h"
#include"ts.h" 
/*Définitions en langage C*/
int i=0 ,j,a=0 ,compatibilite = 0, k=1 , valuetype = 0 , nb_ligne=1 ,Col=1 , nTemp=1;
int sauvtype,fin_pos ,sauv_debut_while ,sauv_deb_for ,else_pos; 
char tempC[12]="" , val[12]="";
char  *sauv_idf ,  *id;
typedef struct{ 
	 char*  nom_idf; 
     }tab_idf;
     tab_idf  tab[20];
	 
void insert_liste_idf(int code_type){
      while(sauv_var != NULL)
        {  
            id= depiler(&sauv_var);
            inserer(strdup(id),code_type, 0 , 2);
        }
}
%}
%union {
        char* str;
        int  integer;
        float f;
        struct {
                char* res;
                 int type;
                float  val;
                }EXP;
}

%token commentaire  vrg  aff  plus moin mult division   par_ov par_fr  accolade_fr  aco_f aco_o accolade_ov  dpts  pts_vrg
%token mc_if mc_else mc_for mc_while mc_or mc_and mc_not mc_var mc_code mc_struct  mc_entier mc_reel mc_const  
%token  <integer>entier <f>reel <str>idf 
%token G L  GE  LE  NEQ  EQ  

%left plus moin
%left mult division
%left mc_and
%left mc_or
%type<EXP> EXP_AR EXP CONDITION INIT

%%
S: idf  accolade_ov  COR_PRG accolade_fr     
     {printf("\n \n programme syntaxiquement correct ^_^ .\n");}
;
COR_PRG: mc_var accolade_ov LISTE_DEC accolade_fr mc_code accolade_ov MAIN accolade_fr
;
LISTE_DEC:DEC LISTE_DEC 
         |commentaire  LISTE_DEC 
         |
;
/******************** DECLARATION ********************/
DEC: DEC_CST
    |DEC_VAR
    |DEC_TAB
    |DEC_STRUCT
;
DEC_STRUCT: DEF_STRUCT
           |VAR_STRUCT
;
DEF_STRUCT : mc_struct accolade_ov COR_STRUCT accolade_fr idf pts_vrg
;
COR_STRUCT: LISTE_DEC_STR COR_STRUCT 
           |commentaire  COR_STRUCT 
           |   
;
LISTE_DEC_STR: DEC_VAR
;
VAR_STRUCT: mc_struct idf LISTE_IDF  pts_vrg
;
DEC_CST: mc_const AFF_CONST pts_vrg     
;
AFF_CONST:  idf aff entier
           {doubleDeclaration(strdup($1)); inserer(strdup($1),1,0,1); inser_val(strdup($1),$3);}
           | idf aff reel   
           {doubleDeclaration(strdup($1)); inserer(strdup($1),2,0,1); inser_val(strdup($1),$3);}    
;
DEC_VAR :TYPE_VAR  LISTE_IDF  pts_vrg 
;
LISTE_IDF: idf  vrg LISTE_IDF 
          {
            empiler_Str(&sauv_var,strdup($1)); doubleDeclaration(strdup($1));
            insert_liste_idf(sauvtype);
           } 
          |idf  
          {
            empiler_Str(&sauv_var,strdup($1)); doubleDeclaration(strdup($1)); 
            insert_liste_idf(sauvtype);
          } 
;
DEC_TAB: TYPE_VAR LISTE_TAB pts_vrg
;
LISTE_TAB: idf  aco_o entier aco_f vrg LISTE_TAB 
          {doubleDeclaration(strdup($1)); inserer(strdup($1), sauvtype , $3 ,2);}
          |idf  aco_o entier aco_f
          {doubleDeclaration(strdup($1)); inserer(strdup($1), sauvtype , $3 ,2);}
;
TYPE_VAR: mc_entier {  sauvtype = 1;}
         |mc_reel   {  sauvtype = 2;}
;
// MAIN  
MAIN :LISTE_INSTRUCTION
;
LISTE_INSTRUCTION:   INSTRUCTION  LISTE_INSTRUCTION
                  |  commentaire  LISTE_INSTRUCTION
                  |
;
INSTRUCTION: INSTRUCTION_AFFECTATION
            | LOOP_FOR
            | LOOP_WHAILE 
            | IF_ELSE
;
//AFFECTATION 
INSTRUCTION_AFFECTATION: PARTIE_GOUCHE aff EXP pts_vrg
                        { 
                          if(a != compatibilite){yyerror("\n\n type incompatible");}                   
                          compatibilite=0;  quadrupler (":=",$3.res,"",sauv_idf);
                          inser_val(sauv_idf,$3.val);  
                        }
;
PARTIE_GOUCHE: idf 
              {dec ($1); a = returntype($1);   sauv_idf=strdup($1);}
              |idf  aco_o entier aco_f
              {dec ($1); a = returntype($1); veriftailletab($1,$3); sauv_idf=strdup($1);}
;
// FOR 
LOOP_FOR:DEBUT_FOR  accolade_ov  LISTE_INSTRUCTION accolade_fr
         { 
           sauv_idf = depiler(&sauv_var); quadrupler("+",strdup(sauv_idf),"1",strdup(sauv_idf)); 
           sauv_deb_for = depiler_qc(&pileFOR); quadrupler("BR",ToSTR(sauv_deb_for),"",""); q[sauv_deb_for].op1= ToSTR(indq); 
         }
;
DEBUT_FOR:mc_for par_ov idf dpts INIT dpts entier dpts INIT par_fr
          { 
            dec($3); quadrupler("=",$5.res,"",$3); empiler_qc(&pileFOR,indq); quadrupler("BG","",$3,$9.res); empiler_Str(&sauv_var, $3);
          }
;
INIT : entier {$$.res = ToSTR($1);}
      | idf   { $$.res = strdup($1); dec($1);  if(returntype($1) != 1) yyerror("type incompatible"); }
;
//WHILE 
LOOP_WHAILE:DEBUT_WHILE accolade_ov LISTE_INSTRUCTION accolade_fr 
             {quadrupler("BR",ToSTR(sauv_debut_while),"",""); q[sauv_debut_while].op1= ToSTR(indq); }
;
DEBUT_WHILE: mc_while par_ov CONDITION par_fr
             {empiler_qc(&pile2,indq); sauv_debut_while= depiler_qc(&pile2);  quadrupler("BZ","",strdup($3.res),"");} 
;
//IF_ELSE 
IF_ELSE:A accolade_fr
       {indq--; fin_pos = depiler_qc(&pile1);}
       |A accolade_fr mc_else accolade_ov LISTE_INSTRUCTION accolade_fr
       {fin_pos = depiler_qc(&pile1); q[fin_pos].op1= ToSTR(indq);}
;
A: B LISTE_INSTRUCTION
    {else_pos = depiler_qc(&pile1); q[else_pos].op1= ToSTR(indq+ 1); empiler_qc(&pile1, indq); quadrupler("BR","","","");}
;
B:mc_if par_ov CONDITION par_fr accolade_ov
  {empiler_qc(&pile1, indq); quadrupler("BZ","",strdup($3.res),"");} 
;
//CONDITION
CONDITION:  EXP_AR EQ EXP_AR
          {  sprintf(tempC, "T%d",nTemp);
             nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
             createquadruplerCompare (2,$1.res,$3.res,$$.res);}  
          | EXP_AR NEQ EXP_AR
          {  sprintf(tempC, "T%d",nTemp);
             nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
             createquadruplerCompare (1,$1.res,$3.res,$$.res);}
          |EXP_AR L EXP_AR
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (3,$1.res,$3.res,$$.res);}
          |EXP_AR G EXP_AR 
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (4,$1.res,$3.res,$$.res);}
          |EXP_AR GE EXP_AR
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (5,$1.res,$3.res,$$.res);}
          |EXP_AR LE EXP_AR
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerCompare (6,$1.res,$3.res,$$.res);}
          |mc_not EXP_AR
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerLogic   (1,$2.res,NULL,$$.res);}
          |CONDITION mc_or CONDITION 
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerLogic   (2,$1.res,$3.res,$$.res);}
          |CONDITION mc_and CONDITION 
          {   sprintf(tempC, "T%d",nTemp);
              nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; 
              createquadruplerLogic   (3,$1.res,$3.res,$$.res);}
          |EXP_AR
;
//                    
EXP_AR: EXP {$$.res = $1.res; compatibilite=0;}
;
EXP: EXP plus EXP
    {sprintf(tempC, "T%d",nTemp);nTemp++;$$.res=strdup(tempC);tempC[0]='\0';quadrupler ("+",$1.res,$3.res,$$.res);}
    |EXP moin EXP
     {sprintf(tempC, "T%d",nTemp);nTemp++;$$.res=strdup(tempC);tempC[0]='\0';quadrupler ("-",$1.res,$3.res,$$.res);}
    |EXP mult EXP
    {sprintf(tempC, "T%d",nTemp);nTemp++;$$.res=strdup(tempC);tempC[0]='\0';quadrupler ("*",$1.res,$3.res,$$.res);}
    |EXP division EXP
    {
      if ($3.val==0){yyerror("\n\ndivision sur 0") ;}
      sprintf(tempC, "T%d",nTemp);nTemp++;$$.res=strdup(tempC);tempC[0]='\0'; quadrupler ("/",$1.res,$3.res,$$.res);
    }
    |par_ov EXP par_fr
     {$$.type=$2.type; $$.res=$2.res;}
    |idf 
     { dec ($1);        
      if(compatibilite == 0) {compatibilite = returntype(strdup($1)) ;  } 
      else { 
            if(compatibilite != returntype(strdup($1))) { yyerror("\n\ntype incompatible") ;}
           }  
         $$.res=strdup($1);      $$.val=1;                
      }
    |entier
     {    
       if(compatibilite == 0) {compatibilite = 1; }
       else{ 
             if (compatibilite != 1 ){ yyerror("\n\ntype incompatible") ;}
           }     
            sprintf(val, "%d",$1); $$.res=strdup(val); $$.val=$1; 
     }
    |reel
      {  
        if(compatibilite == 0) {compatibilite = 2;} 
        else  { 
               if (compatibilite != 2 ){ yyerror("\n\ntype incompatible") ;}
              }
             sprintf(val, "%f",$1); $$.res=strdup(val);  $$.val=$1;    
      }
;

%%
/*Redéfinitions des fonctions prédéfinies*/
yyerror(char*msg)           
 {
	printf(" %s a la ligne %d et a la colonne %d \n",msg, nb_ligne, Col);
	exit (0);
 }
main()
{
init();
yyparse();

printf("\n------------------LES quadruplerRUPLETS AVANT OPTIMISATION ----------------------\n");
afficherquadrupler();

optimisation();

printf("\n------------------LES quadruplerRUPLETS APRES OPTIMISATION----------------------\n");
afficherquadrupler();

//code assembleur
assembler();

//table des mots clés et séparateurs
afficher();    
printf("\n \n");

//la table des IDF 
printHachTable();
printf("\n \n");

}
yywrap()
{}
