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
#include "Register.h"
#include "Label.h"
#include "SymbolTable.h"

#include "CodeDigmips.h"

#include <vector>
#include <map>

#define PTR_SIZE 1

extern int line_number; //from parser.ypp

/*
 * TYPES
 */

map<string,Type*> type;


//Constructors
void add_type(char* id, Type* t)
{
  string id_str = string(id);
  if(type.find(id_str) != type.end())
    //Already declared as a type?
    {
      cerr << "SymbolTable::add_type: " << id_str 
	   << " already declared as a type" << endl;
      exit(1);
    }

  type[id_str] = t;
}


Type* get_type(char* id)
{
  string id_str = string(id);
  if(type.find(id_str) != type.end())
    return type[id_str];
  else
    {
      cerr << "SymbolTable::get_type: type " << id_str << " is not declared" 
	   << endl;
      return new Type(ID,id); //for recursive types
    }
}


void normalize_type(Type* type)
{
  //Traverse the type...    
  if(type->type_id == INT || type->type_id == CHAR)
    //(true) base type => stop
    return;

  if(type->type_id == POINTER)
    normalize_type(type->element_type);

  if(type->type_id == ARRAY)
    normalize_type(type->element_type);

  if(type->type_id == RECORD)
    for(map<string,Type*>::const_iterator it = type->record_field.begin();
	it != type->record_field.end(); ++it)
      //For each record field...
      normalize_type((*it).second);

  //... until an ID is reached
  if(type->type_id == ID)
    *type = *get_type((char*)type->id.c_str()); //substitute by its value
}

void normalize_types()
{
  Type* t1;
  Type* t2;
  //DEBUG

  //Unroll...
  for(map<string,Type*>::const_iterator it = type.begin(); 
      it != type.end(); ++it)
    //For each type...
    {
      Type* t = (*it).second;
      normalize_type(t); //unroll it

      //if(it->first == "list_t") t1 = t;
      //if(it->first == "list2_t") t2 = t;
      //DEBUG
    }

  //t1->show_dot("list_t"); t2->show_dot("list2_t");
  // if(*t1 == *t2)
  //   cout << "ok" << endl;
  // else
  //   cout << "not ok" << endl;
  //exit(0);
  //DEBUG

  // for(map<string,Type*>::const_iterator it = type.begin(); 
  //     it != type.end(); ++it)
  //   //For each type...
  //   (*it).second->show_dot(it->first);
  //DEBUG

  //... and check for non-pointed recursion
  for(map<string,Type*>::const_iterator it = type.begin(); 
      it != type.end(); ++it)
    //For each type...
    {
      Type* t = (*it).second;
      if(!(t->is_well_formed()))
	//Non pointed recursion?
	{
	  cerr << "SymbolTable::normalize_types: error: type " << (*it).first 
	       << " may have non-pointed recursion" << endl;
	  exit(1); 
	}
    }      
}


/*
 * ARGUMENTS AND LOCAL VARIABLES
 */

vector<string> argument;
vector<string> local_var;

map<string,Type*> argument_type;
map<string,Type*> local_var_type;

map<string,int> argument_reg;
map<string,int> local_var_reg;


void reset_variables()
{
  argument.resize(0);
  local_var.resize(0);
  argument_type.erase(argument_type.begin(),argument_type.end());
  argument_reg.erase(argument_reg.begin(),argument_reg.end());
  local_var_type.erase(local_var_type.begin(),local_var_type.end());
  local_var_reg.erase(local_var_reg.begin(),local_var_reg.end());
}


void add_argument(char* id, Type* type)
{
  string id_str = string(id);
  argument.push_back(id_str);

  if(argument_reg.find(id_str) != argument_reg.end())
    //Already declared as an argument?
    {
      cerr << "SymbolTable::add_argument: " << id_str 
	   << " already declared as an argument" << endl;
      exit(1);
    }

  argument_type[id_str] = type;
  argument_reg[id_str] = new_register();
  //allocate a fresh register
}


