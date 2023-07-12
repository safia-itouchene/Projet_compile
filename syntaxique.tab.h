
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     commentaire = 258,
     vrg = 259,
     aff = 260,
     plus = 261,
     moin = 262,
     mult = 263,
     division = 264,
     par_ov = 265,
     par_fr = 266,
     accolade_fr = 267,
     aco_f = 268,
     aco_o = 269,
     accolade_ov = 270,
     dpts = 271,
     pts_vrg = 272,
     mc_if = 273,
     mc_else = 274,
     mc_for = 275,
     mc_while = 276,
     mc_or = 277,
     mc_and = 278,
     mc_not = 279,
     mc_var = 280,
     mc_code = 281,
     mc_struct = 282,
     mc_entier = 283,
     mc_reel = 284,
     mc_const = 285,
     entier = 286,
     reel = 287,
     idf = 288,
     G = 289,
     L = 290,
     GE = 291,
     LE = 292,
     NEQ = 293,
     EQ = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 30 "syntaxique.y"

        char* str;
        int  integer;
        float f;
        struct {
                char* res;
                 int type;
                float  val;
                }EXP;



/* Line 1676 of yacc.c  */
#line 104 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


