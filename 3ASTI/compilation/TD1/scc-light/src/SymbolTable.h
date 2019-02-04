#ifndef __SYMBOL_H
#define __SYMBOL_H

#include <string>

using namespace std;

void reset_symbol_table();
//Empty the symbol table

void declare_variable(string id);
//Add variable 'id' to the symbol table

int get_address(string id);
//Get the delta assigned to variable 'id'

int get_size();
//Total size of declared variables



#endif