void add_local_var(char* id, Type* type)
{
  string id_str = string(id);
  local_var.push_back(id_str);

  if(local_var_reg.find(id_str) != local_var_reg.end())
    //Already declared as a local variable?
    {
      cerr << "SymbolTable::add_local_var: " << id_str 
	   << " already declared as a local variable" << endl;
      exit(1);
    }

  local_var_type[id_str] = type;
  local_var_reg[id_str] = new_register();
  //allocate a fresh register
}


Type* get_variable_type(char* id)
{
  string id_str = string(id);

  //Argument?
  if(argument_type.find(id_str) != argument_type.end())
    return argument_type[id_str];

  //Local variable?
  if(local_var_type.find(id_str) != local_var_type.end())
    return local_var_type[id_str];

  cerr << "SymbolTable::get_variable_type: variable " << id_str 
       << " is not declared" << endl;
  exit(1);
}


//Translation utilities
int get_register(char* id)
{
  string id_str = string(id);

  if((argument_reg.find(id_str) != argument_reg.end()) &&
     (local_var_reg.find(id_str) != local_var_reg.end()))
    //Declared twice (argument and local variable)?
    {
      cerr << "SymbolTable::get_register: " << id_str 
	   << " is declared as argument and local variable" << endl;
      exit(1);
    }

  if(argument_reg.find(id_str) != argument_reg.end())
    //Argument?
    return argument_reg[id_str];

  if(local_var_reg.find(id_str) != local_var_reg.end())
    //Local variable?
    return local_var_reg[id_str];

  //Default: not declared
  cerr << "SymbolTable::get_register: identifier not declared: " << id_str 
       << endl;
  exit(1);
}


/*
 * FUNCTIONS
 */

map<string,vector<Type*> > function_arg_type;
map<string,Type*> function_return_type;

string current_function_id;

void reset_functions()
{
  //Insert arithmetic operators
  vector<Type*> args;
  args.push_back(new Type(INT));
  args.push_back(new Type(INT));

  //+
  function_arg_type["+"] = args;
  function_return_type["+"] = new Type(INT);

  //-
  function_arg_type["-"] = args;
  function_return_type["-"] = new Type(INT);

  //*
  function_arg_type["*"] = args;
  function_return_type["*"] = new Type(INT);
  function_arg_type["__mul"] = args;
  function_return_type["__mul"] = new Type(INT);

  //euclidian /
  function_arg_type["/"] = args;
  function_return_type["/"] = new Type(INT);
  function_arg_type["__div"] = args;
  function_return_type["__div"] = new Type(INT);

  //%
  function_arg_type["%"] = args;
  function_return_type["%"] = new Type(INT);
  function_arg_type["__mod"] = args;
  function_return_type["__mod"] = new Type(INT);

  //
  // Functions defined in the runtime library
  //

  //void __init_heap()
  vector<Type*> args_void;
  function_arg_type["__init_heap"] = args_void;
  function_return_type["__init_heap"] = new Type(VOID);

  //int malloc(int)
  vector<Type*> args_i;
  args_i.push_back(new Type(INT));
  function_arg_type["malloc"] = args_i;
  function_return_type["malloc"] = new Type(INT);

  //void free(int,int)
  function_arg_type["free"] = args;
  function_return_type["free"] = new Type(VOID);

  //char input_char()
  function_arg_type["input_char"] = args_void;
  function_return_type["input_char"] = new Type(CHAR);

  //void print_char(char)
  vector<Type*> args_c;
  args_c.push_back(new Type(CHAR));
  function_arg_type["print_char"] = args_c;
  function_return_type["print_char"] = new Type(VOID);

  //void print_string(char*)
  function_arg_type["print_string"] = args_i;
  function_return_type["print_string"] = new Type(VOID);

  //void print_int(int)
  function_arg_type["print_int"] = args_i;
  function_return_type["print_int"] = new Type(VOID);

  //void print_newline()
  function_arg_type["print_newline"] = args_void;
  function_return_type["print_newline"] = new Type(VOID);
}

