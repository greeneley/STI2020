%{
/*****************************************************************************
 *                DigCC: a minimal C compiler for DigMIPS                    *
 ***************************************************************************** 
 *                                                                           *
 * Copyright (c) 2012 Christophe Alias                                       *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by the     *
 * Free Software Foundation; either version 2 of the License, or (at your    * 
 * option) any later version.                                                *
 *                                                                           *
 * This program is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General  *
 * Public License for more details.                                          *
 *                                                                           *
 * You should have received a copy of the GNU General Public License along   *
 * with this program; if not, write to the Free Software Foundation, Inc.,   *
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                 *
 *                                                                           *
 * Written by Christophe Alias, Christophe.Alias@ens-lyon.fr                 *
 *                                                                           *
 *****************************************************************************/

#include <string.h>	/* for strcmp, strdup & friends */
#include <stdio.h>	/* for strcmp, strdup & friends */
#include <stdlib.h>	/* for atoi() */

#include "Attributes.h"
#include "Type.h"
#include "parser.h"	/* (TK_) symbols from parser.y */

extern int line_number;	/* defined in parser.ypp */

%}

%x comment
%x asm

%%
[ \t\r]			break;		/* ignore white space */
"\n" 			++line_number; 

"("                     return TK_LPAR;
")"                     return TK_RPAR;
","                     return TK_COMMA;
";"                     return TK_SEMI;
"{"                     return TK_LACC;
"}"                     return TK_RACC; 

"true"                  return TK_TRUE;
"false"                 return TK_FALSE;
">"                     return TK_GREATER;
">="                    return TK_GREATER_EQ;
"<"                     return TK_LOWER;
"<="                    return TK_LOWER_EQ;
"=="                    return TK_EQUAL;
"!="                    return TK_NEQUAL;

"+"                     return TK_PLUS;
"-"                     return TK_MINUS;
"*"                     return TK_MUL;
"/"                     return TK_DIV;
"%"                     return TK_MOD;
"++"                    return TK_PLUSPLUS;

"["                     return TK_LBRAC;
"]"                     return TK_RBRAC;
"&"                     return TK_REF;
"."                     return TK_DOT;

"int"                   return TK_INT_TYPE;
"char"                  return TK_CHAR_TYPE;
"void"                  return TK_VOID_TYPE;
"struct"                return TK_STRUCT;
"typedef"               return TK_TYPEDEF;
"sizeof"                return TK_SIZEOF;


"="                     return TK_ASSIGN; 

"if"                    return TK_IF;
"else"                  return TK_ELSE;
"while"                 return TK_WHILE;
"for"                   return TK_FOR;
"return"                return TK_RETURN;

"__asm {"               BEGIN(asm);
<asm>[ \t]*"}"          BEGIN(INITIAL);
<asm>[^\n]*             {
                          yylval.id_string = strdup(yytext);
                          return TK_ASM;
                        }
<asm>\n                 line_number++;

"//"                    BEGIN(comment);   //
<comment>[^\n]          break;            //
<comment>\n             {                 // Comments handling
                          BEGIN(INITIAL); //
                          line_number++;  //
                        }                 //

[0-9]+                  { 
                          yylval.integer = atoi(yytext); 
                          return TK_NUM; 
                        }

\"[^\n]*\"              {
                          yylval.id_string = strdup(yytext);
                          return TK_STRING; 
                        }


\'[^\n]\'               {
                          yylval.integer = (int)(yytext[1]); 
                          return TK_CHAR; 
                        }

[A-Za-z_]([A-Za-z0-9_])*"_t" {
                          yylval.id_string = strdup(yytext);
                          //cout << yylval.id_string << endl;
                          return TK_TYPE_ID;
                        }

[A-Za-z_]([A-Za-z0-9_])* {
                          yylval.id_string = strdup(yytext);
                          //cout << yylval.id_string << endl;
                          return TK_ID;
                        }

.			{ 
                          fprintf(stderr,"line %d: error: illegal character\n", 
                                  line_number); 
                          exit(1);
                        }

