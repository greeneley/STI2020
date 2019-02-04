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
#ifndef __TYPE_H
#define __TYPE_H

#include <iostream>  //For the pretty-printer
#include <stdlib.h> //for exit()

#include <map>
#include <vector>

using namespace std; 

enum type_t
  { 
    INT,
    CHAR,
    POINTER,
    ARRAY,
    RECORD,

    ID, //Type identifier

    VOID //procedure return type
  };

class Type
{
 public:
  type_t type_id;

  Type* element_type; //array and pointer
  int size;           //array size
  map<string,Type*> record_field; //record

  string id; //type identifier

  /*
   * Constructors
   */

  Type(type_t base_type);
  //Base type
  Type(type_t base_type, Type* element_type); 
  //Pointer
  Type(type_t compound_type, Type* element_type, int size); 
  //Array
  Type(type_t compound_type, map<string,Type*> record_field);
  //Record

  Type(type_t base_type, char* identifier);
  //Identifier

  int is_base();
  //Base type? (INT, CHAR, POINTER)

  int is_well_formed();
  //Check for non-pointed recursion

  int operator==(Type& t);
  //Deep type equivalence

  int size_of();

  Type* un_ref();                 //
  Type* un_index();               // used for type checking
  Type* un_field(char* field_id); //

  int get_field_rank(char* field_id);

  int allocate();
  //Generate the code to allocate and build the variable in the stack
  //Then, return a pointer as a register#.

  Type* clone();

  void print_dot(ostream& sout, string type_name);
  void show_dot(string file_name);

 private:
  int is_well_formed_(int pointer_reached, vector<Type*> path);
  void get_nodes(); //collect the nodes of 'this', used by print_dot
};

//pretty-printer
ostream& operator <<(ostream& sout, Type& e);

//private
string string_of_type_id(type_t type_id);

#endif
