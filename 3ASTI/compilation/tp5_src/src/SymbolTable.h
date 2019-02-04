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
#ifndef __SYMBOL_TABLE_H
#define __SYMBOL_TABLE_H

#include "Type.h"

#include <iostream>  //For the pretty-printer

using namespace std;

/*
 * Types (type_id --> Type*)
 */

void add_type(char* id, Type* t);

Type* get_type(char* id); //from type identifier

void normalize_type(Type* type);
void normalize_types(); //substitute type IDs


/*
 * Variables (variable_id --> (Type*,register))
 */

void reset_variables();
void add_argument(char* id, Type* type);
void add_local_var(char* id, Type* type);

Type* get_variable_type(char* id);
int get_register(char* id);


/*
 * Functions
 */

void reset_functions(); 
//init with built-in functions

void add_function(char* function_id, Type* return_type);

void add_argument_type(Type* type);
//WARNING: types must be normalized!

Type* return_type(char* function_id);

void type_check(char* function_id, vector<Type*> arg_type);

void prelude();
void postlude();
//Function prelude/postlude code generation


/*
 * Pretty-printer
 */

void print_symbols(ostream& sout);

#endif

