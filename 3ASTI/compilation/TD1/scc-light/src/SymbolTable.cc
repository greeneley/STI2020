#include "SymbolTable.h"

#include <map>
#include <iostream>
#include <stdlib.h>

map<string,int> delta;
int last_delta = -1;

void reset_symbol_table()
{
  delta.erase(delta.begin(),delta.end());
  last_delta = -1;
}

void declare_variable(string id)
{
  if(delta.find(id) != delta.end())
    {
      cerr << "SymbolTable::insert_variable: variable " << id << " already defined" << endl;
      exit(1);
    }
  last_delta++;
  delta[id] = last_delta;
}

int get_address(string id)
{
  if(delta.find(id) == delta.end())
    {
      cerr << "SymbolTable::get_address: variable " << id << " is not declared" << endl;
      exit(1);
    }
  return delta[id];
}

int get_size()
{
  return (last_delta+1)*8;
}
