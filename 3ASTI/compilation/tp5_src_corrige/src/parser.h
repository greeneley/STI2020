/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_INT_TYPE = 258,
    TK_CHAR_TYPE = 259,
    TK_VOID_TYPE = 260,
    TK_STRUCT = 261,
    TK_TYPEDEF = 262,
    TK_SIZEOF = 263,
    TK_LPAR = 264,
    TK_RPAR = 265,
    TK_COMMA = 266,
    TK_SEMI = 267,
    TK_LACC = 268,
    TK_RACC = 269,
    TK_TRUE = 270,
    TK_FALSE = 271,
    TK_GREATER = 272,
    TK_GREATER_EQ = 273,
    TK_LOWER = 274,
    TK_LOWER_EQ = 275,
    TK_EQUAL = 276,
    TK_NEQUAL = 277,
    TK_PLUS = 278,
    TK_MINUS = 279,
    TK_MUL = 280,
    TK_DIV = 281,
    TK_MOD = 282,
    TK_PLUSPLUS = 283,
    TK_NUM = 284,
    TK_ID = 285,
    TK_TYPE_ID = 286,
    TK_CHAR = 287,
    TK_STRING = 288,
    TK_LBRAC = 289,
    TK_RBRAC = 290,
    TK_REF = 291,
    TK_DOT = 292,
    TK_ALLOC = 293,
    TK_FREE = 294,
    TK_ASSIGN = 295,
    TK_IF = 296,
    TK_ELSE = 297,
    TK_WHILE = 298,
    TK_FOR = 299,
    TK_RETURN = 300,
    TK_ASM = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "parser.ypp" /* yacc.c:1909  */

  int integer;
  char* id_string;

  Type* type;
  LhsExpr* lhs_expr;
  RhsExpr* rhs_expr;

#line 110 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */