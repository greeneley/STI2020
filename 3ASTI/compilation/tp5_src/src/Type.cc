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
#include "Type.h"
#include "Label.h"
#include "Register.h"
#include "CodeDigmips.h"

#include <unistd.h> //for system() calls 
#include <fstream> //for show_dot() file I/O

#define PTR_SIZE 1


////////////////////////////////////////////////////////////////
// CONSTRUCTORS
////////////////////////////////////////////////////////////////

Type::Type(type_t base_type)
{
  type_id = base_type;
}


Type::Type(type_t base_type, Type* element_type)
//Pointers
{
  type_id = base_type;
  this->element_type = element_type->clone();
}


Type::Type(type_t compound_type, Type* element_type, int size)
//Arrays
{
  type_id = compound_type;
  this->element_type = element_type->clone();
  this->size = size;
}


Type::Type(type_t compound_type, map<string,Type*> record_field)
//Records
{
  type_id = compound_type;

  for(map<string,Type*>::const_iterator it = record_field.begin(); 
      it != record_field.end(); ++it)
    //For each field...
    this->record_field[(*it).first] = (*it).second->clone(); 
      //...clone and copy
}


Type::Type(type_t base_type, char* identifier)
//Type identifier
{
  string id_str = string(identifier);
  type_id = base_type; 
  id = id_str;
}


int
Type::is_base()
{
  return type_id == INT || type_id == CHAR || type_id == POINTER;
}


////////////////////////////////////////////////////////////////
// WELL-FORMED TYPES
////////////////////////////////////////////////////////////////

extern int line_number;

int
Type::is_well_formed()
{
  vector<Type*> empty_path ( 0 );
  return is_well_formed_(false,empty_path);
}


int belong(Type* t, vector<Type*> v)
{
  for(int i=0; i<v.size(); i++)
    if(v[i] == t)
      return true;
  return false;  
}


int
Type::is_well_formed_(int pointer_reached, vector<Type*> path)
{
  if(belong(this,path))
    //Type already in the root path (cycle)?
    {
      if(!pointer_reached)
	//Recursion an no pointer in the root path => *not* well formed  
	return false;
      else
	return true;
    }
  
  path.push_back(this);

  if(type_id == INT || type_id == CHAR)
    return true;

  if(type_id == POINTER)
    return element_type->is_well_formed_(true,path);

  if(type_id == ARRAY)
    return element_type->is_well_formed_(pointer_reached,path);

  if(type_id == RECORD)
    {
      for(map<string,Type*>::const_iterator it = record_field.begin();
	  it != record_field.end(); ++it)
	//For each record field...
	if(!((*it).second->is_well_formed_(pointer_reached,path)))
	  return false; //not well formed?
      return true; //every field is ok
    }

  if(type_id == ID)
    {
      cerr << "Type::is_well_formed_: ID(" << id << ") found in a type"
	   << endl;
      return false; //not well formed in that case, too 
    }

  if(type_id == VOID)
    {
      cerr << "Line " << line_number << ": error: void is forbidden in "
	   << "type construction" << endl;
      return false; //not well formed in that case, too 
    }

  return false; //unknown type
}


////////////////////////////////////////////////////////////////
// TYPE EQUIVALENCE
////////////////////////////////////////////////////////////////

vector<Type*> node1;
vector<Type*> node2;

int equiv(Type* t1, Type* t2)
//Graph bisimulation...
{
  if(t1 == t2)
    return true; //same pointer, same type...

  if(belong(t1,node1) && belong(t2,node2))
    //cycle completed in both side w/o failure => ok
    return true;

  node1.push_back(t1);
  node2.push_back(t2);

  if(t1->type_id != t2->type_id)
    //Different head type?
    return false;

  if(t1->type_id == POINTER)
    return equiv(t1->element_type,t2->element_type);
    //Same pointed object

  if(t1->type_id == INT || t1->type_id == CHAR)
    return true;

  if(t1->type_id == ARRAY)
    {
      if(t1->size != t2->size)
	return false;
      return equiv(t1->element_type,t2->element_type);
      //Same size and pointed object
    }

  if(t1->type_id == RECORD)
    {
      if(t1->record_field.size() != t2->record_field.size())
	return false;

      map<string,Type*>::const_iterator it1 = t1->record_field.begin();
      map<string,Type*>::const_iterator it2 = t2->record_field.begin();
      while(it1 != t1->record_field.end())
	//For each field for t1 and t2...
	{
	  if(!(equiv(it1->second,it2->second)))
	    return false;
	  it1++; it2++; //next field(s)
	}

      return true;
      //Fields must be equivalent two-by-two
    }

  if(t1->type_id == ID)
    {
      cerr << "Type::equiv_: ID(" << t1->id << ") found in a type"
	   << endl;
      return false; //not equivalent in that case, too 
    }

  return false; //unknown type
}


int Type::operator==(Type& t)
{
  node1.resize(0);
  node2.resize(0);
  return ((is_base() && t.is_base()) || //hack, weak C typing...
	  equiv(this,&t));
}



extern int line_number;

int multiple4(int n)
{
  int mod = n%4;
  if(mod == 0) return n;
  return n + (4-mod);
}

int 
Type::size_of()
{
  //Retourne le multiple de 4 immediatement supérieur à la vraie taille.

  if(is_base()) 
    return multiple4(1+1);

  if(type_id == ARRAY)
    return multiple4(size+1);

  if(type_id == RECORD)
    return multiple4(record_field.size()+1);

  cerr << "Line " << line_number << ": error: sizeof: bad type"
       << endl;
  exit(1);
}


Type* 
Type::un_ref()
{
  if(type_id == POINTER)
    return element_type;
  else
    {
      cerr << "Line " << line_number << ": error: not a pointer"
	   << endl;
      exit(1);
    }
}

Type* 
Type::un_index()
{
  if(type_id == ARRAY || type_id == POINTER)
    return element_type;
  else
    {
      cerr << "Line " << line_number << ": error: not an array"
	   << endl;
      exit(1);
    }
}

Type* 
Type::un_field(char* field_id)
{
  if(type_id == RECORD)
    //Record?
    {
      string field_id_str = string(field_id);
      map<string,Type*>::const_iterator field = record_field.find(field_id_str);
      if(field != record_field.end())
	//Field found?
	return record_field[field_id_str];
      else
	{
	  cerr << "Line " << line_number << ": error: bad field name"  << endl;
	  exit(1);
	}
    }
  cerr << "Line " << line_number << ": error: not a record" << endl;
  exit(1);
}


int 
Type::get_field_rank(char* field_id)
{
  string field_id_str = string(field_id);

  int field_rank = 0;
  for(map<string,Type*>::const_iterator field = record_field.begin(); 
      field != record_field.end(); ++field)
    //For each field...
    {
      if((*field).first == field_id_str)
	//Found?
	return field_rank;
      field_rank++;
    } 

  //Not found?
  cerr << "Line " << line_number << ": field does not exist" << endl;
  exit(1);
}


int
Type::allocate()
{
  if(is_base())
    return 0; //already allocated => init with 0...

  if(type_id == ARRAY)
    {
      /*
       * Allocate the array itself
       */

      int r_array_base = new_register(); 
      mov_reg_sp(r_array_base);
      //Keep array base address (final result)

      int r_size = new_register();
      ldi(r_size,size*PTR_SIZE);
      sub_sp_reg(r_size);
      //Allocate the whole array (of pointers)
      
      /*
       * Allocate each element
       */

      if(element_type->is_base())
	//Base type => already allocated (PTR>max(INT,CHAR))
	return r_array_base;

      //Else: generate a for loop allocating each element one by one.

      int r_element = new_register();

      ldi(r_size,size);

      int r_ptr_size = new_register();
      ldi(r_ptr_size,PTR_SIZE);

      int r_cell_ptr = new_register();
      copy(r_cell_ptr,r_array_base);
      //cell_ptr = &(a[0])

      int r_one = new_register();
      ldi(r_one,1);

      int r_counter = new_register();
      ldi(r_counter,1);
      //counter = 1

      string loop = new_label("loop_array_alloc");
      string next = new_label("next");
      string end_loop = new_label("end_array_alloc");
      label(loop);
      //loop:

        cjump(r_counter,LE,r_size,next);
        //counter<=size => continue
	j(end_loop);
	label(next);

        r_element = element_type->allocate();
        //Allocate the counter^th element...

        st(r_cell_ptr,0,r_element);	  
        //... then assign to array[i]

        sub(r_cell_ptr,r_cell_ptr,r_ptr_size);	  
        //array cell--

        add(r_counter,r_counter,r_one);
        //counter++

	j(loop);
	//goto loop

      label(end_loop);
      //end_loop:

      return r_array_base;
    }

  if(type_id == RECORD)
    //Almost a copy/paste of array allocation
    {
      /*
       * Allocate the record itself
       */

      int r_record_base = new_register();
      mov_reg_sp(r_record_base);
      //Save record base address (final result)

      int nb_fields = record_field.size();
      int r_size = new_register();
      ldi(r_size,nb_fields*PTR_SIZE);
      sub_sp_reg(r_size);
      //Allocate the whole record (with pointers)

      /*
       * Allocate each field
       */

      int r_field = new_register();
      int field_rank=0;
      for(map<string,Type*>::const_iterator it=record_field.begin(); 
	  it != record_field.end(); ++it)
	//For each record field...
	{
	  Type* field_type = (*it).second;

	  if(field_type->is_base())
	    //Base type => already allocated (PTR>max(INT,CHAR))
	    {
	      field_rank++;
	      continue;
	    }

	  r_field = field_type->allocate();
	  //Allocate it...

	  st(r_record_base,-1*field_rank*PTR_SIZE,r_field);	  
	  //... then update the record

	  field_rank++;
	}

      return r_record_base;
    }

  if(type_id == ID)
    {
      //Two possible cases: 
      //1) recursive type not guarded by a pointer => error
      //2) type truly not declared => error

      cerr << "Type::allocate: undeclared type" << endl;
      exit(1);
    }

  cerr << "Type::allocate: undeclared type (void?)" << endl;
  exit(1); //unknown type
}


