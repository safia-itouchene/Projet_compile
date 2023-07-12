%{  
/*definition en language C */ 
#include <stdio.h> 
#include<string.h>  
#include "syntaxique.tab.h"
#include "ts.h"
#include "ts.c"
extern  nb_ligne;
extern Col;
extern YYSTYPE yylval;
char val_s_par[10]="";
char b[10]="";
char e[]="(";
int i;
int j ;
%}
/*Les définitions des expressions régulière*/
%option noyywrap
chiffre [0-9]
idf  ([a-zA-Z][a-z0-9]*)
chaine_commentaire (%%[^\n]*)
entier (\([+-]{chiffre}{chiffre}*\))|{chiffre}*
reel (\([+-]{chiffre}+\.{chiffre}*\)|{chiffre}+\.{chiffre}*)
space ("\t"|" ")+
saut "\n"+

%%
VAR                        {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);return mc_var; }
CODE                       {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext); return mc_code;}
STRUCT                     {rechercher(yytext,"Mot cle",0,0, 1);  Col= Col + strlen(yytext);return mc_struct;}
INTEGER                    {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);yylval.str=strdup("INTEGER"); return mc_entier;}
FLOAT                      {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);yylval.str=strdup("FLOAT"); return mc_reel;}
CONST                      {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);yylval.str=strdup("CONST");return mc_const;}
FOR                        {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);return mc_for;}
WHILE                      {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);return mc_while; }
IF                         {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);return mc_if;}
ELSE                       {rechercher(yytext,"Mot cle",0,0, 1); Col= Col + strlen(yytext);return mc_else;}
"!"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext); yylval.str=strdup(yytext);return mc_not;}
"+"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext); yylval.str=strdup(yytext);return plus;}
"-"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext); yylval.str=strdup(yytext);return moin;}
"*"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext); yylval.str=strdup(yytext);return mult;}
"/"                        {rechercher(yytext,"Separateurs",0,0,2); Col= Col + strlen(yytext);yylval.str=strdup(yytext);return division;}
"&&"                       {rechercher(yytext,"Separateurs",0,0,2); Col= Col + strlen(yytext);yylval.str=strdup(yytext);return mc_and;}
"{"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext); yylval.str=strdup(yytext);return accolade_ov;}
"}"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext); yylval.str=strdup(yytext);return accolade_fr;}
"||"                       {rechercher(yytext,"Separateurs",0,0,2); Col= Col + strlen(yytext);return mc_or;}
";"                        {rechercher(yytext,"Separateurs",0,0,2); Col= Col + strlen(yytext);return pts_vrg; }
"<"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return  G;}
">"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return  L;}
"<="                       {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return GE;}
">="                       {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return LE;}
"=="                       {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return EQ;}
"!="                       {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return NEQ;}
":"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return dpts;}
"("                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return par_ov;}
")"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return par_fr;}
"["                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return aco_o;}
"]"                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return aco_f;}
","                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return vrg;}
"="                        {rechercher(yytext,"Separateurs",0,0,2);Col= Col + strlen(yytext);return aff;}

{idf}        {if (yyleng <=8){
					printf(" %s  ",yytext); Col =Col+yyleng;  
					yylval.str=strdup(yytext);  
					return idf ;
			}else{
					Col =Col+yyleng; 
					printf("\nERREUR  a la ligne :%d  et colonne :%d  IDF %s est tres long ...\n",nb_ligne,Col, yytext);
				}}

{entier}     { printf(" %s  ",yytext); Col =Col+yyleng;  
			   if( strncmp(yytext,e,1) == 0){
					j=0;
					for(i=1; i<(strlen(yytext)-1);i++){  
						val_s_par[j]=yytext[i];         
						j++;
					}  
					if( abs(atoi(val_s_par)) > 32767 ) {
						printf("%s erreur \n",yytext); }
					else{   
						yylval.integer=atoi(val_s_par);   
						return entier ;
					}
			}else{
					if( abs(atoi(yytext)) > 32767 ) {
						printf("%s erreur \n",yytext); }
                    else{    
                        yylval.integer=atoi(yytext);  
						return entier;
                 } }
}

{reel}  {printf(" %s  ",yytext); Col =Col+yyleng;  yylval.f=atof(yytext);
         j=0;
         if( strncmp(yytext,e,1)==0){ 
	     for(i=1;i<(strlen(yytext)-1);i++){
		      b[j]=yytext[i];
		      j++;
	         }   
			 j=0;
		   yylval.f=atof(b);
		  } else{  

                  yylval.f=atof(yytext);
		  } 
          return reel ;
 }
{chaine_commentaire} {Col= Col + strlen(yytext); } 
{space} {Col =Col+yyleng;}
{saut}  {Col=1; nb_ligne=nb_ligne+yyleng;}

. printf ("\nEntite lexicale non reconnue a ligne %d a la Colonne %d ... \n", nb_ligne, Col);