void add_function(char* function_id, Type* return_type)
{
  string id_str = string(function_id);
  if(function_return_type.find(id_str) != function_return_type.end())
    //Already declared?
    {
      cerr << "Line " << line_number << ": error: function " << id_str
	   << " already declared" << endl;
      exit(1);
    }

  function_return_type[id_str] = return_type;
  current_function_id = id_str;
}


void add_argument_type(Type* type)
{
  function_arg_type[current_function_id].push_back(type);  
}


Type* return_type(char* function_id)
{
  string id_str = string(function_id);
  if(function_return_type.find(id_str) == function_return_type.end())
    //Not declared?
    {
      cerr << "Line " << line_number << ": error: function " << id_str
	   << " is not declared" << endl;
      exit(1);
    }

  return function_return_type[id_str];
}


void type_check(char* function_id, vector<Type*> arg_type)
{
  string id_str = string(function_id);
  int nb_args = function_arg_type[id_str].size();
  if(arg_type.size() != nb_args)
    //!= number of arguments?
    {
      cerr << "Line " << line_number << ": error: function " 
	   << id_str << " expects " << nb_args << " arguments" << endl;
      exit(1);
    }

  for(int i=0; i<nb_args; i++)
    //For each argument passed...
    {
      if(!(*arg_type[i] == *(function_arg_type[id_str][i])))
	//Not the right type?
	{
	  cerr << "Line " << line_number << ": error: type mismatch for "
	       << "argument " << i+1 << " of function " << id_str << endl;
	  exit(1);
	}
    }
}

//
// Function prelude/postlude code generation
//

void prelude()
{
  //Set ARP
  push_arp();
  mov_arp_sp();

  string label_allocate = new_label("alloc");
  label(label_allocate);

  //Allocate the temporaries
  int temporary_size = new_register();
  ldi(temporary_size,999); //dummy size, fixed after register allocation
  sub_sp_reg(temporary_size);

  //Argument -> register
  int shift = argument.size()*PTR_SIZE + 3*PTR_SIZE; //OLD_ARP, @retour
  for(int i=0; i<argument.size(); i++)
    //For each argument...
    {
      ld_arp(argument_reg[argument[i]],shift);
      //load to the dedicated register

      shift -= PTR_SIZE;
    }

  //Local variable -> register
  for(int i=0; i<local_var.size(); i++)
    //For each local variable...
    {
      char* local_variable = (char*) local_var[i].c_str();
      Type* variable_type = get_variable_type(local_variable);

      if(!(variable_type->is_base()))
	{
	  int var_register = variable_type->allocate();
	  //allocate it on the stack

	  copy(get_register(local_variable),var_register);
	  //assign to dedicated register
	}
    }
}


void postlude()
{
  //Deallocate the local variables and the temporaries
  mov_sp_arp();

  //Restore the ARP of the callee
  pop_arp();

  //Deallocate the arguments and jump back to the callee
  ret(argument.size()*PTR_SIZE);
}


//Pretty-printer
void print_symbols(ostream& sout)
{
  //Types
  sout << "Types" << endl;
  for(map<string,Type*>::const_iterator it = type.begin(); 
      it != type.end(); ++it)
    sout << (*it).first << ": " << *((*it).second) << endl;
  sout << endl;

  //Arguments
  sout << "Arguments" << endl;
  for(int i=0; i<argument.size(); i++)
    sout << argument[i] << " --> r" << argument_reg[argument[i]] << endl;
  sout << endl;

  //Local variables
  sout << "Local variables" << endl;
  for(int i=0; i<local_var.size(); i++)
    sout << local_var[i] << " --> r" << local_var_reg[local_var[i]] << endl;
  sout << endl;
}

