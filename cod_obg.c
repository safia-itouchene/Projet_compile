#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quadrupler.h"
#include "ts.h"

/***********************************Generation du code machine************************************************/
void assembler(){
   
	int i, v = 0, type; 
	char c[12] = "";
	int ascii = 0;
	int in = 0;

	typedef struct e{
		char *ind;
	} e;
	e tab[100];

	// Creation du fichier
	FILE *fp;
	fp = fopen("code_obg.asm", "a");
	if (fp == NULL){
		printf("Une erreur lors de la creation du fichier !");
	}

	fprintf(fp, "DATA SEGMENT \n");
	elem *p;
	for (i = 0; i < taille; i++){
		p = tess[i];
		while (p != NULL){
			type = p->type;
			switch (type){
				case 1: // INTEGER
					if (p->taille_tab == 0)
						fprintf(fp, "%s DW ?\n", p->nom); // cas variable simple
					else
						fprintf(fp, "%s DW %d dup (?) \n", p->nom, p->taille_tab); // cas tableau d'INTEGER
				break;

				case 2: // FLOAT
					if (p->taille_tab == 0)
						fprintf(fp, "%s DD ?\n", p->nom); // cas variable simple
					else
						fprintf(fp, "%s DD dup(?)\n", p->nom); // cas tableau d'INTEGER
				break;

				default:
				break;}
			p = p->svt;
		}
	}
	fprintf(fp, "temp DW 100 dup (?) \n");
	fprintf(fp, "DATA ENDS\n");
	fprintf(fp, "\n");
	fprintf(fp, "CODE SEGEMENT\n");
	fprintf(fp, "ASSUME CS:CODE, DS:DATA\n");
	fprintf(fp, "MAIN :\n");
	fprintf(fp, "MOV AX,DATA\n");
	fprintf(fp, "MOV DS,AX\n\n");

	for (i = 0; i < indq; i++){ // parcourir les quadruplerruplets
		for (v = 0; v < in; v++){
			sprintf(c, "%d", i);
			if (strcmp(c, tab[v].ind) == 0) fprintf(fp, "etiquette%s:", c);
			c[0] = '\0';
		}

    // Operation d'addition
    if (strcmp(q[i].opr, "+") == 0){
		
      if ((q[i].op1[0] == 'T') && (q[i].op2[0] == 'T')){  // les deux operandes sont des variables temporaires
			fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "ADD AX,t[%c]\n ", q[i].op2[1]);
			if (q[i].res[0] == 'T'){ // si le resultat est une variable temporaire
				fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV t[SI],AX \n");
			}else{ 
				fprintf(fp, "MOV %s,AX \n", q[i].res);}
      }else{ // une des deux operandes ou aucune est une variable temporaire
			if (q[i].op1[0] == 'T'){ // Operande 1 est une variable temporaire
				fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "ADD AX, %s\n", q[i].op2);
				if (q[i].res[0] == 'T'){ // le resultat est une variable temporaire
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else if (q[i].op2[0] == 'T'){ // Operande 2 est une variable temporaire
				fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "ADD AX, %s\n", q[i].op1);
				if (q[i].res[0] == 'T'){ // le resultat est une variable temporaire
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else{ // aucune des operandes n'est une variable temporaire
				fprintf(fp, "MOV AX, %s\n", q[i].op1);
				fprintf(fp, "ADD AX, %s\n", q[i].op2);
				if (q[i].res[0] == 'T'){ // le resultat est une variable temporaire
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}
		}
    }

    // Operation de soustraction
    if (strcmp(q[i].opr, "-") == 0){
		if ((q[i].op1[0] == 'T') && (q[i].op2[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "SUB AX,t[%c] \n", q[i].op2[1]);
			if (q[i].res[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV t[SI],AX \n");
			}else{
				fprintf(fp, "MOV %s,AX \n", q[i].res);}
		}else{
			if (q[i].op1[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "SUB AX, %s\n", q[i].op2);
				if (q[i].res[0] == 'T'){
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else if (q[i].op2[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "SUB AX, %s\n", q[i].op1);
				if (q[i].res[0] == 'T') {
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else{
					fprintf(fp, "MOV AX, %s\n", q[i].op1);
					fprintf(fp, "SUB AX, %s\n", q[i].op2);
					if (q[i].res[0] == 'T'){
						fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
						fprintf(fp, "ADD SI,SI\n");
						fprintf(fp, "MOV t[SI],AX \n");
					}else{
						fprintf(fp, "MOV %s,AX \n", q[i].res);}
				}
			}
		}

	// operation de multiplication
    if (strcmp(q[i].opr, "*") == 0){
		if ((q[i].op1[0] == 'T') && (q[i].op2[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "MUL AX,t[%c] \n", q[i].op2[1]);
			if (q[i].res[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV t[SI],AX \n");
			}else{
				fprintf(fp, "MOV %s,AX \n", q[i].res);}
		}else{
			if (q[i].op1[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "MUL AX, %s\n", q[i].op2);
				if (q[i].res[0] == 'T'){
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else if (q[i].op2[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "MUL AX, %s\n", q[i].op1);
				if (q[i].res[0] == 'T'){
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else{
				fprintf(fp, "MOV AX, %s\n", q[i].op1);
				fprintf(fp, "MUL AX, %s\n", q[i].op2);
				if (q[i].res[0] == 'T'){
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}
		}
    }

    // Operation de division
    if (strcmp(q[i].opr, "/") == 0){
		if ((q[i].op1[0] == 'T') && (q[i].op2[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "DIV AX,t[%c] \n", q[i].op2[1]);
			if (q[i].res[0] == 'T') {
				fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV t[SI],AX \n");
			}else{
				fprintf(fp, "MOV %s,AX \n", q[i].res);}
		}else{
			if (q[i].op1[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "DIV AX, %s\n", q[i].op2);
				if (q[i].res[0] == 'T'){
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
			}else if (q[i].op2[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV AX, t[SI]\n");
				fprintf(fp, "DIV AX, %s\n", q[i].op1);
				if (q[i].res[0] == 'T'){
					fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
					fprintf(fp, "ADD SI,SI\n");
					fprintf(fp, "MOV t[SI],AX \n");
				}else{
					fprintf(fp, "MOV %s,AX \n", q[i].res);}
        }else{
			fprintf(fp, "MOV AX, %s\n", q[i].op1);
			fprintf(fp, "DIV AX, %s\n", q[i].op2);
			if (q[i].res[0] == 'T'){
				fprintf(fp, "MOV SI,%c\n", q[i].res[1]);
				fprintf(fp, "ADD SI,SI\n");
				fprintf(fp, "MOV t[SI],AX \n");
			}else{
            fprintf(fp, "MOV %s,AX \n", q[i].res);}
        }
      }
    }
	
    // Operation d'egalite
    if (strcmp(q[i].opr, "=") == 0){
		if (q[i].res[0] == 'T'){
			fprintf(fp, "MOV t[%c],%s  \n", q[i].res[1], q[i].op1);
		}else{
        fprintf(fp, "MOV %s,%s \n", q[i].res, q[i].op1);}
    }

    // Operation d'affectation
    if (strcmp(q[i].opr, ":=") == 0){
		if (q[i].op1[0] = 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op1[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX,t[SI] \n");
			fprintf(fp, "MOV %s,AX \n", q[i].res);
		}else{
			fprintf(fp, "MOV AX,%s \n", q[i].op1);
			fprintf(fp, "MOV %s,AX \n", q[i].res);
		}
    }

//*****************************************************************************************************************************************
    
	//---    BG  ----
    if (strcmp(q[i].opr, "BG") == 0){

      tab[in].ind = q[i].op1;
      in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){ // operande2 est un temporaire et resultat est un temporaire
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JG etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){ // operande 2 est un temporaire
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JG etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){ // operande2 est une variable  et le resutat est un temporaire
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JG etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){ //Operande 2 est une variable 
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JG etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){ // operande 2 est un chiffre et le resutat temporaire
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JG etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){ //operande2 est un chiffre
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JG etiquette %s\n", q[i].op1);
			}
		}
    }

    //---    BNE  ----
    if (strcmp(q[i].opr, "BNE") == 0){
		
		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JNE etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JNE etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JNE etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JNE etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JNE etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JNE etiquette %s\n", q[i].op1);
			}
		}
    }
    //---  BE ----
    if (strcmp(q[i].opr, "BE") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JE etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JE etiquette %s\n", q[i].op1);
      }else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JE etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JE etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JE etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JE etiquette %s\n", q[i].op1);
			}
		}
    }
    // --- BL----

    if (strcmp(q[i].opr, "BL") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JB etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JB etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JB etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JB etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JB etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JB etiquette %s\n", q[i].op1);
			}
		}
    }
    //--- BGE  ----
    if (strcmp(q[i].opr, "BGE") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JAE etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JAE etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JAE etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JAE etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JAE etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JAE etiquette %s\n", q[i].op1);
			}
		}
    }
    //--- BLE ----
    if (strcmp(q[i].opr, "BLE") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JBE etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JBE etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JBE etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JBE etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JBE etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JBE etiquette %s\n", q[i].op1);
			}
		}
	}
    // ---   BR ---
    if (strcmp(q[i].opr, "BR") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JMP etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JMP etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JMP etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JMP etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JMP etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JMP etiquette %s\n", q[i].op1);
			}
		}
    }
    //----  BZ ---
    if (strcmp(q[i].opr, "BZ") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JZ etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JZ etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JZ etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JZ etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JZ etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JZ etiquette %s\n", q[i].op1);
			}
		}
    }
    // -----  BNZ  ---
    if (strcmp(q[i].opr, "BNZ") == 0){

		tab[in].ind = q[i].op1;
		in = in + 1;

		if ((q[i].op2[0] == 'T') && (q[i].res[0] == 'T')){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI] \n");
			fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
			fprintf(fp, "JNZ etiquette %s\n", q[i].op1);
		}else if (q[i].op2[0] == 'T'){
			fprintf(fp, "MOV SI,%c\n", q[i].op2[1]);
			fprintf(fp, "ADD SI,SI\n");
			fprintf(fp, "MOV AX, t[SI]\n");
			fprintf(fp, "CMP AX,%s \n", q[i].res);
			fprintf(fp, "JNZ etiquette %s\n", q[i].op1);
		}else{
			ascii = ascii + q[i].op2[0];
			if ((65 <= ascii <= 90) && (q[i].res[0] == 'T')){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,t[%c] \n", q[i].res[1]);
				fprintf(fp, "JNZ etiquette %s\n", q[i].op1);
			}else if (65 <= ascii <= 90){
				fprintf(fp, "MOV AX, %s\n", q[i].op2);
				fprintf(fp, "CMP AX,%s \n", q[i].res);
				fprintf(fp, "JNZ etiquette %s\n", q[i].op1);
			}else if ((48 <= ascii <= 57) && (q[i].res[0] == 'T')){
				fprintf(fp, "CMP %s,t[%c] \n", q[i].op2, q[i].res[1]);
				fprintf(fp, "JNZ etiquette %s\n", q[i].op1);
			}else if (48 <= ascii <= 57){
				fprintf(fp, "CMP %s,%s \n", q[i].op2, q[i].res);
				fprintf(fp, "JNZ etiquette %s\n", q[i].op1);
			}
		}
    }
 }
  fprintf(fp, "FIN :\n");
  fprintf(fp, "MOV AH,4CH\n");
  fprintf(fp, "INT 21h\n");
  fprintf(fp, "CODE ENDS\n");
  fprintf(fp, "END MAIN\n");

  fclose(fp);
}