Type* 
Type::clone()
{
  if(type_id == INT || type_id == CHAR || type_id == VOID)
    return new Type(type_id);
  //Base type

  if(type_id == POINTER)
    return new Type(POINTER,element_type);
  //element_type is cloned in the constructor

  if(type_id == ARRAY)
    return new Type(ARRAY,element_type,size);
  //idem

  if(type_id == RECORD)
    return new Type(RECORD,record_field);

  if(type_id == ID)
    return new Type(ID,(char*)id.c_str());
  //special undeclared type

  if(type_id == VOID)
    return new Type(VOID);

  cerr << "Type::clone: unhandled type" << endl;
  exit(1);
}


vector<Type*> node;        //filled by get_nodes()
map<Type*,int> node_index; //

void 
Type::print_dot(ostream& sout, string type_name)
{
  //Collect the nodes
  node.resize(0);
  node_index.erase(node_index.begin(),node_index.end());
  get_nodes(); //fill 'node' and 'node_index'

  sout << "digraph " << type_name << " {" << endl;

  //Nodes
  for(int i=0; i<node.size(); i++)
    //For each node...
    sout << "  node" << i << "[label=\"" 
	 << string_of_type_id(node[i]->type_id) << "\",shape=box];"
	 << endl; //print attributes

  //Edges
  for(int i=0; i<node.size(); i++)
    //For each node...
    {
      type_t type = node[i]->type_id;
      if(type == POINTER || type == ARRAY)
	sout << "  node" << i << " -> node" << node_index[node[i]->element_type]
	     << "[label=\"element_type\"];" << endl;

      if(type == RECORD)
	for(map<string,Type*>::const_iterator it=node[i]->record_field.begin(); 
	    it != node[i]->record_field.end(); ++it)
	  //For each record field...
	  sout << "  node" << i << " -> node" << node_index[it->second]
	       << "[label=\"" << it->first << "\"];" << endl;
    }

  sout << "}" << endl;
}


void 
Type::show_dot(string file_name)
{
  ofstream output_file;
  string dot_file = file_name;
  dot_file += ".dot";
  output_file.open(dot_file.c_str());

  print_dot(output_file,file_name);
  //Generate the .dot

  output_file.close();

  string ps_file = file_name;
  ps_file += ".ps";
  string dot_command = "dot -Tps ";
  dot_command += dot_file;
  dot_command += " > ";
  dot_command += ps_file;
  system(dot_command.c_str());

  string display_command = "evince ";
  display_command += ps_file;
  display_command += " &";
  system(display_command.c_str());
  //Compile and display
}


void 
Type::get_nodes()
{
  for(int i=0; i<node.size(); i++)
    if(node[i] == this)
      return; //already traversed?

  node.push_back(this); //Add to traversed nodes.
  node_index[this] = node.size()-1;

  if(type_id == POINTER || type_id == ARRAY)
    element_type->get_nodes();

  if(type_id == RECORD)
    {
      for(map<string,Type*>::const_iterator it = record_field.begin(); 
	  it != record_field.end(); ++it)
	//For each record field...
	it->second->get_nodes();
    }
}


//pretty-printer
ostream& operator <<(ostream& sout, Type& t)
{
  if(t.type_id == INT)
    {
      sout << "int";
      return sout;
    }

  if(t.type_id == CHAR)
    {
      sout << "char";
      return sout;
    }

  if(t.type_id == POINTER)
    {
      sout << "(" << *(t.element_type) << ")*";
      return sout;
    }

  if(t.type_id == ARRAY)
    {
      sout << "(" << *(t.element_type) << ")[" << t.size << "]";
      return sout;
    }

  if(t.type_id == RECORD)
    {
      sout << "struct { ";
      for(map<string,Type*>::const_iterator it = t.record_field.begin(); 
	  it != t.record_field.end(); ++it)
	//For each record field...
	sout << *(it->second) << " " << it->first << ", ";
      sout << "}";
      return sout;
    }

  if(t.type_id == ID)
    {
      sout << "ID(" << t.id << ")";
      return sout;
    }

  if(t.type_id == VOID)
    {
      sout << "void";
      return sout;
    }

  cerr << "Type::<<: unhandled type" << endl;
  exit(1);
}

string string_of_type_id(type_t type_id)
{
  if(type_id == INT)
    return "INT";
  if(type_id == CHAR)
    return "CHAR";
  if(type_id == POINTER)
    return "POINTER";
  if(type_id == ARRAY)
    return "ARRAY";
  if(type_id == RECORD)
    return "RECORD";
  if(type_id == ID)
    return "ID";
  if(type_id == VOID)
    return "VOID";
}
